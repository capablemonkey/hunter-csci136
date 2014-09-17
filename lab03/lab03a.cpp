/******************************************************************************
Title: Guess!
Author: Gordon Zheng
Created on: 2014-09-16
Description: Asks the user to guess the number I'm thinking of. 
  This game gets old fast.
Usage: ./lab03a
Build with: g++ lab03a.cpp -o lab03a
Dependencies: none
******************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int num = 4, input = 0;

	cout << "I'm thinking of a number between 1 and 5, inclusive.  What is it?" << endl;

	while (input != num) {
		cout << "Guess: ";
		cin >> input;
	}

	cout << "That was it!  You win!" << endl;

	return 0;
}