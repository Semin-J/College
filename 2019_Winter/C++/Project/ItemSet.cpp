// Name: Semin Jeon
// Date: 2019-04-05
// MS02

#include <iostream>
#include <iomanip>
#include <string>
#include "Utilities.h"
#include "ItemSet.h"


namespace sict {
  // Default constructor
  ItemSet::ItemSet() : m_name(""), m_serial(0), m_qty(0), m_desc("") {}

  // 1-argument constructor
  ItemSet::ItemSet(const std::string& str_src) : m_name(""), m_serial(0), m_qty(0), m_desc("") {
    std::string tmp = str_src;
    size_t pos = 0;
    try {
      m_name = m_util.extractToken(tmp, pos);
      if (m_name.size() > m_util.getFieldWidth()) { m_util.setFieldWidth(m_name.size()); }
      m_serial = stoul(m_util.extractToken(tmp, pos));
      m_qty = stoul(m_util.extractToken(tmp, pos));
      m_desc = tmp.substr(pos);
    }
    catch (std::string err) {
      std::cout << err << std::endl;
    }
  }

  // Move constructor
  ItemSet::ItemSet(ItemSet&& item_src) {
    if (this != &item_src) {
      m_name = item_src.m_name;
      m_serial = item_src.m_serial;
      m_qty = item_src.m_qty;
      m_desc = item_src.m_desc;
    }
  }
  // getting name of the item
  const std::string& ItemSet::getName() const {
    return m_name;
  }

  // getting serial number of the item
  const unsigned int ItemSet::getSerialNumber() const {
    return m_serial;
  }

  // getting quatity of the item
  const unsigned int ItemSet::getQuantity() const {
    return m_qty;
  }

  // prefix --
  ItemSet& ItemSet::operator--() {
    ++m_serial;
    --m_qty;
    return *this;
  }

  // display the iteminfo in certain way
  void ItemSet::display(std::ostream& os, bool full) const {
    int fw = m_util.getFieldWidth();
    os << std::left << std::setw(fw) << std::setfill(' ') << m_name << " [";
    os << std::setw(5) << std::setfill('0') << m_serial << "]";
    if (full) {
      os << " Quantity " << std::left << std::setw(3) << std::setfill(' ') << m_qty << " Description: " << m_desc << std::endl;
    }
    else { os << std::endl; }
  }

}