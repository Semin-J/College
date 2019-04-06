// Name: Semin Jeon
// Date: 2019-04-05
// MS03

#include <iostream>
#include <string>
#include "LineManager.h"

namespace sict {
  // Constructor
  // It determines the last station in LineManeger object
  LineManager::LineManager(std::vector<Station*>& stn_src, std::vector<size_t>& index_src,
                           std::vector<CustomerOrder>& order_src, size_t start_point, std::ostream & os) : firstStn(0), lastStn(0) {

    // Copies the address of the stn_src to m_stn(data member)
    m_stn.resize(stn_src.size());
    m_stn = stn_src;

    // Moving the orders to the waiting deque
    for (size_t i = 0; i < order_src.size(); ++i) {
      waiting.push_back(std::move(order_src.at(i)));
    }

    // Set the first station index with start_point
    firstStn = start_point;

    // Change the vector that holds the next station order(data member)
    // and Copy the index order to data member
    nextStn.resize(index_src.size());
    nextStn = index_src;

    // Last station index's values becomes a next station index
    lastStn = firstStn;
    while (nextStn.at(lastStn) != m_stn.size()) {
      lastStn = nextStn.at(lastStn);
    }
  }

  // Display all the orders, both complete and incomplete
  void LineManager::display(std::ostream& os) const {
    os << "COMPLETED ORDERS" << std::endl;
    for (auto& i : completed) { i.display(os, true); }
    os << std::endl;
    os << "INCOMPLETE ORDERS" << std::endl;
    for (auto& i : incompleted) { i.display(os, true); }
  }

  // LineManager fills up the orders in the queue, moves the orders to the next stations
  // regardless the order is filled or not
  // Check all the orders are processed or not, and then return the boolean value
  bool LineManager::run(std::ostream& os) {
    bool allDone = false;
    size_t orderNum = waiting.size();
    std::string prev, next, prodName;

    // Run until the waiting deque is empty
    while (!waiting.empty() || orderNum) {
      if (!waiting.empty()) {
        *(m_stn.at(firstStn)) += std::move(waiting.front()); // .at(i) is safe than [i]
        waiting.pop_front();
      }
      // Fill each station's orders
      for (size_t i = 0; i < m_stn.size(); ++i) {
        m_stn.at(i)->fill(os);
      }

      // The order at last station pop out to complete, incomplete queue
      // The order in the middle in line, move to next station
      size_t index = firstStn;
      CustomerOrder tmp;
      for (size_t i = 0; i < m_stn.size(); ++i) {
        if (m_stn.at(i)->hasAnOrderToRelease()) {
          m_stn.at(i)->pop(tmp);
          if (i != lastStn) {
            prev = m_stn.at(i)->getName();
            index = nextStn.at(i);
            if (index != m_stn.size()) {
              next = m_stn.at(index)->getName();
              prodName = tmp.getNameProduct();
              *(m_stn.at(index)) += std::move(tmp);
              os << " --> " << prodName << " moved from " << prev << " to " << next << std::endl;
            }
          }
          else {
            prodName = tmp.getNameProduct();
            prev = m_stn.at(i)->getName();
            os << " --> " << prodName << " moved from " << prev << " to ";
            if (tmp.isFilled()) {
              os << "Complete Set" << std::endl;
              completed.push_back(std::move(tmp));
            }
            else {
              os << "Incomplete Set" << std::endl;
              incompleted.push_back(std::move(tmp));
            }
            --orderNum;
          }
        }
      }
    }
    // Checking all the processes are done
    if (!orderNum) {
      allDone = true;
    }
    return allDone;
  }
}