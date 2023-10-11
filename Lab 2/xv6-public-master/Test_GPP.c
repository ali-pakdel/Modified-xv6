#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	printf(1, "Parent pid is: %d\n", get_parent_pid());	
    exit();
}