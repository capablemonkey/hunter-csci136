/******************************************************************************
Title: Number Multiplier
Author: Gordon Zheng
Created on: 2014-09-02
Description: Asks for 2 numbers and multiplies them.
Usage: ./lab01c
Build with: g++ lab01c.cpp -o lab01c
Dependencies: none
******************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int a, b;

	cout << "Give me a number: ";
	cin >> a;
	cout << "Give me another one: "; 
	cin >> b;

	cout << "Product: " << a * b << endl;
	return 0;
}