// Name: Semin Jeon
// Student ID: 146453162 (sjeon18@myseneca.ca)
// Date: 2019-03-05
// WS06: STL containers

#include <fstream>
#include <string>
#include <iomanip>
#include "Product.h"

extern int FW;

namespace sict {
  Product::Product() : m_product(0), m_price(0.0) {}

  Product::Product(int product_src, double price_src) : m_product(product_src), m_price(price_src) {
    if (product_src < 0 || price_src < 0.0) { *this = Product(); }
  }

  double Product::price() const { return m_price; }
  void Product::display(std::ostream& os) const {
    os << std::setw(FW) <<  m_product 
      << std::setw(FW) << m_price;
  }

  TaxableProduct::TaxableProduct(int product_src, double price_src, char tax_src)
    : Product(product_src, price_src), m_tax(tax_src == 'H' ? 0.13 : 0.08) {
  };
  double TaxableProduct::price() const {
    return Product::price() * (1 + m_tax);
  }
  void TaxableProduct::display(std::ostream & os) const {
    Product::display(os);
    if (m_tax == 0.13)
      os << " HST";
    else
      os << " PST";
  }

  iProduct* readRecord(std::ifstream& file) {
    iProduct* result = nullptr;
    std::string line_src;
    std::getline(file, line_src, '\n');
    size_t pos = line_src.find(" ");
    if (pos != std::string::npos) {
      if (line_src.length() > 11) {
        int product_tmp = stoi(line_src.substr(0, pos));
        double price_tmp = stod(line_src.substr(pos + 1, pos + 6));
        char tax_tmp = line_src[pos + 7];
        result = new TaxableProduct(product_tmp, price_tmp, tax_tmp);
      }
      else {
        int product_tmp = stoi(line_src.substr(0, pos));
        double price_tmp = stod(line_src.substr(pos + 1, pos + 6));
        result = new Product(product_tmp, price_tmp);
      }
    }
    return result;
  }
  
}