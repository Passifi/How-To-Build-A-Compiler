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
  char* testString = "Technically a const char*";
  int x = 0;
  x += 1;
  //just another comment
  x *= 2;
  return x;
}