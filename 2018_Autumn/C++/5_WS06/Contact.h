// Name: Semin Jeon
// Date: 2018/11/03

#ifndef CONTACT_H
#define CONTACT_H

namespace sict {
  const int MAX_CHAR = 20;
  class Contact {
    char mname[MAX_CHAR + 1];
    long long* mphone; //memory allocation
    int contactLen;
  public:

    //Constructors
    Contact();
    Contact(const char*, long long*, int);
    Contact(const Contact&); //copy constructor
    ~Contact();

    //member functions
    bool isEmpty() const;
    void display() const;

    //operator overloading
    Contact& operator =(const Contact&);
    Contact& operator +=(long long);
    bool operator !=(const Contact&); // additional overloaded member operator
  };
}
#endif
