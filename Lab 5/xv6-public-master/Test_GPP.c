#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    int i = atoi(argv[1]);

    while(1) 
    {
	    printf(1, "%d is thinking!\n", i);
        sem_acquire(i);
        sem_acquire((i + 4) % 5);
    
        printf(1, "%d is eating!\n", i);

        sem_release(i);
        sem_release((i + 4) % 5);

        printf(1, "%d has putted down chopsticks!\n", i);
    }
    exit();
}