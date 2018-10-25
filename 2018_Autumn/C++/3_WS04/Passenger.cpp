//Name: Semin Jeon
//WS04
//2018/10/04

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Passenger.h"

using namespace std;
// TODO: continue your namespace here
namespace sict{
  const int max_size = 19;
  char o_name[max_size];
  char dest[max_size];
  int year, month, day;
      // TODO: implement the default constructor here
    Passenger::Passenger() {
      set();
    }
      // TODO: implement the constructor with 2 parameters here
    Passenger::Passenger(const char* passenger_name, const char* destination) {
      if (passenger_name != nullptr && destination != nullptr) {
        strncpy(o_name, passenger_name, max_size);
        o_name[max_size - 1] = '\0';
        strncpy(dest, destination, max_size);
        dest[max_size - 1] = '\0';
        year = 2018;
        month = 10;
        day = 1;
      }
      else
        set();
    }

    //Constructor with 5 parameters 
    Passenger::Passenger(const char* passenger_name, const char* destination, int year, int month, int day) {
      if (passenger_name != nullptr && destination != nullptr && year >= 2018 && year <= 2020
          && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
        strncpy(o_name, passenger_name, max_size);
        o_name[max_size - 1] = '\0';
        strncpy(dest, destination, max_size);
        dest[max_size - 1] = '\0';
        this->year = year;
        this->month = month;
        this->day = day;

      }
      else
        set();
    }

    //Setter for safe empty state
    void Passenger::set() {
      o_name[0] = '\0';
      dest[0] = '\0';
      year = 0;
      month = 0;
      day = 0;
    }
    
    //return name to client
    const char* Passenger::name() const {
      return o_name;
      //constructor initialize the data member safely already
      //So, whether the name is empty or not, doesn't matter
    }


    bool Passenger::canTravelWith(const Passenger& friends) {
      bool travel;
      if (strcmp(this->dest,friends.dest) == 0 && (year == friends.year) && (month == friends.month) && (day == friends.day))
        travel = true;
      else
        travel = false;

      return travel;
    }

    // TODO: implement isEmpty query here
    bool Passenger::isEmpty() const {
      bool empty;
      if (o_name == nullptr || o_name[0] == '\0' || dest == nullptr || dest[0] == '\0')
        empty = true;
      else
        empty = false;

      return empty;

    }
      // TODO: implement display query here
    void Passenger::display() const {
      if ((o_name[0] != 0) && (dest[0] != 0)) {
        cout << o_name << " - " << dest << " on " << year << "/" 
          << setfill('0') << setw(2) << month << "/" 
          << setfill('0') << setw(2) << day << endl;
      }
      else
        cout << "No passenger!" << endl;
    }

}