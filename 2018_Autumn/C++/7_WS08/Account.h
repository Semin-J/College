// Name: Semin Jeon
// Date: 2018/11/17
// The Account class derives from the iAccount interface, holds the current balance 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "iAccount.h"
namespace sict {
  class Account : public iAccount{
  private:
    double m_balance;
  protected:
    double balance() const;
  public:
    Account(double initial = 0.0);
    bool credit(double add);
    bool debit(double subtract);
  };
}
#endif // !_ACCOUNT_H_

