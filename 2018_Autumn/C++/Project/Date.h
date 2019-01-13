// Final Project Milestone 1
// Name: Semin Jeon
// Student No
// Date: 2018/11/01

/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace aid {
  //#define NO_ERROR 0
  #define NO_ERROR 0
  #define CIN_FAILED 1
  #define DAY_ERROR 2
  #define MON_ERROR 3
  #define YEAR_ERROR 4
  #define PAST_ERROR 5

  const int min_year = 2018;
  const int max_year = 2038;
  const int min_date = 751098;

  class Date {
    int m_day, m_month, m_year, all_day, errState;

    void safe_set();
    int mdays(int, int)const;
    void errCode(int);
 
  public:
    Date();
    Date(int, int, int);
    int year();
    int month();
    int day();
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator>=(const Date&) const;
    int errCode() const;
    bool bad() const;
    std::istream& read(std::istream&);
    std::ostream& write(std::ostream&) const;
  };

  std::ostream& operator<<(std::ostream&, const Date&);
  std::istream& operator>>(std::istream&, Date&);


}
#endif