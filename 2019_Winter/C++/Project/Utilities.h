// Name: Semin Jeon
// Date: 2019-03-22
// MS02

#ifndef SICT_UTILITIES_H_
#define SICT_UTILITIES_H_

#include <string>

namespace sict {
  class Utilities {
    static char m_del;
    static size_t m_width;
  public:
    Utilities();
    const std::string extractToken(const std::string& str_src, size_t& next_pos);
    const char getDelimiter() const;
    size_t getFieldWidth() const;
    static void setDelimiter(const char del_src);
    static void setFieldWidth(size_t width_src);
  };
}

#endif //SICT_UTILITIES_H_