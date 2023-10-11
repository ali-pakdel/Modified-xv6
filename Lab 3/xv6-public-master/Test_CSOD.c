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
    int num = my_stoi(argv[1]);

    int sum = calculate_sum_of_digits(num);

	printf(1, "Sum of digits is: %d\n", sum);
	
    exit();
}