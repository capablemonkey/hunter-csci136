/******************************************************************************
Title: Fibonacci
Author: Gordon Zheng
Created on: 2014-10-09
Description: 	Calulates Fibonacci sequence iteratively up to P elements, where
							the P-th element is larger than the maximum int value.

							Computes the Fibonacci sequence only once and stores it in a 
							vector in order to avoid having to compute the sequence each time 
							to calculate the value of P, as well as to generate the actual 
							sequence in the output.
							
Usage: ./lab05
Build with: g++ lab05.cpp -o lab05
Dependencies: none
******************************************************************************/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Prototypes
vector<int> generateFibonacci(void);
int fib(int n);

// Constants
const int MAXINTVAL = numeric_limits<int>::max();
const vector<int> FIBONACCI_SEQUENCE = generateFibonacci();
const int MAX_POSITION = FIBONACCI_SEQUENCE.size();

int main() {
	cout << "Fibonacci sequence generator." << endl;
	
	// Fetch user specified position
	int positions = -1;
	while (positions < 1 || positions > MAX_POSITION) {
		cout << "How many positions of the sequence should I display: ";

		cin >> positions;

		if (positions < 1 || positions > MAX_POSITION) {
			cout << endl << "Sorry, I can only generate the sequence for positions 1-" 
				 << MAX_POSITION << endl;
		}
	}

	// print sequence up to user specified position
	for (int i=1; i <= positions; i++) {
		cout << fib(i) << " ";
	}

	cout << endl;
	return 0;
}

// Returns the n-th Fibonacci number
int fib(int n) {
	return FIBONACCI_SEQUENCE[n - 1];
}

// returns a vector containing the Fibonacci sequence up to P elements,
// where the P-th element is larger than the maximum int value.
vector<int> generateFibonacci(void) {
	vector<int> sequence;

	sequence.push_back(0);
	sequence.push_back(1);
	
	for (int current = 2; current < MAXINTVAL; current++) {
		if (float(sequence[current - 1]) + sequence[current - 2] > MAXINTVAL) {
			break;
		}

		sequence.push_back(sequence[current - 1] + sequence[current - 2]);
	}

	return sequence;
}