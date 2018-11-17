// Name: Semin Jeon
// Date: 2018/11/17
// ChequingAccount class derives from the Account class and holds the transaction fee and month-end fee to be applied to the account. 
#ifndef _CHEQUING_ACCOUNT_H_
#define _CHEQUING_ACCOUNT_H_
#include "Account.h"

namespace sict {
  class ChequingAccount : public Account {
    double m_transaction;
    double m_monthly;
  public:
    ChequingAccount(double initial, double transaction_src, double monthly_src);
    bool credit(double add);
    bool debit(double subtract);
    void monthEnd();
    void display(std::ostream& os) const;
  };
}
#endif // !_CHEQUING_ACCOUNT_H_
