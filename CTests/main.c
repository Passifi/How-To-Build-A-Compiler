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
   if(argc >1) {
    myToLower(argv[1]);
    printf("%s\n",argv[1]);
  if(stringCmp("cat", argv[1])) {
      printf("Meow\n");
  } 
  else if(stringCmp("dog", argv[1]))
      printf("Woof\n");
  } else {
    printf("Please provide a string of proper length in the first argument!\n");
  }
  return 0;
}
