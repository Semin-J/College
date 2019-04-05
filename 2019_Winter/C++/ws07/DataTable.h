// name: Semin Jeon
// Student ID: 146453162 (sjeon18@myseneca.ca)
// Date: 2019-03-16
// WS07: STL Algorithms

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <cmath>
extern int FW, ND; //Field Width, Number Precision

namespace sict {
  template<typename T>
  class DataTable {
    int m_num;
    std::vector<std::vector<T>> m_data; // didn't use parellel vector, since binding as a pair is more properly reflect the (x, y) pair
  public:
    DataTable(std::ifstream& file) : m_num(0) {
      std::string line_src;
      while (std::getline(file, line_src)) {
        ++m_num;
      }
      file.clear();
      file.seekg(0, std::ios::beg);
      m_data.resize(m_num, std::vector<T>(2, 0));
      size_t pos = 0u;
      for (int i = 0; i < m_num; ++i) {
        std::getline(file, line_src, '\n');
        pos = line_src.find(" ");
        if (pos != std::string::npos) {
          m_data[i][0] = (T)std::stod(line_src.substr(0, pos));
          m_data[i][1] = (T)std::stod(line_src.substr(pos + 1));
        }
      }
    }

    T mean() const {
      T mean = (T)0;
      for (int i = 0; i < m_num; ++i)
        mean += m_data[i][1];
      return mean / m_num;
    }

    T sigma() const {
      T sigma = (T)0;
      for (int i = 0; i < m_num; ++i)
        sigma += (T)std::pow(m_data[i][1] - mean(), 2);
      return std::sqrt(sigma / (T)(m_num - 1));
    }

    T median() const {
      T* tmp = new T[m_num];
      for (int i = 0; i < m_num; ++i) {
        tmp[i] = m_data[i][1];
      }
      std::sort(tmp, tmp + m_num);
      int i = std::round((m_num + 1) / 2);
      T med = tmp[i];
      delete[] tmp;
      return med;
    }

    T slope() const { // n(num1) - num2 / n(num3) - num4^2
      T num1 = (T)0;
      T num3 = (T)0;
      T num4 = (T)0;
      T x = (T)0;
      T y = (T)0;
      for (int i = 0; i < m_num; ++i) {
        num1 += (m_data[i][0] * m_data[i][1]);
        x += m_data[i][0];
        y += m_data[i][1];
        num3 += std::pow(m_data[i][0], 2);
        num4 += m_data[i][0];
      }
      T num2 = x * y;
      return (m_num * num1 - num2) / (m_num * num3 - std::pow(num4, 2));
    }

    T intercept() const { // y - slope*x / n
      T x = T(0); T y = (T)0;
      for (int i = 0; i < m_num; ++i) {
        x += m_data[i][0];
        y += m_data[i][1];
      }
      return (y - slope() * x) / m_num;
    }


    void displayData(std::ostream& os) const {
      os << "Data Values" << std::endl << "------------" << std::endl;
      os << std::setw(FW) << std::setprecision(ND) << "x"
        << std::setw(FW) << std::setprecision(ND) << "y" << std::endl;
      os.precision(ND);
      for (int i = 0; i < m_num; ++i) {
        os << std::setw(FW) << std::fixed << m_data[i][0]
          << std::setw(FW) << std::fixed << m_data[i][1] << std::endl;
      }
    }
    void displayStatistics(std::ostream& os) const {
      os << "\nStatistics" << std::endl << "----------" << std::endl;
      os << "  y mean    = " << std::setw(FW) << std::setprecision(ND) << mean() << std::endl;
      os << "  y sigma   = " << std::setw(FW) << std::setprecision(ND) << sigma() << std::endl;
      os << "  y median  = " << std::setw(FW) << std::setprecision(ND) << median() << std::endl;
      os << "  slope     = " << std::setw(FW) << std::setprecision(ND) << slope() << std::endl;
      os << "  intercept = " << std::setw(FW) << std::setprecision(ND) << intercept() << std::endl;
    }
  };
}

#endif //SICT_DATA_TABLE_H
