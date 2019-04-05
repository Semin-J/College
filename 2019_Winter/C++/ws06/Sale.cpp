// Name: Semin Jeon
// Date: 2019-03-05
// WS06: STL containers

#include <string>
#include <fstream>
#include <iomanip>
#include "Sale.h"


extern int FW;
namespace sict {
  // 1-arg constructor
  Sale::Sale(const char* name) {
    std::ifstream file(name);
    int lines = 0;

    // Checking the number of lines
    if (file.is_open()) {
      std::string temp;
      while (file.good()) {
        std::getline(file, temp, '\n');
        ++lines;
      }
      --lines;
      file.clear(); // Reset flag
      file.seekg(std::ios::beg); // Set input position-beginning of stream
      for (int i = 0; i < lines; ++i) {
        m_record.push_back(readRecord(file));
      }
      file.close();
    }
  }

  void Sale::display(std::ostream& os) const {
    double total = 0.0;
    os << "\nProduct No" << std::setw(FW) << "Cost" << " Taxable"<< std::endl;
    for (auto& i : m_record) { 
      os << *i;
      os << std::fixed << std::setprecision(2);
     // i->display(os);
      total += i->price();
      os << std::endl;
    }
    os << std::setw(FW) << "Total" << std::setw(FW) << std::fixed << std::setprecision(2) << total << std::endl;
  }

 

  std::ostream& operator<<(std::ostream& os, const iProduct& p_src) {
    p_src.display(os);
    return os;
  }

}