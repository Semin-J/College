// String.cpp
// Semin Jeon
// Date: 2019/01/16

#include "String.h"

extern int INITIAL;

namespace sict {

  String::String(const char* string_src) {
    int size = strlen(string_src);
    if (size > 0) {
      m_string = new char[size + 1];
      strcpy(m_string, string_src);
      m_string[size] = '\0';
    }
    else {
      m_string = nullptr;
    }
  }

  String::~String() {
    delete m_string;
    m_string = nullptr;
  }

  void String::display(std::ostream& os) const {
    os << m_string;
  }

  std::ostream& operator<<(std::ostream& os, const String& str) {
    static int num = INITIAL;
    os << num << ": ";
    str.display(os);
    ++num;
    return os;
  }
}
