/***********************************************************
// DYNAMIC MEMORY
// Date: 2018/09/17
// Name: Semin
***********************************************************/


// TODO: include the necessary headers
#include "Kingdom.h"
#include <iostream>
// TODO: the sict namespace
namespace sict {
  // TODO:definition for display(...)
  void display(const Kingdom& kingdom) {
    std::cout << kingdom.m_name << ", population " << kingdom.m_population << std::endl;
  }
  void display(const Kingdom kingdom[], int num) {
    int total = 0;
    std::cout << "------------------------------" << std::endl
              << "Kingdoms of SICT" << std::endl
              << "------------------------------" << std::endl;
    for (int i = 0; i < num; i++) {
      std::cout << i+1 <<". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << std::endl;
      total += kingdom[i].m_population;
    }
    std::cout << "------------------------------" << std::endl
      << "Total population of SICT: " << total << std::endl
      << "------------------------------" << std::endl;
    

  }
}