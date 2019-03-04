// Name: Semin Jeon
// Date: 2019-02-13
// WS05: Functions and Error handling

#ifndef SICT_KVPAIR_H_
#define SICT_KVPAIR_H_

//#include <iostream>
//#include <iomanip>
extern int fieldWidth;

namespace sict {
  template <typename K, typename V>
  class KVPair {
    K m_key;
    V m_value;
  public:
    // Default Constructor
    KVPair() {};

    // 2 Arguments Constructor
    KVPair(const K& key_src, const V& value_src) : m_key(key_src), m_value(value_src) {};

    // Display
    template<typename F>
    void display(std::ostream& os, F func_src) const {
      os << std::left << std::setw(fieldWidth) << m_key << " : "
        << std::right << std::setw(fieldWidth) << m_value
        << std::setw(fieldWidth) << func_src(m_value) << std::endl;
    }
  };
}

#endif //SICT_KVPAIR_H_