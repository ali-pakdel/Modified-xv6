#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    for (int i = 0; i < 5; i++)
    {
        sem_init(i, 1);
    }

    for (int i = 0; i < 5; i++)
    {
        int pid = fork();
		if (pid == 0)
		{
			char c = i + '0';
        	char* cs = &c;
        	char* args[] = {"Test_GPP", cs};
        	exec("Test_GPP", args);
		}
    }
    exit();
}