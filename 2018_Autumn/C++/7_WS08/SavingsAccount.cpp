// Name: Semin Jeon
// Date: 2018/11/17
// SavingsAccount class derives from the Account class and holds the interest rate that applies to the account

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

namespace sict {
  SavingsAccount::SavingsAccount(double initial, double rate_src)
  : Account(initial) {
    if (rate_src > 0)
      m_rate = rate_src;
    else
      m_rate = 0.0;
  }

  void SavingsAccount::monthEnd() {
    double bal = balance();
    bal *= m_rate;
    credit(bal);
  }

  void SavingsAccount::display(std::ostream & os) const {
    os << "Account type: Savings" << std::endl
      << "Balance: $" << std::fixed << std::setprecision(2) << balance() << std::endl
      << "Interest Rate (%): " << std::fixed << std::setprecision(2) << m_rate*100 << std::endl;
  }
}