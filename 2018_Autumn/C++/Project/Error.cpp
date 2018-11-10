// Name: Semin Jeon
// Date: 2018/11/08
// Error class manages the error state of client code and encapsulates the last error message

#include <iostream>
#include <cstring>
#include "Error.h"

namespace aid {

  //To set data member, using dynamic allocation
  void Error::setter(const char* error_src) {
    if (error_src != nullptr && error_src[0] != '\0') { // "" == [0]='\0' in memory
      int size = strlen(error_src);
      m_error = new char[size + 1];
      strncpy(m_error, error_src, size);
      m_error[size] = '\0';
    }
    else safeEmpty();
  }

  Error::Error(const char * error_src) { //=nullptr
    setter(error_src);
  }

  Error::~Error() {
    delete[] m_error;
  }

  // To set the data member in safe empty state
  void Error::safeEmpty() {
    m_error = nullptr;
  }

  void Error::clear() {
    delete[] m_error;
    safeEmpty();
  }

  bool Error::isClear() const {
    bool clear;
    if (m_error == '\0')
      clear = true;
    else
      clear = false;
    return clear;
  }

  void Error::message(const char* str) {
    delete[] m_error;
    setter(str);
  }

  const char * Error::message() const {
    return m_error;
  }

  std::ostream& operator<<(std::ostream & os,const Error & rhs) {
    if (rhs.message() != nullptr && rhs.message()[0] != '\0') {
      os << rhs.message();
    }
    return os;
  }
}