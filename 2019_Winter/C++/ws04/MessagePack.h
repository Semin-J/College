// Name: Semin Jeon
// Date: 2019-02-12
// WS04: composition and aggregation classes

#ifndef SICT_MSGPACK_H_
#define SICT_MSGPACK_H_

#include <iostream>
#include "Message.h"

namespace sict {
  class MessagePack {
    Message** m_pack;
    int m_num;
  public:
    MessagePack();
    MessagePack(Message** pack_src, int num_src);
    MessagePack(const MessagePack& pack_src);
    MessagePack(MessagePack&& pack_src);
    MessagePack& operator=(const MessagePack& pack_src);
    MessagePack& operator=(MessagePack&& pack_src);
    ~MessagePack();
    void display(std::ostream& os) const;
    size_t size() const;
  };
  std::ostream& operator<<(std::ostream& os, const MessagePack& pack_src);
}

#endif //SICT_MSGPACK_H_