#include "types.h"
#include "stat.h"
#include "user.h"

int my_stoi(char *inp){
	int s = strlen(inp);
	int res = 0, i = 0;
	int curr = 0;
	for (i = 0; i < s; i++){
		if (inp[i] == '1')
			curr = 1;
		if (inp[i] == '2')
			curr = 2;
		if (inp[i] == '3')
			curr = 3;
		if (inp[i] == '4')
			curr = 4;
		if (inp[i] == '5')
			curr = 5;
		if (inp[i] == '6')
			curr = 6;
		if (inp[i] == '7')
			curr = 7;
		if (inp[i] == '8')
			curr = 8;
		if (inp[i] == '9')
			curr = 9;
	    for (int k = 0; k < s-i-1; k++)
		{
		    curr *= 10;
		}
	    res += curr;
	}
	return res;
}

int
main(int argc, char *argv[])
{
    printf(1, "Debugging mode has started with pid %d\n", getpid());
    int pid = my_stoi(argv[1]);
    set_process_parent(pid);
    wait();
	printf(1, "Debugging mode has stopped\n");
    exit();
}
