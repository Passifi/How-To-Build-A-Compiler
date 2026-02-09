#include <stdio.h> 

void myToLower(char*  s) {
  for(int i= 0; s[i]; ++i) {
      s[i] = s[i] | (0x20 *(s[i] >='A' && s[i] <'Z'+1)); 
   }
} 

int stringCmp(const char* a, char* b) {
  int index = 0;
  while(a[index] && b[index]) {
    if(a[index] != b[index]) {
      return 0;
    }
    index++;
  }
  return 1;
}

int main(int argc, char** argv) {
  
    int x = 0;
    int y = ++x * x++;
    printf("%d\n",y);
  return y;
}
