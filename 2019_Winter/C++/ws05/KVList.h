// Name: Semin Jeon
// Date: 2019-02-16
// WS05: Functions and Error handling

#ifndef SICT_KVLIST_H_
#define SICT_KVLIST_H_

//#include <iostream>
//#include <iomanip>

namespace sict {
  template <typename T>
  class KVList {
    T* m_obj;
    int m_size;
    int m_current;
  public:
    KVList(const KVList&) = delete; // Copy Constructor
    KVList& operator=(const KVList&) = delete; // Copy Assignment
    KVList& operator=(KVList&&) = delete; // Move Assignment
    
    // Default Constructor
    KVList() : m_obj(nullptr), m_size(0), m_current(0) {}

    // 1 Arguments Constructor
    KVList(int size_src) : m_obj(nullptr), m_size(0), m_current(0) {
      if (size_src > 0) {
        m_size = size_src;
        m_obj = new T[m_size];
      }
      else { throw "The size should be positive value"; }
    }

    // Move Constuctor
    KVList(KVList&& list_src) { 
      m_obj = list_src.m_obj;
      list_src.m_obj = nullptr;
      m_current = list_src.m_current;
      list_src.m_current = 0;
      m_size = list_src.m_size;
      list_src.m_size = 0;
    }

    // Destructor
    ~KVList() { delete[] m_obj; m_obj = nullptr; }

    // Operator[]
    const T& operator[](size_t idx) const { 
      if (idx < 0 || idx >= m_size) { throw "Out-of-bounds"; }
      return m_obj[idx]; 
    }

    // Display
    template <typename F>
    void display(std::ostream& os, F func_src) const {
      for (int i = 0; i < m_size; ++i)
        m_obj[i].display(os, func_src);
    }

    // Push Back
    void push_back(const T& t_src) {
      if (m_current < m_size) {
        m_obj[m_current] = t_src;
        ++m_current;
      }
    }
  };
}

#endif //SICT_KVLIST_H_