// Name: Semin Jeon
// Date: 2019-03-22
// MS02

#ifndef SICT_CUSTOMERORDER_H_
#define SICT_CUSTOMERORDER_H_

#include "ItemSet.h"

namespace sict {
  // store item name, serial, fillstatus
  struct ItemInfo {
    std::string item_name;
    unsigned int item_serial{ 0u };
    bool fillStatus{ false };
  };

  class CustomerOrder {
    static unsigned int m_nameWidth;
    std::string m_custName;
    std::string m_product;
    int m_num;
    ItemInfo* m_item{nullptr};

  public:
    CustomerOrder(const CustomerOrder&) = delete; // Copy Constructor
    CustomerOrder& operator=(const CustomerOrder&) = delete; // Copy assignment
    CustomerOrder(); // Default constructor
    CustomerOrder(const std::string& str_src); // 1-argument Constructor
    CustomerOrder(CustomerOrder&& order_src); // Move Constructor
    CustomerOrder& operator=(CustomerOrder&& order_src); //Move assignment
    ~CustomerOrder(); // Destructor
    void fillItem(ItemSet& item_src, std::ostream& os);
    bool isFilled() const;
    bool isItemFilled(const std::string& item_src) const;
    std::string getNameProduct() const;
    void display(std::ostream& os, bool showDetail = false) const;
  };
}


#endif //SICT_CUSTOMERORDER_H_