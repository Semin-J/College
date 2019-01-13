// Final Project Milestone 1
// Name: Semin Jeon
// Student No
// Date: 2018/11/01
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Date.h"


namespace aid {

	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)));
	}

  void Date::errCode(int errorCode) {
    errState = errorCode;
  }
  void Date::safe_set() {
    m_year = 0;
    m_month = 0;
    m_day = 0;
    all_day = 0;
  }
  Date::Date() {
    safe_set();
    errState = NO_ERROR;
  }

  Date::Date(int year, int month, int day) {
    
    if (year >= min_year && year <= max_year) {
      m_year = year;
      if (month >= 1 && month <= 12) {
        m_month = month;
        if (day <= mdays(m_month, m_year) && day >= 1) {
          m_day = day;
          all_day = m_year * 372 + m_month * 31 + m_day;
          if (all_day >= min_date)
            errState = NO_ERROR;
          else errState = PAST_ERROR;          
        }
        else errState = DAY_ERROR;
      }
      else errState = MON_ERROR;
    } 
    else errState = YEAR_ERROR;

    if (errState != NO_ERROR)
      this->safe_set();
  }

  int Date::year() {
    return m_year;
  }

  int Date::month() {
    return m_month;
  }

  int Date::day() {
    return m_day;
  }

  bool Date::operator==(const Date& rhs) const {
    bool correct;
    if (m_year != 0 && rhs.m_year != 0) {
      if (all_day == rhs.all_day)
        correct = true;
      else correct = false;
    }
    else correct = false;

    return correct;
  }

  bool Date::operator!=(const Date& rhs) const {
    bool correct;
    if (m_year != 0 && rhs.m_year != 0) {
      if (all_day != rhs.all_day)
        correct = true;
      else correct = false;
    }
    else correct = false;

    return correct;
  }

  bool Date::operator<(const Date& rhs) const {
    bool correct;
    if (m_year != 0 && rhs.m_year != 0) {
      if (all_day < rhs.all_day)
        correct = true;
      else correct = false;
    }
    else correct = false;

    return correct;
  }

  bool Date::operator>(const Date& rhs) const {
    bool correct;
    if (m_year != 0 && rhs.m_year != 0) {
      if (all_day > rhs.all_day)
        correct = true;
      else correct = false;
    }
    else correct = false;

    return correct;
  }

  bool Date::operator<=(const Date& rhs) const {
    bool correct;
    if (m_year != 0 && rhs.m_year != 0) {
      if (all_day <= rhs.all_day)
        correct = true;
      else correct = false;
    }
    else correct = false;

    return correct;
  }

  bool Date::operator>=(const Date& rhs) const {
    bool correct;
    if (m_year != 0 && rhs.m_year != 0) {
      if (all_day >= rhs.all_day)
        correct = true;
      else correct = false;
    }
    else correct = false;

    return correct;
  }
  int Date::errCode() const {
    return errState;
  }

  bool Date::bad() const {
    return errState != NO_ERROR;
  }

  std::istream& Date::read(std::istream& istr) {
    int t_year = 0;
    int t_month = 0;
    int t_day=0;
    char bin;
    istr >> t_year >> bin >> t_month >> bin >> t_day;

    if (istr.fail() == false)
      *this = Date(t_year, t_month, t_day);
      
    else {
      safe_set();
      errState = CIN_FAILED;
    }
    return istr;
  }

  std::ostream& Date::write(std::ostream& ostr) const {
    ostr << m_year << "/";
    ostr.fill('0');
    ostr.width(2);
    ostr << m_month << "/";
    ostr.fill('0');
    ostr.width(2);
    ostr << m_day;
    ostr.fill(' ');
    return ostr;
  }

  std::ostream& operator<<(std::ostream& ostr, const Date& d) {
    d.write(ostr);
    return ostr;
  }

  std::istream& operator>>(std::istream& istr, Date& d) {
    d.read(istr);
    return istr;
  }

}
