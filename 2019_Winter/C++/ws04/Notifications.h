// Name: Semin Jeon
// Date: 2019-02-12
// WS04: composition and aggregation classes

#ifndef SICT_NOTIFICATIONS_H_
#define SICT_NOTIFICATIONS_H_

#include <iostream>
#include "Message.h"

namespace sict {
  class Notifications {
    const Message** m_msgArr;
    int m_max;
    int m_current;
  public:
    Notifications();
    Notifications(int max_src);
    Notifications(const Notifications& noti_src);
    Notifications(Notifications&& noti_src);
    ~Notifications();
    Notifications& operator=(const Notifications& noti_src);
    Notifications& operator=(Notifications&& noti_src);
    Notifications& operator+=(const Message& msg_src);
    Notifications& operator-=(const Message& msg_src);
    void display(std::ostream& os) const;
    size_t size() const;
  };

  std::ostream& operator<<(std::ostream& os, const Notifications& noti_src);
}

#endif //SICT_NOTIFICATIONS_H_