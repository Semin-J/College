// Name: Semin Jeon
// Student number: 
// email: semini93@gmail.com
// Date: 2018/11/06

#ifndef HERO_H_
#define HERO_H_
namespace sict {
  class Hero {
  protected:
    #define MAX_CHAR 40
    #define MAX_ROUNDS 100
    char m_name[MAX_CHAR + 1];
    int m_health;
    int m_strength;
    void safeEmpty();
  public:
    // Constructors
    Hero();
    Hero(const char*, int, int);
    // Destructor
    ~Hero();
    // Member functions, operator
    const char* showName() const;
    bool isAlive() const;
    int attackStrength() const;
    void operator-=(int);
    friend std::ostream& operator<<(std::ostream&, const Hero&);
  };

  //helper operators
  const Hero& operator*(const Hero&, const Hero&);

}
#endif //HERO_H_
