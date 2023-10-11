#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	printf(1, "Current Pid: %d\nParent Pid: %d\n", getpid(), get_parent_pid());
    sleep(1500);
	printf(1, "After debugging: \nCurrent Pid: %d\nParent Pid: %d\n", getpid(), get_parent_pid());
    exit();
}
