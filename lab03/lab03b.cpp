/******************************************************************************
Title: Enumerate Primes
Author: Gordon Zheng
Created on: 2014-09-16
Description: Prints the prime numbers between 3 and 100.  
	Generates primes naively.
Usage: ./lab03b
Build with: g++ lab03b.cpp -o lab03b
Dependencies: none
******************************************************************************/

#include <iostream>
using namespace std;

int main() {
	for (int n = 3; n < 100; n++) {
		bool isPrime = true;

		for (int t = 2; t < n / 2; t++) {
			if (n % t == 0) isPrime = false;
		}

		if (isPrime == true) cout << n << endl;
	}

	return 0;
}