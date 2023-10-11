#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
  int pid;
  int n;
  int x;

  if(argc < 2)
	n = 1; 
  else
	n = atoi(argv[1]);
  if (n < 0 ||n > 20)
	  n = 2;
  x = 0;
  pid = 0;

  for ( int i = 0; i < n; i++ ) {
    pid = fork ();
    if (pid > 0) {

      wait();
      }
      else{
        for(int j  = 0; j < 8000000000; j++)
            x = x + 92.48 * 22;
        break;
      }
  }
  exit();
}