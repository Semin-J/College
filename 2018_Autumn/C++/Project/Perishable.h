// Name: Semin Jeon
// Date: 2018/11/24
// Perishable class is a separate concrete class that encapsulates information for perishable goods.

#ifndef PERISHABLE_H_
#define PERISHABLE_H_

#include "Good.h"
#include "Date.h"
#include <fstream>

namespace aid {
  class Perishable : public Good {
  private:
    Date expiry_date;
    //const char* fileName;//using different pointer?
  public:
    Perishable();
    ~Perishable();
    std::fstream& store(std::fstream& file, bool newLine = true) const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear) const;
    std::istream& read(std::istream& is);
    const Date& expiry() const;
  };
}
#endif // !PERISHABLE_H_

