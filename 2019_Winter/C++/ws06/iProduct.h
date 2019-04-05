// Name: Semin Jeon
// Student ID: 146453162 (sjeon18@myseneca.ca)
// Date: 2019-03-05
// WS06: STL containers

#ifndef SICT_IPRODUCT_H_
#define SICT_IPRODUCT_H_

extern int FW;

namespace sict {
  class iProduct {

  public:
    virtual double price() const = 0;
    virtual void display(std::ostream& os) const = 0;
  };
  std::ostream& operator<<(std::ostream& os, const iProduct& p);
  iProduct* readRecord(std::ifstream& file);
}

#endif //SICT_IPRODUCT_H_