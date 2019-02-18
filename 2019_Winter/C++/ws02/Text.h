// Text.h
// Name: Semin Jeon
// Date: 2019-01-26

#ifndef _TEXT_H_
#define _TEXT_H_
#include <string>
#include <fstream>

namespace sict {
  class Text {
    size_t m_current;
    std::string* m_str;

  public:
    Text();
    Text(const char* file_src);
    Text(const Text& text_src);
    Text(Text&& text_src);
    Text& operator=(const Text& text_src);
    Text& operator=(Text&& text_src);
    ~Text();
    size_t size() const;
  };
}
#endif // !_TEXT_H_

