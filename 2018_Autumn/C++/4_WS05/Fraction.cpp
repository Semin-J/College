//name: Semin Jeon
//WS05
//2018/10/13

// TODO: insert header files
#include <iostream>
#include "Fraction.h"
// TODO: continue the namespace
using namespace std;
namespace sict{

  int nu; //numerator(above line)
  int de; //denominator(below line)

	// TODO: implement the default constructor
  Fraction::Fraction() {
    safe_set();
  }
  
	// TODO: implement the two-argument constructor
  Fraction::Fraction(int numerator, int denominator) {
    if(numerator >= 0 && denominator > 0) {
      nu = numerator;
      de = denominator;
    }
    else safe_set();
  }

  //set function for safe empty state
  void Fraction::safe_set() {
    nu = -1;
    de = 0;
  }

	// TODO: implement the max query
  int Fraction::max() const {
    int greater = (nu >= de ? nu : de);
    return greater;
  }

  // TODO: implement the min query
  int Fraction::min() const {
    int lesser = (nu <= de ? nu : de);
    return lesser;
  }

	// gcd returns the greatest common divisor of num and denom
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    void Fraction::reduce() {
      int g = gcd();
      nu /= g; //nu /= gcd(); is working on this line
      de /= g; //de /= gcd(); isn't working on this line. Because nu is already changed above
    }

    // TODO: implement the display query
    void Fraction::display() const {
      if ((nu > -1) && (de/gcd() > 1)) {
        cout << nu/gcd() << "/" << de/gcd();
      }
      else if ((nu > -1) && (de/gcd() == 1)) {
        cout << nu/de;
      }
      else if (nu < 0 || de < 1) {
        cout << "no fraction stored";
      }
    }

    // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const {
      bool empty;
      if (nu == -1 && de == 0)
        empty = true;
      else
        empty = false;

      return empty;
    }

    // TODO: implement the + operator
    Fraction Fraction::operator+ (const Fraction& rhs) const {
      Fraction this_copy = *this;
      if (this_copy.de == 0 || rhs.de == 0);
      else {
        this_copy.nu = ((this_copy.de) * (rhs.nu)) + ((this_copy.nu) * (rhs.de));
        this_copy.de *= rhs.de;
        this_copy.reduce();
      }
      return this_copy;
    }

    //implement the * operator
    Fraction Fraction::operator* (const Fraction& rhs) const {
      Fraction this_copy = *this;
      if (this_copy.de == 0 || rhs.de == 0);
      else {
        this_copy.nu *= rhs.nu;
        this_copy.de *= rhs.de;
        this_copy.reduce();
      }
      return this_copy;
    }

    //implement the == operator
    bool Fraction::operator== (const Fraction& rhs) const {
      bool same;
      Fraction this_copy = *this;
      Fraction rhs_copy = rhs;
      if (this_copy.de != 0 && rhs_copy.de != 0) {
        this_copy.reduce();
        rhs_copy.reduce();
        if ((this_copy.nu == rhs_copy.nu) && (this_copy.de == rhs_copy.de)) same = true;
        else same = false;
      }
      else same = false;
      
      return same;
    }

    //implement the != operator
    bool Fraction::operator!= (const Fraction& rhs) const {
      bool same;
      Fraction this_copy = *this;
      Fraction rhs_copy = rhs;
      if (this_copy.de != 0 && rhs_copy.de != 0) {
        this_copy.reduce();
        rhs_copy.reduce();
        if ((this_copy.nu == rhs_copy.nu) && (this_copy.de == rhs_copy.de)) same = false;
        else same = true;
      }
      else same = false;

      return same;
    }

    //implement the += operator
    Fraction& Fraction::operator+= (const Fraction& rhs) {
      if (this->de == 0 || rhs.de == 0);
      else {
        this->nu = ((this->de) * (rhs.nu)) + ((this->nu) * (rhs.de));
        this->de *= rhs.de;
        this->reduce();
      }
      return *this;
    }
}