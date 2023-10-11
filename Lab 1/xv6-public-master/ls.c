#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"


int stoi(char *inp);

char*
fmtname(char *path)
{
  static char buf[DIRSIZ+1];
  char *p;

  // Find first character after last slash.
  for(p=path+strlen(path); p >= path && *p != '/'; p--)
    ;
  p++;

  // Return blank-padded name.
  if(strlen(p) >= DIRSIZ)
    return p;
  memmove(buf, p, strlen(p));
  memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));
  return buf;
}

void
ls(char *path)
{
  char buf[512], *p;
  struct dirent de;
  int fd;
  struct stat st;

  if((fd = open(path, 0)) < 0){
    printf(2, "ls: cannot open %s\n", path);
    return;
  }

  if(fstat(fd, &st) < 0){
    printf(2, "ls: cannot stat %s\n", path);
    close(fd);
    return;
  }

  switch(st.type){
  case T_FILE:
    printf(1, "%s %d %d %d\n", fmtname(path), st.type, st.ino, st.size);
    break;

  case T_DIR:
    if(strlen(path) + 1 + DIRSIZ + 1 > sizeof buf){
      printf(1, "ls: path too long\n");
      break;
    }
    strcpy(buf, path);
    p = buf+strlen(buf);
    *p++ = '/';
    while(read(fd, &de, sizeof(de)) == sizeof(de)){
      if(de.inum == 0)
        continue;
      memmove(p, de.name, DIRSIZ);
      p[DIRSIZ] = 0;
      if(stat(buf, &st) < 0){
        printf(1, "ls: cannot stat %s\n", buf);
        continue;
      }
      printf(1, "%s %d %d %d\n", fmtname(buf), st.type, st.ino, st.size);
    }
    break;
  }
  close(fd);
}

void factor(char *inp){

	int num = stoi(inp);
	int i = 0;
  int fd;

	if((fd = open("a.text", 0)) < 0){
    printf(2, "ls: cannot open %s\n", "a.text");
    return;
  }
	for (i = 1; i <= num; i++){
		if (num % i == 0);

  }
}

int stoi(char *inp){
	int s = sizeof(inp);
	int res = 0, i = 0;
	for (i = 0; i < s; i++){
		if (inp[i] == '1')
			res += 1 * (s-i-1) * 10;
		if (inp[i] == '2')
			res += 2 * (s-i-1) * 10;
		if (inp[i] == '3')
			res += 3 * (s-i-1) * 10;
		if (inp[i] == '4')
			res += 4 * (s-i-1) * 10;
		if (inp[i] == '5')
			res += 5 * (s-i-1) * 10;
		if (inp[i] == '6')
			res += 6 * (s-i-1) * 10;
		if (inp[i] == '7')
			res += 7 * (s-i-1) * 10;
		if (inp[i] == '8')
			res += 8 * (s-i-1) * 10;
		if (inp[i] == '9')
			res += 9 * (s-i-1) * 10;		
	}
	return res;
}

int
main(int argc, char *argv[])
{

  if(argc < 2){
    ls(".");
    exit();
  }
  int i = stoi("28");

  /*if(argv[0] == "factor"){
  	factor(argv[1]);*/
  
  for(i=1; i<argc; i++)
    ls(argv[i]);
  exit();
}
