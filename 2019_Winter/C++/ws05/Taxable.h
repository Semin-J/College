// Name: Semin Jeon
// Date: 2019-02-13
// WS05: Functions and Error handling

#ifndef SICT_TAXABLE_H_
#define SICT_TAXABLE_H_

namespace sict {
  class Taxable {
    const float m_tax;
  public:
    Taxable(float tax_src) : m_tax(tax_src) {}
    float operator()(float price_src) {
      return price_src * (1 + m_tax);
    }
  };
}

#endif //SICT_TAXABLE_H_