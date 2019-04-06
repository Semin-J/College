// Name: Semin Jeon
// Date: 2019-03-22
// MS02

#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"
#include "ItemSet.h"
#include "CustomerOrder.h"


namespace sict {
  // Class variable
  unsigned int CustomerOrder::m_nameWidth = 0;

  // Default Constructor
  CustomerOrder::CustomerOrder() : m_custName(""), m_product(""), m_num(0) {}

  // 1-argument Constructor
  CustomerOrder::CustomerOrder(const std::string& str_src) : m_custName(""), m_product(""), m_num(0) {
    try {
      size_t pos = 0;
      std::string tmp = str_src;
      Utilities util;
      m_custName = util.extractToken(tmp, pos);
      if (m_custName.size() > m_nameWidth) { m_nameWidth = m_custName.size(); }
      m_product = util.extractToken(tmp, pos);

      // Checking the number of token(item)
      size_t tmp_pos = pos;
      while (tmp_pos < tmp.size()) { 
        util.extractToken(tmp, tmp_pos);
        ++m_num; 
      }

      if (m_num < 1) { throw std::string("There is no required item"); }
      else {
        m_item = new ItemInfo[m_num];
        int current = 0;
        while (current < m_num) {
          m_item[current].item_name = util.extractToken(tmp, pos);
          ++current;
        }
      }
    }
    catch (std::string err) { std::cout << "Error: " << err << std::endl; }
  }

  // Move Constructor
  CustomerOrder::CustomerOrder(CustomerOrder&& order_src) {
    *this = std::move(order_src);
  }

  // Move assignment
  CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order_src) {
    if (this != &order_src) {
      if (m_num > 0) delete[] m_item;
      m_custName = order_src.m_custName;
      m_product = order_src.m_product;
      m_num = order_src.m_num;
      m_item = order_src.m_item;
      order_src.m_item = nullptr;
      order_src.m_custName = "";
      order_src.m_product = "";
      order_src.m_num = 0;
    }
      return *this;
  }

  // Destructor
  CustomerOrder::~CustomerOrder() {
    delete[] m_item;
  }

  // fill the empty item. Don't touch filled item
  void CustomerOrder::fillItem(ItemSet& item_src, std::ostream& os) {
    for (int i = 0; i < m_num; ++i) {
      if (m_item[i].item_name == item_src.getName()) {
        if (item_src.getQuantity() > 0 && !m_item[i].fillStatus) {
          m_item[i].item_serial = item_src.getSerialNumber();
          m_item[i].fillStatus = true;
          --item_src;
          os << " Filled " << getNameProduct() << "[" << m_item[i].item_name
            << "][" << m_item[i].item_serial << "]" << std::endl;
        }
        else if (item_src.getQuantity() > 0 && m_item[i].fillStatus) {
          os << " Unable to fill " << getNameProduct() << "[" << m_item[i].item_name
            << "][" << m_item[i].item_serial << "]" << " already filled" << std::endl;
        }
        else {
          os << " Unable to fill " << getNameProduct() << "[" << m_item[i].item_name
            << "][" << m_item[i].item_serial << "]" << " out of stock" << std::endl;
        }
      }
    }
  }

  // check all the item is filled or not
  bool CustomerOrder::isFilled() const {
    bool status = true;
    for (int i = 0; i < m_num; ++i) {
      if (!m_item[i].fillStatus) return false;
    }
    return status;
  }

  // check the item is filled or not
  bool CustomerOrder::isItemFilled(const std::string& item_src) const {
    bool status = true;
    for (int i = 0; i < m_num; ++i) {
      if (m_item[i].item_name == item_src) {
        if (!m_item[i].fillStatus) return false;
      }
    }
    return status;
  }

  // get customer and prodcut name in certain format
  std::string CustomerOrder::getNameProduct() const {
    return std::string(m_custName + " [" + m_product + "]");
  }

  // display stored item in certain format
  void CustomerOrder::display(std::ostream& os, bool showDetail) const {
    if (showDetail) {
      os << std::left << std::setw(m_nameWidth + 1) << std::setfill(' ') << m_custName
        << "[" << m_product << "]" << std::endl;
      for (int i = 0; i < m_num; ++i) {
        os << std::left << std::setw(m_nameWidth + 1) << std::setfill(' ') << "" <<
           "[" << m_item[i].item_serial << "] " << m_item[i].item_name <<
          " - " << (m_item[i].fillStatus ? "FILLED" : "MISSING") << std::endl;
      }
    }
    else {
      os << std::left << std::setw(m_nameWidth + 1) << std::setfill(' ') << m_custName
        << "[" << m_product << "]" << std::endl;
      for (int i = 0; i < m_num; ++i) {
        os << std::left << std::setw(m_nameWidth + 1) << std::setfill(' ') << "" <<
           m_item[i].item_name << std::endl;
      }
    }
  }
}
