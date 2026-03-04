#include <stdio.h>
#include <stdlib.h>
typedef char *T;
int t = 0;
int main(void) {
  int x = 0;
  if (1) {
    int x = 2;
    printf("%d \n", x);
    x++;
    x++;
    if (1) {
      int x = 3;

      printf("%d \n", x);
      x++;
    }
  }
  printf("%d \n", x);
}
