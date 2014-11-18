#include "fraction.h"

Fraction::Fraction() {
	numerator = 1;
	denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
	// check if denominator is valid:
	if (denominator == 0) { 
		std::cerr << "FATAL: Denominator must not be negative or 0." << std::endl; 
		// throw "Oh no!";
		std::exit(1);
	}

	// if denominator is negative, make it positive and change the sign of the numerator:
	if (denominator < 0) { 
		denominator = denominator * -1;
		numerator = numerator * -1;
	}

	this->numerator = numerator;
	this->denominator = denominator;

	this->simplify();
}

// multiply denominators to find common denominator
// multiply each numerator by the other and add
Fraction Fraction::sumWith(const Fraction otherFraction) const {
	int commonDenominator = this->denominator * otherFraction.denominator;
	int sumNumerator = (this->numerator * otherFraction.denominator + 
											otherFraction.numerator * this->denominator);

	return Fraction(sumNumerator, commonDenominator);
}

// multiply denominators to find common denominator
// multiply numerators by the other to find product numerator
Fraction Fraction::multiplyWith(const Fraction otherFraction) const {
	int commonDenominator = this->denominator * otherFraction.denominator;
	int productNumerator = this->numerator * otherFraction.numerator;

	return Fraction(productNumerator, commonDenominator);
}

void Fraction::print(std::ostream &out) const {
	out << numerator << "/" << denominator;
	return;
}

// Find the greatest common factor for the fraction and divide
// numerator and denominator by it.
void Fraction::simplify() {
	for (int i = std::abs(this->numerator); i > 1; i--) {
		if (this->numerator % i == 0 && this->denominator % i == 0) {
			this->numerator = this->numerator / i;
			this->denominator = this->denominator / i;
			break;
		}
	}

	return;
}