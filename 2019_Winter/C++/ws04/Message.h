// Name: Semin Jeon
// Date: 2019-02-12
// WS04: composition and aggregation classes

#ifndef SICT_MESSAGE_H_
#define SICT_MESSAGE_H_

#include <iostream>
#include <string>

namespace sict {
  class Message {
    std::string m_user;
    std::string m_reply; //prefaced by an @
    std::string m_msg;
  public:
    Message(){}; //string objects are already in safe empty state("")
    Message(const std::string& str_src);
    bool empty() const;
    void display(std::ostream& os) const;
    bool operator==(const Message& msg_src) const;
  };
}

#endif // !SICT_MESSAGE_H_
