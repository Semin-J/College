// Text.cpp
// Name: Semin Jeon
// Date: 2019-01-26
#include "Text.h"

namespace sict {

  Text::Text() : m_current(0), m_str(nullptr) {}

  Text::Text(const char* file_src) : m_current(0) {
    std::ifstream f(file_src);
    if (f.is_open()) {
      std::string temp;
      while (f.good()) {
        std::getline(f, temp, '\n');
        ++m_current;
      }
      --m_current;
      m_str = new std::string[m_current];
      f.clear();
      f.seekg(std::ios_base::beg);
      for (size_t i = 0; i < m_current; i++) {
        std::getline(f, m_str[i], '\n');
      }
      f.close();
    }
  }

  Text::Text(const Text& text_src) : m_current(0), m_str(nullptr) {
    *this = text_src;
  }

  Text::Text(Text&& text_src) : m_current(0), m_str(nullptr) {
    *this = std::move(text_src);
  }

  Text& Text::operator=(const Text& text_src) {
    if (this != &text_src) {
      delete[] m_str;
      m_current = 0;
      if (text_src.m_current != 0) {
        m_current = text_src.m_current;
        m_str = new std::string[m_current];
        for (size_t i = 0; i < m_current; i++) {
          m_str[i] = text_src.m_str[i];
        }
      }
    }
    return *this;
  }

  Text& Text::operator=(Text&& text_src) {
    if (this != &text_src) {
      std::string* temp;
      
      temp = m_str;
      m_str = text_src.m_str;
      text_src.m_str = temp;
      
      int tmp;
      tmp = m_current;
      m_current = text_src.m_current;
      text_src.m_current = tmp;
    }
    return *this;
  }

  Text::~Text() {
    delete[] m_str;
    m_str = nullptr;
  }

  size_t Text::size() const {
    return m_current;
  }

}
