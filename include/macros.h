#pragma once 
#include <iostream>
#define DEBUG
#ifdef DEBUG

#define printError(x) std::cout << x << std::endl;
#else
#define printError(x) ;
#endif // DEBUG