#ifndef __FRACTION_HPP__
#define __FRACTION_HPP__

#include <iostream>
#include <exception>
#include <list>
#include <utility>

//Thrown if divisor is zero
class DivideByZero: public std::exception{
	virtual const char *what() const throw(){
		return "Divisor is 0";
	}
};

class Fraction{
	int num, den;
	std::list<int> num_factors, den_factors;
protected:
	Fraction(const int numerator, const int denominator,
		const std::list<int> numerator_factors,
		const std::list<int> denominator_factors);
	//Initializes both numerator and denominator factors list;
	void get_factors();
	//Returns (true, n) if n is prime else (false, factor)
	const std::pair<bool,int> is_prime(const int &n) const;
	//Returns the next prime after n
	const int &get_next_prime(int &n) const;
	//Returns a list of prime factors given a number
	const std::list<int> factor(int n) const;
	//Makes the fraction into lowest terms
	void lowest_terms();
public:
	Fraction();
	Fraction(const int numerator, const int denominator);
	Fraction(const std::pair<int, int> n);
	Fraction(const double n, const int sig=6);
	~Fraction();
	//Returns (numerator, denominator)
	const std::pair<int, int> GetFraction() const;
	//Returns numerator
	const int Numerator();
	const int &Numerator() const;
	//Returns denominator
	const int Denominator();
	const int &Denominator() const;
	//Returns numerator's factors
	const std::list<int> NumeratorFactors() const;
	//const std::list<int> &NumeratorFactors() const;
	//Returns denominator's factors
	const std::list<int> DenominatorFactors() const;
	//const std::list<int> &DenominatorFactors() const;
	//Mathematical operators
	//With other Fractions:
	const Fraction operator + (const Fraction &param) const;
	const Fraction operator - (const Fraction &param) const;
	const Fraction operator - () const; //negation
	const Fraction operator * (const Fraction &param) const;
	const Fraction operator / (const Fraction &param) const;
	const Fraction operator = (const Fraction &param);
	const bool operator < (const Fraction &param) const;
	const bool operator > (const Fraction &param) const;
	const Fraction operator += (const Fraction &param);
	const Fraction operator -= (const Fraction &param);
	const Fraction operator *= (const Fraction &param);
	const Fraction operator /= (const Fraction &param);
	const bool operator == (const Fraction &param) const;
	const bool operator != (const Fraction &param) const;
	const bool operator <= (const Fraction &param) const;
	const bool operator >= (const Fraction &param) const;
	//With doubles:
	const Fraction operator + (const double param) const;
	const Fraction operator - (const double param) const;
	const Fraction operator * (const double param) const;
	const Fraction operator / (const double param) const;
	const Fraction operator = (const double param);
	const bool operator < (const double param) const;
	const bool operator > (const double param) const;
	const Fraction operator += (const double param);
	const Fraction operator -= (const double param);
	const Fraction operator *= (const double param);
	const Fraction operator /= (const double param);
	const bool operator == (const double param) const;
	const bool operator != (const double param) const;
	const bool operator <= (const double param) const;
	const bool operator >= (const double param) const;
	//Output operators
	friend std::ostream &operator << (std::ostream &os, const Fraction &param);
};

#endif