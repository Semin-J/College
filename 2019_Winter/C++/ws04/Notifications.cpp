// Name: Semin Jeon
// Date: 2019-02-12
// WS04: composition and aggregation classes

#include "Notifications.h"

namespace sict {

  // Default construtor
  Notifications::Notifications() : m_msgArr(nullptr), m_max(0), m_current(0) {};

  // 1 argument constructor
  Notifications::Notifications(int max_src) : m_max(0), m_current(0) {
    if (max_src > 0) {
      m_max = max_src;
      m_msgArr = new const Message*[m_max];
      for (int i = 0; i < m_max; ++i)
        m_msgArr[i] = nullptr;
    }
    else { *this = Notifications(); }
  }

  // Copy constructor
  Notifications::Notifications(const Notifications& noti_src) : m_msgArr(nullptr), m_max(0), m_current(0) {
    *this = noti_src;
    }


  // Move constructor
  Notifications::Notifications(Notifications&& noti_src) : m_msgArr(nullptr), m_max(0), m_current(0) {
    *this = std::move(noti_src);
  }

  // Destructor
  Notifications::~Notifications() {
    delete[] m_msgArr;
    m_msgArr = nullptr;
  }

  // Copy assignment
  Notifications& Notifications::operator=(const Notifications& noti_src) {
    if (this != &noti_src) {
      delete[] m_msgArr;
      m_max = noti_src.m_max;
      m_msgArr = new const Message*[noti_src.m_max];
      for (int i = 0; i < m_max; i++)
        m_msgArr[i] = nullptr;
      m_current = noti_src.m_current;
      for (int i = 0; i < m_current; ++i) {
        m_msgArr[i] = noti_src.m_msgArr[i];
      }
    }
    return *this;
  }

  // Move assignment
  Notifications& Notifications::operator=(Notifications&& noti_src) {
    if (this != &noti_src) {
      delete[] m_msgArr;
      m_msgArr = noti_src.m_msgArr;
      noti_src.m_msgArr = nullptr;
      m_max = noti_src.m_max;
      noti_src.m_max = 0;
      m_current = noti_src.m_current;
      noti_src.m_current = 0;
    }
    return *this;
  }

  Notifications& Notifications::operator+=(const Message& msg_src) {
    if (!msg_src.empty() && (m_current < m_max))
      m_msgArr[m_current++] = &msg_src;
    return *this;
  }

  Notifications& Notifications::operator-=(const Message& msg_src) {
    bool found = false;
    int i;
    for (i = 0; i < m_current && !found; ++i) {
      if (*m_msgArr[i] == msg_src) { found = true; }
    }
    if (found) {
      for (; i < m_current; i++) {
        m_msgArr[i - 1] = m_msgArr[i];
      }
      if (m_current) {
        m_msgArr[--m_current] = nullptr;
      }
    }
    return *this;
  }

  void Notifications::display(std::ostream& os) const {
    for (int i = 0; i < m_current; ++i)
      m_msgArr[i]->display(os);
  }

  size_t Notifications::size() const {
    return m_current;
  }

  std::ostream& operator<<(std::ostream& os, const Notifications& noti_src) {
    noti_src.display(os);
    return os;
  }

}