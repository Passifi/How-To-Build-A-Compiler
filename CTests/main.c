#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv) {
  // just another comment
  uint8_t x;
  int y,z;
  x = 0;
  y = 1;
  double k = (0.2f);
  double g = 0.2;
  do {
    printf("%d \n",x); 
    z = x+ y;
    x = y;
    y = z;
  } while(x < 255);


  return 0;
}
