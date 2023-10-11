#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "syscall.h"

int 
my_stoi(char *inp){
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
    // char* buff = "Fateh Garh Resort	5	Situated in res wide range of facilities to fulfil the v	Udaipur Fateh Garh Resort	5	Situated in res wide range of facilities to fulfil the v	Udaipur Fateh Garh Resort	5	Situated in res wide range of facilities to fulfil the v	Udaipur Fateh Garh Resort	5	Situated in res wide range of facilities to fulfil the v	Udaipur";

    // if (open(argv[2], O_RDONLY) >= 0)
    //     unlink(argv[2]);

    // int num = my_stoi(argv[1]);
    // uint sector_addresses[num];
    // num *= 512;
    
    // int fd = open(argv[2], O_CREATE | O_WRONLY);
    // write(fd, buff, sizeof(buff));
    // close(fd);

	int fd = open("test2.txt", O_RDONLY);
    uint sector_addresses[5];
	get_file_sectors(fd, sector_addresses);
    close(fd);

    for (int i = 0; i < 5; i++)
    {
        printf(1, "Sector %d address: %d\n", i, sector_addresses[i]);
    }
	
    exit();
}