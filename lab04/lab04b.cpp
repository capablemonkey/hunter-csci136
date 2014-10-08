/******************************************************************************
Title: Sort Numbers
Author: Gordon Zheng
Created on: 2014-09-16
Description: Open lab04b-data.txt, sort the numbers on each line in 
  ascending order
Usage: ./lab04b
Build with: g++ lab04b.cpp -o lab04b
Dependencies: none
******************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

void sortIntegers(int &num1, int &num2, int &num3);
void swap(int &num1, int &num2);

int main() {
  ifstream numbersFile("lab04b-data.txt");
  string line;

  // make sure we have a good ifstream
  if (!numbersFile) {
    cout << "File 'lab04b-data.txt' could not be opened." << endl;
    return 1;
  }
  
  // iterate through lines of file
  while (getline(numbersFile, line)) {
    // use string stream to conveniently extract numbers:
    istringstream buffer(line);
    int num1, num2, num3;

    // if the line can't be coerced to int, int, int, it's an invalid line
    // and we'll just stop here.
    if (!(buffer >> num1 >> num2 >> num3)) { break; }

    sortIntegers(num1, num2, num3);

    cout << num1 << " " << num2 << " " << num3 << endl;
  }

  return 0;
}

void sortIntegers(int &num1, int &num2, int &num3) {
  // dumb, hardcoded bubble sort, without arrays!
  if (num1 > num2) swap(num1, num2);
  if (num2 > num3) swap(num2, num3);
  if (num1 > num2) swap(num1, num2);
}

void swap(int &num1, int &num2) {
  // swap num1 and num2
  int buffer = num1;
  num1 = num2;
  num2 = buffer;

  return;
}