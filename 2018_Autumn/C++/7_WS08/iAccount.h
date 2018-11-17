// Name: Semin Jeon
// Date: 2018/11/17
// iAccount is interface 

#ifndef _I_ACCOUNT_H_
#define _I_ACCOUNT_H_

#include <ostream>
namespace sict {
  class iAccount {
  public:
    virtual bool credit(double) = 0;
    virtual bool debit(double) = 0;
    virtual void monthEnd() = 0;
    virtual void display(std::ostream&) const = 0;
    virtual ~iAccount() {}; //destructor for calling derived class' using base class' pointer
  };
  iAccount* CreateAccount(const char* account_type, double initial_balance);
}
#endif // !_I_ACCOUNT_H_

