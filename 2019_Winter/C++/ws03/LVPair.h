// Name: Semin Jeon
// WS03 Templates
// Date: 2019-02-03
// LVPair.h
#ifndef SICT_LVPAIR_H_
#define SICT_LVPAIR_H_

#include <iostream>
#include <string>
//#include "List.h"

namespace sict {
  // L: type of the label, V: type of the value
  template <typename L, typename V>
  class LVPair {
    L m_label;
    V m_value;
  public:
    LVPair() {}
    LVPair(const L& label_src, const V& value_src) {
      m_label = label_src;
      m_value = value_src;
    }

    const L& label() const { return m_label; }

    const V& value() const { return m_value; }

    virtual void display(std::ostream& os) const {
      os << m_label << " : " << m_value << std::endl;
    }

  };

  template <typename L, typename V>
  std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair_src) {
    pair_src.display(os);
    return os;
  }

  template <typename L, typename V>
  class SummableLVPair : public LVPair<L, V> {
    static V m_initV;
    static size_t m_minW; //minimum width of label field(m_label's max length)
  public:
    SummableLVPair() {}

    SummableLVPair(const L& label_src, const V& value_src) : LVPair<L, V>::LVPair(label_src, value_src) {
      size_t labelWidth = label_src.size();
      if (labelWidth > m_minW) { m_minW = labelWidth; }
    }

    const V& getInitialValue() {
      return m_initV;
    }

    V sum(const L& label_src, const V& sum) const {
      V result = sum;
      if (label_src == LVPair<L, V>::label())
        result = LVPair<L, V>::value() + sum;
      return result;
    }

    void display(std::ostream& os) const {
      os << std::left;
      os.width(m_minW);
      LVPair<L, V>::display(os);
    }

  };

  template <typename L, typename V>
  size_t SummableLVPair<L, V>::m_minW = 0;

  template <>
  int SummableLVPair<std::string, int>::m_initV = 0;

  template <> // I think this initializaion for m_initV is not needed since, according to the documentation, the class String takes care of that for us
  std::string SummableLVPair<std::string, std::string>::m_initV = "";

  template <>
  SummableLVPair<std::string, int>::SummableLVPair(const std::string& label_src, const int& value_src) : LVPair<std::string, int>::LVPair(label_src, value_src) {
    if (label_src.size() > m_minW) { m_minW = label_src.size(); }
  }

  template <>
  SummableLVPair<std::string, std::string>::SummableLVPair(const std::string& label_src, const std::string& value_src) : LVPair<std::string, std::string>::LVPair(label_src, value_src) {
    if (label_src.size() > m_minW) { m_minW = label_src.size(); }
  }

  template <>
  std::string SummableLVPair<std::string, std::string>::sum(const std::string& label_src, const std::string& sum) const {
    std::string result = sum;
    if (label_src == LVPair<std::string, std::string>::label())
      result = sum + ' ' + LVPair<std::string, std::string>::value();
    return result;

  }

}

#endif // !SICT_LVPAIR_H_
