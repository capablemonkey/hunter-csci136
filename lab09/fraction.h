#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <ostream>
#include <cstdlib>

class Fraction {
	private:
		int numerator, denominator;

	public:
		Fraction();
		Fraction(int numerator, int denominator);

		Fraction sumWith(const Fraction otherFraction) const;
		Fraction multiplyWith(const Fraction otherFraction) const;
		void print(std::ostream &out) const;
		void simplify();
};

#endif