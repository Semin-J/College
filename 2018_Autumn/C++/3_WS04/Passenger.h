//Name: Semin Jeon
//WS04
//2018/10/04

// TODO: add header file guard here
#ifndef PASSENGER_H_
#define PASSENGER_H_

// TODO: declare your namespace here
namespace sict{
    // TODO: define the Passenger class here
  class Passenger {
    char o_name[19];
    char dest[19];
    int year, month, day;
  public:
    Passenger();
    Passenger(const char*, const char*);
    Passenger(const char*, const char*, int, int, int);
    void set();
    const char* name() const;
    bool canTravelWith(const Passenger&);
    bool isEmpty() const;
    void display() const;
  };
}
#endif
