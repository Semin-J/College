// String.h
// Semin Jeon
// Date: 2019/01/16

#ifndef SICT_STRING_H_
#define SICT_STRING_H_

#include <iostream>
#include <cstring>

namespace sict {
  class String {
    char* m_string;
  public:
    String(const char* string_src);
    ~String();
    void display(std::ostream& os) const;
  };

  std::ostream& operator<<(std::ostream& os, const String& str);
}
#endif // !SICT_STRING_H_
