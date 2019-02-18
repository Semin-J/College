// Name: Semin Jeon
// WS03 Templates
// Date: 2019-02-03
// List.h
#ifndef SICT_LIST_H_
#define SICT_LIST_H_

#include <iostream>
#include "LVPair.h"

namespace sict {
  // T: type of any element in the array, N: the max num in the array
  template <typename T, int N>
  class List {
    T m_arr[N];
    size_t m_current{ 0u };
  public:
    size_t size() const { return m_current; }

    const T& operator[](size_t idx) const { return m_arr[idx]; }

    void operator+=(const T& t_src) {
      if (m_current < N) {
        m_arr[m_current] = t_src;
        ++m_current;
      }
    }
  };

  // T: type of any elements in the array, L: type of the specified label
  // V: type of the summation value, N: the max number of elements in the array
  
  //Primary template for LVList
  template <typename T, typename L, typename V, int N>
  class LVList : public List<T, N> {
  public:
    V accumulate(const L& label_src) const {
      SummableLVPair<L, V> temp;

      V result = temp.getInitialValue();

      for (size_t i = 0; i < ((List<T, N>&)*this).size(); i++) {
        temp = ((List<T, N>&)*this)[i];
        result = temp.sum(label_src, result);
      }
      return result;
    }
  };
  
  
}

#endif // !SICT_LIST_H_

