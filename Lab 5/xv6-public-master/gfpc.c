#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void){
  printf(1, "Count of free pages is: %d\n", get_free_pages_count());
  exit();
}