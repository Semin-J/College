// Name: Semin Jeon
// Date: 2019-04-05
// MS03

#ifndef SICT_LINEMANAGER_H_
#define SICT_LINEMANAGER_H_

#include <vector>
#include <deque>
#include "Station.h"

namespace sict {
  class LineManager {
    std::deque<CustomerOrder> waiting;
    std::deque<CustomerOrder> completed;
    std::deque<CustomerOrder> incompleted;
    std::vector<Station*> m_stn;
    std::vector<size_t> assemblyLine;
    size_t firstStn;
    size_t lastStn;
    std::vector<size_t> nextStn;

  public:
    LineManager(std::vector<Station*>& stn_src, std::vector<size_t>& index_nextStn,
                std::vector<CustomerOrder>& order_src, size_t start_point, std::ostream& os);
    void display(std::ostream& os) const;
    bool run(std::ostream& os);

  };
}

#endif //SICT_LINEMANAGER_H_