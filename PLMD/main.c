#include <stdio.h>

char ret[13] = "Hello, World!";

int main(void) {
  extern ret
  printf("%d/n",ret);
  return 0;
}
