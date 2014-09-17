/******************************************************************************
Title: Enumerate Primes
Author: Gordon Zheng
Created on: 2014-09-16
Description: Prints the prime numbers between 3 and 100.  
	Generates primes naively.  This time, break out prime checking into its own
	function.
Usage: ./lab03c
Build with: g++ lab03c.cpp -o lab03c
Dependencies: none
******************************************************************************/

#include <iostream>
using namespace std;

// define prototype
int isPrime(int n);

int main() {
	for (int n = 3; n < 100; n++) {
		if (isPrime(n)) cout << n << endl;
	}

	return 0;
}

// given a number n, check to see if it's prime; returns bool
int isPrime(int n) {
	bool isPrime = true;

	for (int t = 2; t < n / 2; t++) {
		if (n % t == 0) isPrime = false;
	}

	return isPrime;
}