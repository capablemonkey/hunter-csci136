/******************************************************************************
Title: Raiser
Author: Gordon Zheng
Created on: 2014-09-08
Description: Given an employee's current salary, calculate their new salary
after a pay raise, and their 6-month retroactive payment (based on tiers of
pay increase rates)
Usage: ./lab02
Build with: g++ lab02.cpp -o lab02
Dependencies: none
******************************************************************************/

#include <iostream>
using namespace std;

const float RAISE_RATE_TIER_1 = 1.082;
const float RAISE_RATE_TIER_2 = 1.049;
const float RETRO_RATE_TIER_2 = 1.054;
const float RAISE_RATE_TIER_3 = 1.033;

int main() {
  float currentSalary, retroPayment, newSalary;

  // Prompt user for input

  cout << "What's your current salary? $";
  cin >> currentSalary;

  // Calculate new salary and retro pay

  if (currentSalary <= 25000.00) {
    newSalary = currentSalary * RAISE_RATE_TIER_1;
    // difference in yearly salary, divided by 2 (6 mo. retro):
    retroPayment = (newSalary - currentSalary) / 2;
  } else if (currentSalary <= 30000.00) {
    newSalary = currentSalary * RAISE_RATE_TIER_2;
    // use special retro rate instead of new salary to calculate retro payment:
    retroPayment = ((currentSalary * RETRO_RATE_TIER_2) - currentSalary) / 2;
  } else if (currentSalary <= 40000.00) {
    newSalary = currentSalary * RAISE_RATE_TIER_3;
    // difference in yearly salary, divided by 2 (6 mo. retro):
    retroPayment = (newSalary - currentSalary) / 2;
  } else {
    // No raise.
    newSalary = currentSalary;
    retroPayment = 0;
  }

  // Report results:

  if (newSalary == currentSalary && retroPayment == 0) {
    cout << "Well, this is awkward.  Guess what?  You don't get a salary raise!";
  } else {
    cout.precision(2);    // round to 2 digits
    cout << "Retroactive pay: $" << fixed << retroPayment << endl
         << "New salary: $" << fixed << newSalary << endl
         << "Monthly salary: $" << fixed << (newSalary / 12) << endl;
  }

  return 0;
}