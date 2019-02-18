// Name: Semin Jeon
// Date: 2019-02-12
// WS04: composition and aggregation classes

#include "MessagePack.h"

namespace sict {
  // Default constructor
  MessagePack::MessagePack() : m_pack(nullptr), m_num(0) {};

  // 2 argumetns constructor
  MessagePack::MessagePack(Message** pack_src, int num_src) : m_num(0) {
    if (pack_src != nullptr && num_src > 0) {
      m_num = num_src;
      for (int i = 0; i < num_src; ++i) {
        if (pack_src[i]->empty()) { m_num--; }
      }
      m_pack = new Message*[m_num];
      int j = 0;
      for (int i = 0; i < num_src; ++i) {
        if (!(pack_src[i]->empty())) {
          m_pack[j++] = new Message(*pack_src[i]);
        }
      }
    }
    else { *this = MessagePack(); }
  }

  // Copy constructor
  MessagePack::MessagePack(const MessagePack& pack_src) : m_pack(nullptr), m_num(0) {
    *this = pack_src;
  }

  // Move constructor
  MessagePack::MessagePack(MessagePack&& pack_src) : m_pack(nullptr), m_num(0) {
    *this = std::move(pack_src);
  }

  // Copy assignment
  MessagePack& MessagePack::operator=(const MessagePack& pack_src) {
    for (int i = 0; i < m_num; ++i) {
      delete m_pack[i];
      m_pack[i] = nullptr;
    }
    delete[] m_pack;
    m_pack = new Message*[pack_src.m_num];
    m_num = pack_src.m_num;
    for (int i = 0; i < m_num; ++i) {
      m_pack[i] = new Message(*(pack_src.m_pack[i]));
    }
    return *this;
  }

  // Move assignment
  MessagePack& MessagePack::operator=(MessagePack&& pack_src) {
    if (this != &pack_src) {
      for (int i = 0; i < m_num; ++i) {
        delete m_pack[i];
        m_pack[i] = nullptr;
      }
      delete[] m_pack;
      m_pack = pack_src.m_pack;
      pack_src.m_pack = nullptr;
      m_num = pack_src.m_num;
      pack_src.m_num = 0;
    }
    return *this;
  }

  // Destructor
  MessagePack::~MessagePack() {
    for(int i = 0; i < m_num; ++i) {
      delete m_pack[i];
      m_pack[i] = nullptr;
    }
    delete[] m_pack;
    m_pack = nullptr;
  }

  void MessagePack::display(std::ostream& os) const {
    for (int i = 0; i < m_num; ++i)
      m_pack[i]->display(os);
  }

  size_t MessagePack::size() const {
    return m_num;
  }

  std::ostream& operator<<(std::ostream& os, const MessagePack& pack_src) {
    pack_src.display(os);
    return os;
  }
}