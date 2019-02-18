// w1.cpp
// Semin Jeon
// Date: 2019/01/16

#include <iostream>
#include "process.h"

int INITIAL;

int main(int argc, const char* argv[]) {
  INITIAL = argc;
  std::cout << "Command Line : ";
  for (int i = 0; i < INITIAL; i++) {
    std::cout << argv[i] << " ";
  }
  std::cout << std::endl;

  if (argc < 2) {
    std::cout << "***Insufficient number of arguments***" << std::endl;
    return 1;
  }
  else {
    for (int i = 1; i < argc; i++) {
      sict::process(argv[i]);
    }
    return 0;
  }
  
}
