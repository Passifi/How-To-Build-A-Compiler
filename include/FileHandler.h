#pragma once 
#include "macros.h"
#include <fstream> 
#include <iostream>

class FileHandler {
public:
  FileHandler();

  static std::string getTextfileData(std::string path);  
};