// Name: Semin Jeon
// Date: 2018/11/03

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {
  Contact::Contact() {
    strcpy(mname, "");
    mphone = nullptr;
    contactLen = 0;
  }

  Contact::Contact(const char* name, long long* phones, int num) { 
    int size = num;
    contactLen = 0;
    mphone = new long long[size];
    
    for (int i = 0; i < size; i++) {
      bool valid = true; bool country = true; bool local = true;
      if (phones[i] < 10000000000LL || phones[i] >= 1000000000000LL)
        valid = false;
      if ((phones[i] / 10000000000LL) < 0 || (phones[i] / 10000000000LL) > 99)
        country = false;
      if (((phones[i] % 10000000000LL) / 10000000LL < 100) || ((phones[i] % 10000000000LL) / 10000000LL > 999))
        local = false;
      if (valid == true && country == true && local == true) {
        mphone[contactLen] = phones[i];
        contactLen++;
      }
    }
    if (name != nullptr && strlen(name) > 0) {
        strncpy(mname, name, MAX_CHAR);
        mname[MAX_CHAR] = '\0';
    }
    else *this = Contact();
  }

  Contact::Contact(const Contact& rhs) {
    strcpy(this->mname, rhs.mname);
    this->contactLen = rhs.contactLen;
    this->mphone = new long long[rhs.contactLen];
    for (int i = 0;  i < contactLen; i++) {
      this->mphone[i] = rhs.mphone[i];
    }
  }

  Contact::~Contact() {
    delete[] mphone;
  }

  bool Contact::isEmpty() const {
    bool correct;
    if (mname == nullptr || strlen(mname) == 0)
      correct = true;
    else
      correct = false;

    return correct;
  }

  void Contact::display() const {
    if (isEmpty())
      cout << "Empty contact!" << endl;
    else {
      cout << mname << endl;
      for (int i = 0; i < contactLen; i++) {
        long long country, local, front3, back4, rest;
        country = mphone[i] / 10000000000LL;
        rest = mphone[i] % 10000000000LL;
        local = rest / 10000000LL;
        rest %= 10000000LL;
        front3 = rest / 10000LL;
        rest %= 10000LL;
        back4 = rest;
        cout << "(+" << country << ") " << local << " " << front3 << "-";
        cout.fill('0');
        cout.width(4);
        cout << back4 << endl;
      }
    }
  }

  Contact& Contact::operator =(const Contact& rhs) {
    if(*this != rhs) {
      delete[] this->mphone;
      this->mphone = nullptr;
      strcpy(this->mname, rhs.mname);
      this->contactLen = rhs.contactLen;
      this->mphone = new long long[rhs.contactLen];
      for (int i = 0; i < this->contactLen; i++) {
        this->mphone[i] = rhs.mphone[i];
      }
    }
    return *this;
  }

  Contact& Contact::operator +=(long long new_number) {
      bool valid = true; bool country = true; bool local = true;
      if (new_number < 10000000000LL || new_number >= 1000000000000LL)
        valid = false;
      if ((new_number / 10000000000LL) < 0 || (new_number / 10000000000LL) > 99)
        country = false;
      if (((new_number % 10000000000LL) / 10000000LL < 100) || ((new_number % 10000000000LL) / 10000000LL > 999))
        local = false;
      if (valid == true && country == true && local == true) {
        contactLen++;
        long long* temp = new long long[contactLen];
        for (int i = 0; i < contactLen-1; i++) {
          temp[i] = mphone[i];
        }
        temp[contactLen - 1] = new_number;
        mphone = temp;
        temp = nullptr;
        delete[] temp;
      }
      return *this;
  }

  bool Contact::operator !=(const Contact& rhs) {
    bool not_same;
    bool name, phones, number = false;
    int match = 0;
    if (strcmp(mname, rhs.mname) == 0)
      name = true;
    if (this->contactLen == rhs.contactLen) {
      number = true;
      for (int i = 0; i < this->contactLen; i++) {
        if (this->mphone[i] == rhs.mphone[i])
          match++;
      }
      if (this->contactLen == match)
        phones = true;
    }

    if (name && phones && number)
      not_same = false;
    else not_same = true;

    return not_same;
  }
}