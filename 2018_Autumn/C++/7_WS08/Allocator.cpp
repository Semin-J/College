// Name: Semin Jeon
// Date: 2018/11/17
//  Allocator module pre-defines the accounts rates and charges and defines the global function that creates the Account object from the types of account currently available

#include "SavingsAccount.h"
#include "ChequingAccount.h"
#include <cstring>

namespace sict {
  
  iAccount* CreateAccount(const char* account_type, double initial_balance) {
    const double rate = 0.05;
    const double transaction = 0.5;
    const double monthly = 2.0;

    char* type = new char[strlen(account_type)+1];
    strcpy(type, account_type);
    type[strlen(account_type)] = '\0';
    iAccount* acc;
    if (type[0] == 'S') {
      acc = new SavingsAccount(initial_balance, rate);
    }
    else if (type[0] == 'C') {
      acc = new ChequingAccount(initial_balance, transaction, monthly);
    }
    else acc = nullptr;

    delete[] type;

    return acc;
  }
}