// Name: Semin Jeon
// Date: 2018/11/17
// The Account class derives from the iAccount interface, holds the current balance 

#include "Account.h"

namespace sict {
  double Account::balance() const {
    return m_balance;
  }

  Account::Account(double initial) {
    if (initial > 0.0)
      m_balance = initial;
    else
      m_balance = 0.0;
  }

  bool Account::credit(double add) {
    bool added;
    if (add > 0.0) {
      m_balance += add;
      added = true;
    }
    else
      added = false;
    return added;
  }

  bool Account::debit(double subtract) {
    bool subtracted;
    if (subtract > 0.0) {
      m_balance -= subtract;
      subtracted = true;
    }
    else
      subtracted = false;
    return subtracted;
  }
}