// Name: Semin Jeon
// Date: 2019-02-12
// WS04: composition and aggregation classes

#include "Message.h"

namespace sict {
  // 2 arguments constructor
  Message::Message(const std::string & str_src) {
    size_t space = str_src.find(" ");
    if (space < str_src.size()) { // if there is no space in the line, let it skip
      m_user = str_src.substr(0, space);
      if (str_src.find("@") == std::string::npos) {
        std::string tmp_msg = str_src.substr(space + 1);
        if (tmp_msg.size() > 0) { m_msg = tmp_msg; }
        else { m_user = ""; } // m_reply, m_msg is already in safe empty state
      }
      else {
        size_t beforeMsg = str_src.find(" ", space + 1);
        m_reply = str_src.substr(space + 2, beforeMsg - (space + 2));
        std::string tmp_msg = str_src.substr(beforeMsg + 1);
        if (tmp_msg.size() > 0) { m_msg = tmp_msg; }
        else { m_user = "", m_reply = ""; } // m_msg is already in safe empty state
      }
    }
  }

  // isEmpty?
  bool Message::empty() const {
    return (m_user.empty() || m_msg.empty()) ? true : false;
  }

  // Display
  void Message::display(std::ostream& os) const {
    if (!empty()) {
      os << ">User  : " << m_user << std::endl;
      if (!m_reply.empty())
        os << " Reply : " << m_reply << std::endl;
      os << " Tweet : " << m_msg << std::endl;
    }
  }
  bool Message::operator==(const Message& msg_src) const {
    if ((m_msg == msg_src.m_msg) && (m_reply == msg_src.m_reply) && (m_user == msg_src.m_user))
      return true;
    else { return false; }
  }
}
