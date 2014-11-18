/******************************************************************************
Title: Fractions
Author: Gordon Zheng
Created on: 2014-11-16
Description:    Implements rational fraction math  
Usage: ./lab09
Build with: g++ lab09.cpp fraction.cpp -o lab09
Dependencies: fraction.h
******************************************************************************/


#include <iostream>
#include "fraction.h"

using namespace std;

void outputExpression(ostream & out,
                      const Fraction & num1,
                      const Fraction & num2,
                      const Fraction & result,
                      bool isSum);

int main() {
    Fraction num1, num2, result;

    num1 = Fraction(1, 0);
    num2 = Fraction(2, 3);
    result = num1.sumWith(num2);
    outputExpression(cout, num1, num2, result, true);
    result = num1.multiplyWith(num2);
    outputExpression(cout, num1, num2, result, false);
    cout << endl;

    num1 = Fraction(-1, 2);
    num2 = Fraction(-2, 6);
    result = num1.sumWith(num2);
    outputExpression(cout, num1, num2, result, true);
    result = num1.multiplyWith(num2);
    outputExpression(cout, num1, num2, result, false);
    cout << endl;

    num1 = Fraction(-1, -2);
    num2 = Fraction(3, -5);
    result = num1.sumWith(num2);
    outputExpression(cout, num1, num2, result, true);
    result = num1.multiplyWith(num2);
    outputExpression(cout, num1, num2, result, false);
    cout << endl;

    num1 = Fraction(3, 5);
    num2 = Fraction(2, 5);
    result = num1.sumWith(num2);
    outputExpression(cout, num1, num2, result, true);
    result = num1.multiplyWith(num2);
    outputExpression(cout, num1, num2, result, false);

    return 0;
}

void outputExpression(ostream & out,
                      const Fraction & num1,
                      const Fraction & num2,
                      const Fraction & result,
                      bool isSum)
{
    num1.print(out);
    if (isSum) {
        out << " + ";
    } else {
        out << " * ";
    }
    num2.print(out);
    out << " = ";
    result.print(out);
    out << endl;
}

/* The expected output:

    1/2 + 2/3 = 7/6
    1/2 * 2/3 = 2/6

    -1/2 + -2/6 = -10/12
    -1/2 * -2/6 = 2/12

    1/2 + -3/5 = -1/10
    1/2 * -3/5 = -3/10

    3/5 + 2/5 = 25/25
    3/5 * 2/5 = 6/25

    ===================

    If you're doing the extra credit member function simplify, then
    the expected output would be:

    1/2 + 2/3 = 7/6
    1/2 * 2/3 = 1/3

    -1/2 + -1/3 = -5/6
    -1/2 * -1/3 = 1/6

    1/2 + -3/5 = -1/10
    1/2 * -3/5 = -3/10

    3/5 + 2/5 = 1/1
    3/5 * 2/5 = 6/25

*/
