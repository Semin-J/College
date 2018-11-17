// Name: Semin Jeon
// Date: 2018/11/17
// SavingsAccount class derives from the Account class and holds the interest rate that applies to the account

#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

namespace sict {
  class SavingsAccount : public Account {
    double m_rate;
  public:
    SavingsAccount(double initial, double rate_src);
    void monthEnd();
    void display(std::ostream& os) const;
  };
}
#endif // !_SAVINGS_ACCOUNT_H_

