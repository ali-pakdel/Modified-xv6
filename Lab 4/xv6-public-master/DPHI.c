#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

// void phil(int i)
// {
//     while(1) 
//     {
// 	    printf(1, "%d before picking up forks\n", i);
//         sem_acquire(i);
//         sem_acquire((i + 1) % 5);
    
//         printf(1, "%d picked up forks\n", i);

//         sem_release(i);
//         sem_release((i + 1) % 5);

//         printf(1, "%d putted back forks", i);
//     }
//     exit();
// }

int
main(int argc, char *argv[])
{
    for (int i = 0; i < 5; i++)
    {
        sem_init(i, 1);
    }

    for (int i = 0; i < 5; i++)
    {
        fork();
        char c = i + '0';
        char* cs = &c;
        char* args[] = {cs};
        exec("Test_GPP", args);
    }
    exit();
}