// Name: Semin Jeon
// Date: 2019-04-05
// MS02

#ifndef SICT_ITEMSET_H_
#define SICT_ITEMSET_H_

#include "Utilities.h"

namespace sict {
  class ItemSet {
    std::string m_name;
    unsigned int m_serial;
    unsigned int m_qty;
    std::string m_desc;
    Utilities m_util;
  public:
    ItemSet(const ItemSet&) = delete; // Copy Constructor
    ItemSet& operator=(const ItemSet&) = delete; // Copy Assignment
    ItemSet& operator=(ItemSet&&) = delete; //Move Assignment
    ItemSet();
    ItemSet(const std::string& str_src);
    ItemSet(ItemSet&& item_src);
    const std::string& getName() const;
    const unsigned int getSerialNumber() const;
    const unsigned int getQuantity() const;
    ItemSet& operator--();
    void display(std::ostream& os, bool full = true) const;
  };
}

#endif //SICT_ITEMSET_H_