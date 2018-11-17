// Name: Semin Jeon
// Date: 2018/11/17
// ChequingAccount class derives from the Account class and holds the transaction fee and month-end fee to be applied to the account. 

#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"

namespace sict {
  ChequingAccount::ChequingAccount(double initial, double transaction_src, double monthly_src)
  : Account(initial) {
    if (transaction_src > 0.0) m_transaction = transaction_src;
    else m_transaction = 0.0;
    if (monthly_src > 0.0) m_monthly = monthly_src;
    else m_monthly = 0.0;
  }

  bool ChequingAccount::credit(double add) {
    bool added;
    if (add > 0) {
      Account::credit(add - m_transaction);
      added = true;
    }
    else added = false;

    return added;
  }

  bool ChequingAccount::debit(double subtract) {
    bool subtracted;
    if (subtract > 0) {
      Account::debit(subtract + m_transaction);
      subtracted = true;
    }
    else subtracted = false;
    return subtracted;
  }

  void ChequingAccount::monthEnd() {
    Account::debit(m_monthly);
  }

  void ChequingAccount::display(std::ostream & os) const {
    os << "Account type: Chequing" << std::endl
      << "Balance: $" << std::fixed << std::setprecision(2) << balance() << std::endl
      << "Per Transaction Fee: " << std::fixed << std::setprecision(2) << m_transaction << std::endl
      << "Monthly Fee: " << std::fixed << std::setprecision(2) << m_monthly << std::endl;
  }

}


