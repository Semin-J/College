
/**************************************************
//CLASS
//Date: 2018/09/27
//Name: Semin
**************************************************/
#include <iostream>
#include <cstring>
#include <string>
#include "CRA_Account.h"

using namespace std;

namespace sict {
  char family[max_name_length + 1] = { 0 };
  char given[max_name_length+1] = { 0 };
  int siN=0;
  int return_years[max_yrs];
  double balance_owed[max_yrs];
  int num_years;

  void CRA_Account::set(int year, double balance) {
    if (siN != 0) {
        if (return_years != 0 && num_years < max_yrs){
          return_years[num_years] = year;
          balance_owed[num_years] = balance;
          num_years++;
        }
    }
  }

  bool CRA_Account::sin_check(int sin) {
    // This idea  was inspired by Jason, simplified by myself
    // Cut the SIN every 2digits except 9th
    int SIN, temp, first, second, total = 0, nineth;
    bool valid;
    SIN = sin;
    nineth = SIN % 10;
    SIN /= 10; //Only use first 8 digits for SIN to calculate
    for (int i = 0; i < 4; i++) {
      temp = SIN % 100;
      first = temp / 10;
      second = (temp % 10) * 2;
      total += (first + second / 10 + second % 10);
      SIN /= 100; // get rid of last 1 pair (2digits)
    }
    if (nineth == ((total / 10 + 1) * 10 - total))
      valid = true;
    else
      valid = false;

    return valid;
      /* Submitted code
      //I changed the int SIN to String, and used Index
      bool valid; int int_num, weighted_sum = 0;
      string string_num;
      string string_sin = to_string(sin);
      for(int i = 1; i < 9; i = i + 2) {
        int_num = (string_sin[i]-48) * 2; //char '0' == 48 (in ASCII)
        string_num = to_string(int_num);
        weighted_sum += (string_num[0] - 48);
        if (string_num[1] != 0)
          weighted_sum += (string_num[1] - 48);
      }
      for (int i = 0; i < 8; i = i + 2) {
        int_num = (string_sin[i] - 48);
        weighted_sum += int_num;
      }

      if ((string_sin[8] - 48) == ((weighted_sum / 10) + 1) * 10 - weighted_sum)
        valid = true;
      else
        valid = false;
      return valid;
    }
    */
  }
  void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
    if (sin > min_sin && sin < max_sin && (*familyName != 0) && (*givenName != 0)
        && CRA_Account::sin_check(sin) == true) {
      strncpy(family, familyName, max_name_length);
      family[max_name_length] = '\0';
      strncpy(given, givenName, max_name_length);
      given[max_name_length] = '\0';
      siN = sin;
      num_years = 0;
    }
    else {
      siN = 0;
    }

  }

  bool CRA_Account::isEmpty() const {
    bool empty;
    if (siN != 0) empty = false;
    else empty = true;
    return empty;
  }

  void CRA_Account::display() const {
    if (siN != 0) {
      cout << "Family Name: " << family << endl
        << "Given Name : " << given << endl
        << "CRA Account: " << siN << endl;
      for (int i = 0; i < num_years; i++) {
        cout << "Year (" << return_years[i] << ") ";
        if (balance_owed[i] > 2) {
          cout << fixed;
          cout.precision(2);
          cout << "balance owing: " << balance_owed[i] << endl;
        }
        else if (balance_owed[i] < -2) {
          cout << fixed;
          cout.precision(2);
          cout << "refund due: " << (balance_owed[i])*(-1) << endl;
        }
        else {
          cout << "No balance owing or refund due!" << endl;
        }
      }
    }
    else {
      cout << "Account object is empty!" << endl;
    }
  }
}
