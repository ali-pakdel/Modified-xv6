#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int priority, pid;

  pid = atoi(argv[1]);
  priority = atoi(argv[2]);
  
  change_queue_lvl(pid, priority);
  exit();
}