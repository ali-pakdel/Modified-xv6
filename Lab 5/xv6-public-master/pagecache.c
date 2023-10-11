#include "types.h"
#include "defs.h"
#include "mmu.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "pagecache.h"

struct {
  struct cached_page pages[NPAGECACHE];
  int totalCount;
  struct spinlock lock;
} pagecache;

void pagecacheinit(void) {
  initlock(&pagecache.lock, "pagecache");
  for (int i = 0; i < NPAGECACHE; i++) {
    pagecache.pages[i].page = kalloc();
    if (!pagecache.pages[i].page) {
      cprintf("pagecacheinit: Kalloc failed");
      return;
    }
    initsleeplock(&pagecache.pages[i].lock, "pagecache page");
    memset(pagecache.pages[i].page, 0, PGSIZE);
  }
  pagecache.totalCount = 0;
  cprintf("Initialized the page cache\n");
}

static struct cached_page *findPage(uint inum, int offset, int dev) {
  if (!holding(&pagecache.lock))
    panic("Pagecache: find page");
  for (int i = 0; i < NPAGECACHE; i++) {
    if (pagecache.pages[i].inode_number == inum &&
        pagecache.pages[i].offset == offset && pagecache.pages[i].dev == dev) {
      return &pagecache.pages[i];
    }
  }
  return 0;
}

void updatePage(int offset, int inum, int dev, char *addr, int size) {

   acquire(&pagecache.lock);
  int alligned_offset = offset - offset % PGSIZE;
  int start_addr = offset % PGSIZE;
  struct cached_page *res = findPage(inum, alligned_offset, dev);
  release(&pagecache.lock);
  if (!res) {
    return;
  }
  acquiresleep(&res->lock);
  char *page = res->page;
  memmove(page + start_addr, addr, size);
  releasesleep(&res->lock);
  return;
}

struct cached_page *getPage(struct inode *ip, int offset, int inum, int dev) {
  offset -= offset % PGSIZE;
  acquire(&pagecache.lock);
  struct cached_page *res = findPage(inum, offset, dev);
  if (res) {
    acquiresleep(&res->lock);
    release(&pagecache.lock);
    return res;
  }
  struct cached_page *allocpagecache = &pagecache.pages[pagecache.totalCount++];
  release(&pagecache.lock);
  acquiresleep(&allocpagecache->lock);
  if (pagecache.totalCount == NPAGECACHE) {
    pagecache.totalCount = 0;
  }
  memset(allocpagecache->page, 0, PGSIZE);
  int n = readi(ip, allocpagecache->page, offset, PGSIZE);
  if (n == -1) {
    return (struct cached_page *)-1;
  }
  allocpagecache->dev = dev;
  allocpagecache->inode_number = inum;
  allocpagecache->offset = offset;
  return allocpagecache;
}

int copyPage(struct inode *ip, int offset, int inum, int dev, char *dest,
             int size, int dest_offset) {
  struct cached_page *page = getPage(ip, offset, inum, dev);

  if (page == (struct cached_page *)-1) {
    return 0;
  }
  if (!holdingsleep(&page->lock))
    panic("pagecache copy page");

  memmove(dest, page->page + dest_offset, size);

  releasesleep(&page->lock);
  return 0;
}