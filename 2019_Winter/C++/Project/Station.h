// Name: Semin Jeon
// Date: 2019-04-05
// MS03

#ifndef SICT_STATION_H_
#define SICT_STATION_H_

#include <deque>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {
  class Station {
    std::deque<CustomerOrder> m_orders;
    std::string m_name; // stationName
    ItemSet m_itemSet;
  public:
    Station(const Station&) = delete; // Copy cosntructor
    Station(Station&&) = delete; // Move constructor
    Station& operator=(const Station&) = delete; // Copy assignment
    Station& operator=(Station&&) = delete; // Move assignment
    Station(const std::string& item_src);
    void display(std::ostream& os) const;
    void fill(std::ostream& os);
    const std::string& getName() const;
    bool hasAnOrderToRelease() const;
    Station& operator--();
    Station& operator+=(CustomerOrder&& order_src);
    bool pop(CustomerOrder& ready);
    void validate(std::ostream& os) const;


  };
}

#endif //SICT_STATION_H_