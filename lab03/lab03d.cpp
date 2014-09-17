/******************************************************************************
Title: Sum of digits
Author: Gordon Zheng
Created on: 2014-09-16
Description: Prints the sum of digits of all number between 0 and 200.
Usage: ./lab03d
Build with: g++ lab03d.cpp -o lab03d
Dependencies: none
******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

// define prototypes
int sumOfDigits(int n);
int lengthOfInteger(int n);

int main() {
	int sum = 0;

	for (int x = 0; x <= 200; x++) {
		sum += sumOfDigits(x);
	}

	cout << "Sum of digits of all numbers between 0 and 200: " << sum << endl;

	return 0;
}

// given an integer n, return the sum of the digits of n
int sumOfDigits(int n) {
	int sum = 0;
	int digit;

	// keep dividing n by 10^x, where x is the number of orders of magnitude of n.
	// the result is the value of the digit at that order of magnitude. 
	// decrement x in each iteration
	for (int x = lengthOfInteger(n) - 1; x >= 0; x--) {
		if (x == 0) {
			sum += (n % 10);
		} else {
			digit = n / pow(10, x);
			n = n % int(pow(10, x));
			sum += digit;
		}
	}

	return sum;
}

// given an integer n, return the number of digits in n
int lengthOfInteger(int n) {
	int digits = 0;
	int num = n;

	if (num == 0) return 1;

	for (digits = 0; num > 0; digits++) {
		num = num / 10;	
	}

	return digits;
}