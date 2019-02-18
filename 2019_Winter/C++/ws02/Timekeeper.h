// Timekeeper.h
// Name: Semin Jeon
// Date: 2019-01-23

#ifndef _TIME_KEEPER_H_
#define _TIME_KEEPER_H_
#include <chrono>
#include <iostream>

namespace sict {
  const int max = 10;
  class Timekeeper {
    int m_current;
    std::chrono::steady_clock::time_point m_start;
    std::chrono::steady_clock::time_point m_end;
    struct {
      const char* m_message;
      const char* m_unit;
      std::chrono::steady_clock::duration m_duration;
    } record[max];
  public:
    Timekeeper();
    void start();
    void stop();
    void recordEvent(const char* desc_src);
    void report(std::ostream& os);
  };
}
#endif // !_TIME_KEEPER_H_
