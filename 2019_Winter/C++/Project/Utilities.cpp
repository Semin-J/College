// Name: Semin Jeon
// Date: 2019-03-22
// MS02

#include <iostream>
#include <string>
#include "Utilities.h"
#include "ItemSet.h"

namespace sict {
  // initialize class variable
  char Utilities::m_del = '\0';

  // initialize class variable
  size_t Utilities::m_width = 0;

  // default constructor
  Utilities::Utilities() {}

  // extract tokens using outside source
  const std::string Utilities::extractToken(const std::string& str_src, size_t& next_pos) {
    std::string tmp;
    if (str_src.size() > next_pos) {
      tmp = str_src.substr(next_pos, str_src.find(m_del, next_pos) - next_pos);
    }
    else tmp = "";

    if (str_src.find(m_del, next_pos) != std::string::npos) {
      next_pos = str_src.find(m_del, next_pos) + 1;
    }
    else {
      next_pos = std::string::npos;
    }
    if (tmp.size() == 0) { throw "The token is empty"; }
    return tmp;

  }

  // return delimiter
  const char Utilities::getDelimiter() const {
    return m_del;
  }

  // return field width
  size_t Utilities::getFieldWidth() const {
    return m_width;
  }

  // set delimiter using source outside
  void Utilities::setDelimiter(const char del_src) {
    m_del = del_src;
  }

  // set field width using source outside
  void Utilities::setFieldWidth(size_t width_src) {
    m_width = width_src;
  }
}