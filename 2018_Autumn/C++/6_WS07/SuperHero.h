// Name: Semin Jeon
// Student number: 
// email: semini93@gmail.com
// Date: 2018/11/06

#ifndef SUPER_HERO_H_
#define SUPER_HERO_H_
#include "Hero.h"

namespace sict {
  class SuperHero : public Hero {
  protected:
    int m_bonus; // bonus attack strength to superhero
    int m_defend; //defend strength
    void safeEmpty(); // Overriding
  public:
    // Constructors
    SuperHero();
    SuperHero(const char*, int, int, int, int);
    // Destructor
    ~SuperHero();
    // Member functions
    int attackStrength() const; // Overriding
    int defend() const;
  };
  //helper operators
  const SuperHero& operator*(const SuperHero&, const SuperHero&);
}
#endif //SUPER_HERO_H_