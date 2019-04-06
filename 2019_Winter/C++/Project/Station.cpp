// Name: Semin Jeon
// Date: 2019-04-05
// MS03

#include <iostream>
#include <string>
#include "Station.h"

namespace sict {
  // One argument constructor
  Station::Station(const std::string& item_src) : m_itemSet(item_src) {
    m_name = m_itemSet.getName();
  }

  // Display the itemset's information
  void Station::display(std::ostream& os) const {
    m_itemSet.display(os);
  }

  // If there is an order to fill, fill the order
  void Station::fill(std::ostream& os) {
    if (!m_orders.empty()) {
      m_orders.front().fillItem(m_itemSet, os);
    }
  }

  // Get the name of the item
  const std::string& Station::getName() const {
    return m_itemSet.getName();
  }

  // Check the front of the queue of order is ready to release or not
  bool Station::hasAnOrderToRelease() const {
    bool release = false;
    if (!m_orders.empty()) {
      if (!m_itemSet.getQuantity()) release = true;
      else release = m_orders.front().isItemFilled(m_name);
    }
    return release;
  }

  // --Prefix operator, decrease the qty of the item, and increase the serial no of the item
  Station & Station::operator--() {
    --m_itemSet;
    return *this;
  }

  // += operator
  Station& Station::operator+=(CustomerOrder&& order_src) {
    m_orders.push_back(std::move(order_src));
    return *this;
  }

  // If the item is fully filled, pop out from the queue
  bool Station::pop(CustomerOrder& ready) {
    bool filled = false;
    if (!m_orders.empty()) {
      filled = m_orders.front().isItemFilled(m_name);
      ready = std::move(m_orders.front());
      m_orders.pop_front();
    }
    return filled;
  }

  // Reports the state of the ItemSet object in certain format
  void Station::validate(std::ostream& os) const {
    os << " getName(): " << m_itemSet.getName() << std::endl
      << " getSerialNumber(): " << m_itemSet.getSerialNumber() << std::endl
      << " getQuantity(): " << m_itemSet.getQuantity() << std::endl;
  }
}