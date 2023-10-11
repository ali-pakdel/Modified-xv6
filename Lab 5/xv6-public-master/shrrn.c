#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int HRRN, pid;

  pid = atoi(argv[1]);
  HRRN = atoi(argv[2]);
  
  set_HRRN(pid, HRRN);
  exit();
}