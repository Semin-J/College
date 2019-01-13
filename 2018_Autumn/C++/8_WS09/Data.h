// Name: Semin Jeon
// Date: 2018/11/19
//

#ifndef DATA_H_
#define DATA_H_
#include <iostream>
#include <iomanip>
#include <cstring>

namespace sict {
	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

  template <typename T>
  T max(const T* data, int n) {
    T big = data[0];
    for (int i = 1; i < n; i++) {
      if (data[i] > big && data[i] < LARGEST_NUMBER)
        big = data[i];
    }
    return big;
  }


  template <typename T>
  T min(const T* data, int n) {
    T small = data[0];
    for (int i = 1; i < n; i++) {
      if (data[i] < small && data[i] > SMALLEST_NUMBER)
        small = data[i];
    }
    return small;
  }
        
  
  template <typename T>
  T sum(const T* data, int n) {
    T added = 0;
    for (int i = 0; i < n; i++) {
      added += data[i];
    }
    return added;
  }

  template <typename T>
  double average(const T* data, int n) {
    return sum(data, n) / n;
  }

  template <typename T>
  bool read(std::istream& input, T* data, int n) {
    bool ok = true;
    if (ok) {
      for (int i = 0; i < n; i++) {
        input.ignore(2000, ',');
        if (input.fail()) 
          ok = false;
        input >> data[i];
      }
    }
    return ok;
  }

  template <typename T>
  void display(const char* name, const T* data, int n) {
    std::cout << std::setw(20) << std::right << name;
    for (int i = 0; i < n; i++) {
      std::cout << std::setw(COLUMN_WIDTH) << data[i];
    }
    std::cout << std::endl;
  }

  template <class T>
  bool readRow(std::istream& input, const char* name, T* data, int n){
    char rowname[2000];
    bool ok = !input.bad();
    if (ok) {
      input.get(rowname, 2000, ',');
      if (std::strcmp(rowname, name) != 0) {
        std::cout << "Cannot parse row for " << name << std::endl;
        input.ignore(2000, '\n');
        ok = false;
      }
    }
    if (ok)
      ok = read(input, data, n);
    input.ignore(2000, '\n');
    return ok;
  }
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}
#endif // !DATA_H_

