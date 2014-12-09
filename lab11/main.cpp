/******************************************************************************
Title: Custom String
Author: Gordon Zheng
Created on: 2014-12-09
Description:    Implements String class.  Limit 80 chars, including null
                terminator.
Usage: ./lab11
Build with: g++ main.cpp String.cpp -o lab11
Dependencies: String.h
******************************************************************************/

#include <iostream>
#include "String.h"

using namespace std;


int main() {
    String s1;
    String s2("Test string");
    String s3("A test string that is definitely going to be too long and should therefore be truncated.");

    cout << "s1        = " << s1.str() << endl;
    cout << "s1.size() = " << s1.size() << endl;
    cout << "s2        = " << s2.str() << endl;
    cout << "s2.size() = " << s2.size() << endl;
    cout << "s3        = " << s3.str() << endl;
    cout << "s3.size() = " << s3.size() << endl;
    cout << endl;

    s1.copy("Another test string");
    s2.copy("The fourth test string is fairly long, although just shy of being truncated.");
    s3.copy("Another test string that is definitely too long and should therefore be truncated.");

    cout << "s1        = " << s1.str() << endl;
    cout << "s1.size() = " << s1.size() << endl;
    cout << "s2        = " << s2.str() << endl;
    cout << "s2.size() = " << s2.size() << endl;
    cout << "s3        = " << s3.str() << endl;
    cout << "s3.size() = " << s3.size() << endl;
    cout << endl;

    s1.concat(": is still a string,\neven with a newline.");
    s2.concat("PART OF THIS WILL BE SEEN!");
    s3.concat("NONE OF THIS SHOULD BE SEEN!");

    cout << "s1        = " << s1.str() << endl;
    cout << "s1.size() = " << s1.size() << endl;
    cout << "s2        = " << s2.str() << endl;
    cout << "s2.size() = " << s2.size() << endl;
    cout << "s3        = " << s3.str() << endl;
    cout << "s3.size() = " << s3.size() << endl;
    cout << endl;

    s1.copy("Final s1 string.");
    s2 = String("Final s2 string.");
    s3 = String();
    s3.concat("Final ");
    s3.concat("s3 ");
    s3.concat("string.");

    cout << "s1        = " << s1.str() << endl;
    cout << "s1.size() = " << s1.size() << endl;
    cout << "s2        = " << s2.str() << endl;
    cout << "s2.size() = " << s2.size() << endl;
    cout << "s3        = " << s3.str() << endl;
    cout << "s3.size() = " << s3.size() << endl;
    cout << endl;

    return 0;
}


/* The expected output:

    s1        =
    s1.size() = 0
    s2        = Test string
    s2.size() = 11
    s3        = A test string that is definitely going to be too long and should therefore be t
    s3.size() = 79

    s1        = Another test string
    s1.size() = 19
    s2        = The fourth test string is fairly long, although just shy of being truncated.
    s2.size() = 76
    s3        = Another test string that is definitely too long and should therefore be truncat
    s3.size() = 79

    s1        = Another test string: is still a string,
    even with a newline.
    s1.size() = 60
    s2        = The fourth test string is fairly long, although just shy of being truncated.PAR
    s2.size() = 79
    s3        = Another test string that is definitely too long and should therefore be truncat
    s3.size() = 79

    s1        = Final s1 string.
    s1.size() = 16
    s2        = Final s2 string.
    s2.size() = 16
    s3        = Final s3 string.
    s3.size() = 16

*/
