// Name: Semin Jeon
// Date: 2018/11/24
// Perishable class is a separate concrete class that encapsulates information for perishable goods.

#include "Perishable.h"
#include <iomanip>
#include <iostream>

using namespace std;

namespace aid{
  Perishable::Perishable() : Good('P') {}
  Perishable::~Perishable() {}

  std::fstream& Perishable::store(std::fstream & file, bool newLine) const {
    Good::store(file, false);
    file << ",";
    if (!this->isEmpty()) {
      expiry_date.write(file);
      if (newLine)
        file << "\n";
    }
    return file;

  }

  std::fstream& Perishable::load(std::fstream & file) {
    Good::load(file);
    file >> expiry_date;
    file.ignore();
    return file;
  }

  std::ostream& Perishable::write(std::ostream & os, bool linear) const {

    if (Good::isClear()) {
      Good::write(os, linear);
      if (!isEmpty()) {
        if (linear) {
          //os << left;
          os << expiry_date;
        }
        else {
          os << "\n Expiry date: " << expiry_date;
        }
      }
    }
    else {
      os << Good::message();
    }
    return os;
  }

  std::istream& Perishable::read(std::istream & is) {
    Good::read(is);
    if (Good::isClear()) {
      Date tmp;
      cout << " Expiry date (YYYY/MM/DD): ";
      tmp.read(is);
      if (tmp.bad()) {
        is.setstate(std::ios::failbit);
        
        if (tmp.errCode() == 1) Good::message("Invalid Date Entry");
        else if (tmp.errCode() == 2) Good::message("Invalid Day in Date Entry");
        else if (tmp.errCode() == 3) Good::message("Invalid Month in Date Entry");
        else if (tmp.errCode() == 4) Good::message("Invalid Year in Date Entry");
        else if (tmp.errCode() == 5) Good::message("Invalid Expiry in Date Entry");
        //clearError();
      }
      else {
        this->expiry_date = tmp;
        is.fail();
      }
    }
    return is;
  }

  const Date & Perishable::expiry() const {
    return expiry_date;
  }
}

