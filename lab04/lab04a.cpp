/******************************************************************************
Title: Investment Calculator
Author: Gordon Zheng
Created on: 2014-09-16
Description: Open lab04a-data.txt, computes the expected future value of 
  each investment account
Usage: ./lab04a
Build with: g++ lab04a.cpp -o lab04a
Dependencies: none
******************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

const float ANNUAL_INTEREST_RATE = 0.06;

float computeFutureValue(float accountBalance, int periodsPerYear, int years);

int main() {
  ifstream accountsFile("lab04a-data.txt");
  string line;

  // make sure we have a good ifstream
  if (!accountsFile) {
    cout << "File 'lab04a-data.txt' could not be opened." << endl;
    return 1;
  }
  
  // iterate through lines of file
  while (getline(accountsFile, line)) {
    // use string stream to conveniently extract numbers:
    istringstream buffer(line);
    float accountBalance, futureValue;
    int periodsPerYear, years;

    // if the line can't be coerced to float, int, int, it's an invalid line
    // and we'll just stop here.
    if (!(buffer >> accountBalance >> periodsPerYear >> years)) { break; }

    // output floats to 2 decimal places, show point:
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // print future value:
    cout  << "$" << accountBalance << ", "
          << (ANNUAL_INTEREST_RATE * 100) << "% rate, "
          << "compounded " << periodsPerYear << " times a year "
          << "for " << years << " years yields: $"
          << computeFutureValue(accountBalance, periodsPerYear, years)
          << endl;
  }

  return 0;
}

float computeFutureValue(float accountBalance, int periodsPerYear, int years) {
  return accountBalance * (
    pow(1 + (ANNUAL_INTEREST_RATE / periodsPerYear), years * periodsPerYear));
}