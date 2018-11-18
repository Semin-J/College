// Name: Semin Jeon
// Date: 2018/11/18
// Good class is a concrete class that encapsulated the general information for an aid Good


#ifndef GOOD_H_
#define GOOD_H_
#include <fstream>
#include <iostream>
#include "Error.h"

namespace aid {
  #define max_sku_length 7
  #define max_unit_length 10
  #define max_name_length 75
  #define TAX 0.13
  class Good {
  private: // Data members
    char m_type;
    char m_sku[max_sku_length + 1];
    char m_unit[max_unit_length + 1];
    char* m_name;
    int m_qty;
    int m_qtyNeeded;
    double m_price;
    bool m_isTaxed;
    Error m_errorState;
    void safeEmpty();
    int call_empty = 0;
    const char* filename;//???

  protected: // Member Functions
    void name(const char* name_src);
    const char* name() const;
    const char* sku() const;
    const char* unit() const;
    bool taxed() const;
    double itemPrice() const;
    double itemCost() const;
    void message(const char* message_src);
    bool isClear() const;

  public: // Constructors, destructor, member operators, member functions
    // Constructors
    Good(char type_src = 'N');
    Good(const char* sku_src, const char* name_src, const char* unit_src, int qty_src = 0,
         bool isTaxed_src = true, double price_src = 0.0, int qtyNeeded_src = 0);
    // Copy constructor
    Good(const Good& good_src);
    // Destructor
    ~Good();

    
    // Member Operators
    // Copy assignment operator
    Good& operator=(const Good& good_src);
    bool operator==(const char* sku_src);
    bool operator>(const char* sku_src);
    bool operator>(const Good& good_src);
    int operator+=(int add_qty);

    // Member Functions
    std::fstream& store(std::fstream& file, bool newLine = true) const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear) const;
    std::istream& read(std::istream& is);
    double total_cost() const;
    void quantity(int qty_src);
    bool isEmpty() const;
    int qtyNeeded() const;
    int quantity() const;
  };
  // Helper Functions
  std::ostream& operator<<(std::ostream& os, const Good& good_src);
  std::istream& operator>>(std::istream& is, Good& good_src);
  double operator+=(double& add_price, const Good& good_src);
}
#endif // !GOOD_H_