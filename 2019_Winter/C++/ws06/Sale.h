// Name: Semin Jeon
// Date: 2019-03-05
// WS06: STL containers

#ifndef SICT_SALE_H_
#define SICT_SALE_H_

#include "Product.h"
#include <vector>

namespace sict {
  class Sale {
    std::vector<const iProduct*> m_record;
  public:
    Sale(const char* name); // 1-arg constructor
    void display(std::ostream& os) const;
  };
}

#endif //SICT_SALE_H_