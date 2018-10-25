/**************************************************
//CLASS
//Date: 2018/09/27
//Name: Semin
**************************************************/
#ifndef CRA_ACCOUNT_H_
#define CRA_ACCOUNT_H_


namespace sict {

  const int max_name_length = 40;
  const int min_sin = 100000000;
  const int max_sin = 999999999;
  const int max_yrs = 4;

  class CRA_Account{
    char family[max_name_length + 1] = { 0 };
    char given[max_name_length + 1] = { 0 };
    int siN;
    int return_years[max_yrs];
    double balance_owed[max_yrs];
    int num_years;
  public:
    void set(int year, double balance);
    bool sin_check(int sin);
    void set(const char* familyName, const char* givenName, int sin);
    bool isEmpty() const;
    void display() const;
    

  };
}

#endif // CRA_ACCOUNT_H_

