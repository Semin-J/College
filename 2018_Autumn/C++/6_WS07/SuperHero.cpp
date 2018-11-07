// Name: Semin Jeon
// Student number: 
// email: semini93@gmail.com
// Date: 2018/11/06

#include <iostream>
#include <cstring>
#include "SuperHero.h"

using namespace std;
namespace sict {
  // Constructors
  SuperHero::SuperHero() {
    safeEmpty();
  }
  SuperHero::SuperHero(const char* name_src, int health_src, int strength_src, int bonus_src, int defend_src)
  : Hero(name_src, health_src, strength_src) {
    if (m_health != 0 && m_strength != 0) { //base class con first?-YES!
      if (bonus_src > 0) {
        m_bonus = bonus_src;
        if (defend_src > 0)
          m_defend = defend_src;
        else safeEmpty();
      }
      else safeEmpty();
    }
    else safeEmpty();
  }

  // Destructor
  SuperHero::~SuperHero() {}

  // Member functions
  void SuperHero::safeEmpty() {// Overriding
    Hero::safeEmpty();
    m_bonus = 0;
    m_defend = 0;
  }
  int SuperHero::attackStrength() const {// Overriding
    return m_strength + m_bonus;
  }

  int SuperHero::defend() const {
    return m_defend;
  }

  //helper operators
  const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {// Overloading
    int round1 = 0; int round2 = 0;
    SuperHero tmp1 = first;
    SuperHero tmp2 = second;
    int damage1 = tmp2.attackStrength() - tmp1.defend();
    int damage2 = tmp1.attackStrength() - tmp2.defend();
    int valid = 0;
    while (valid < MAX_ROUNDS) {
      tmp1 -= damage1;
      round1++;
      if (tmp1.isAlive() == false)
        valid = MAX_ROUNDS;
    }

    valid = 0;
    while (valid < MAX_ROUNDS) {
      tmp2 -= damage2;
      round2++;
      if (tmp2.isAlive() == false)
        valid = MAX_ROUNDS;
    }


    const SuperHero *tmp = (round1 <= round2 ? &second : &first);
    int round = (round1 <= round2 ? round1 : round2);

    cout << "Super Fight! " << tmp1.showName() << " vs " << tmp2.showName()
      << " : Winner is " << tmp->showName() << " in " << round << " rounds." << endl;
    return *tmp;
  }
}