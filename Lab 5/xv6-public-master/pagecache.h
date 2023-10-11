#define NPAGECACHE 30

struct cached_page {
  int dev;
  int inode_number;
  int refCount;
  int offset;
  char *page;
  struct sleeplock lock;
};