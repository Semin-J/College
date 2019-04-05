// Name: Semin Jeon
// Student ID: 146453162 (sjeon18@myseneca.ca)
// Date: 2019-03-05
// WS06: STL containers

#ifndef SICT_PRODUCT_H_
#define SICT_PRODUCT_H_

#include "iProduct.h"

namespace sict {
  class Product : public iProduct {
    int m_product;
    double m_price;
  public:
    Product(); // default constructor
    Product(int product_src, double price_src); // 2-arg constructor
    double price() const;
    void display(std::ostream& os) const;
  };

  class TaxableProduct : public Product {
    double m_tax;
    enum class Tax { HST, PST };
  public:
    TaxableProduct(int product_src, double price_src, char tax_src);
    double price() const;
    void display(std::ostream& os) const;
  };

  iProduct* readRecord(std::ifstream& file);
  std::ostream& operator<<(std::ostream& os, const iProduct& p);

}

#endif //SICT_PRODUCT_H_