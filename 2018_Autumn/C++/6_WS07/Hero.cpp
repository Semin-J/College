// Name: Semin Jeon
// Student number: 
// email: semini93@gmail.com
// Date: 2018/11/06

#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace sict {
  // Set safe empty state of data members
  void Hero::safeEmpty() {
    m_name[0] = '\0';
    m_health = 0;
    m_strength = 0;
  }

  // Constructors
  Hero::Hero() {
    safeEmpty();
  }

  Hero::Hero(const char* name_src, int health_src, int strength_src) {
    strncpy(m_name, name_src, MAX_CHAR);
    m_name[MAX_CHAR] = '\0';
    if (health_src > 0) {
      m_health = health_src;
      if (strength_src > 0) {
        m_strength = strength_src;
      }
      else safeEmpty();
    }
    else safeEmpty();
  }

  // Destructor
  Hero::~Hero() {}

  // Member functions, operator
  const char* Hero::showName() const {
    return m_name;
  }

  bool Hero::isAlive() const {
    bool healthy = (m_health > 0 ? true : false);
    return healthy;
  }

  int Hero::attackStrength() const {
    return m_strength;
  }


  void Hero::operator-=(int attack) {
    if (m_health > 0 && attack > 0) {
      int deducted = m_health - attack;
      if (deducted > 0)
        m_health = deducted;
      else
        m_health = 0;
    }
  }


  //friend operator (friend keyword is only for prototype)
  std::ostream& operator<<(std::ostream& os, const Hero& hero_src) {
    if (hero_src.m_name[0] != '\0')
      os << hero_src.m_name << endl;
    else
      os << "No hero" << endl;

    return os;
  }

  //helper operators
  const Hero& operator*(const Hero& first, const Hero& second) {
    int round1 = 0; int round2 = 0;
    Hero tmp1 = first;
    Hero tmp2 = second;
    int valid = 0;
    while (valid < MAX_ROUNDS) {
        tmp1 -= tmp2.attackStrength();
        round1++;
        if (tmp1.isAlive() == false)
          valid = MAX_ROUNDS;
    }

    valid = 0;
    while (valid < MAX_ROUNDS) {
        tmp2 -= tmp1.attackStrength();
        round2++;
        if (tmp2.isAlive() == false)
          valid = MAX_ROUNDS;
    }


    const Hero *tmp = (round1 <= round2 ? &second : &first);
    int round = (round1 <= round2 ? round1 : round2);

    cout << "Ancient Battle! " << tmp1.showName() << " vs " << tmp2.showName()
      << " : Winner is " << tmp->showName() << " in " << round << " rounds." << endl;
    return *tmp;
    
  }

}