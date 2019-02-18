// Timekeeper.cpp
// Name: Semin Jeon
// Date: 2019-01-23
#include "Timekeeper.h"

namespace sict {

  Timekeeper::Timekeeper() : m_current(0) {}

  void Timekeeper::start() {
    m_start = std::chrono::steady_clock::now();
  }

  void Timekeeper::stop() {
    m_end = std::chrono::steady_clock::now();
  }

  void Timekeeper::recordEvent(const char* desc_src) {
    record[m_current].m_message = desc_src;
    record[m_current].m_duration = m_end - m_start;
    record[m_current].m_unit = "nanoseconds";
    ++m_current;
  }

  void Timekeeper::report(std::ostream & os) {
    os << "\nExecution Times:" << std::endl;
    for (int i = 0; i < m_current; i++) {
      os << record[i].m_message << ' '
         << (std::chrono::duration_cast<std::chrono::nanoseconds>(record[i].m_duration)).count()
         << ' ' << record[i].m_unit << std::endl;
    }
  }

}
