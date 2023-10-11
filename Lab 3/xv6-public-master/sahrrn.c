#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int HRRN;

  HRRN = atoi(argv[1]);
  
  set_all_HRRN(HRRN);
  exit();
}