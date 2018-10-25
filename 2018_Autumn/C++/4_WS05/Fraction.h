//name: Semin Jeon
//WS05
//2018/10/13

// TODO: header file guard
#ifndef FRACTION_H
#define FRACTION_H

// TODO: create namespace
namespace sict{

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
    int nu; //numerator(above line)
    int de; //denominator(below line)
		// TODO: declare private member functions
    int max() const;
    int min() const;
    int gcd() const;
    void reduce();
	public:
		// TODO: declare public member functions
    Fraction();
    Fraction(int, int);
    void safe_set();
    bool isEmpty() const;
    void display() const;
		// TODO: declare the + operator overload
    Fraction operator+ (const Fraction&) const;
    Fraction operator* (const Fraction&) const;
    bool operator== (const Fraction&) const;
    bool operator!=(const Fraction&) const;
    Fraction& operator+= (const Fraction&);
	};
}
#endif // !FRACTION_H
