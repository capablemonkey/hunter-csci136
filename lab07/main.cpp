#include <iostream>
#include "bigint.h"

using namespace std;

int main() {
    const int MAX_SIZE = 20;
    int num1a_size = 15,
        num1b_size = 15,
        num2a_size = 12,
        num2b_size = 8,
        num3a_size = 8,
        num3b_size = 12,
        result_size;

    // the number 999,999,999,999,999 with each digit stored as array element
    int num1a[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

    // the number 123,456,789,012,345 with each digit stored as array element
    int num1b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5};

    // the number 123,123,123,123 with each digit stored as array element
    int num2a[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};

    // the number 12,345,678 with each digit stored as array element
    int num2b[] = {1, 2, 3, 4, 5, 6, 7, 8};

    // the number 87,654,321 with each digit stored as array element
    int num3a[] = {8, 7, 6, 5, 4, 3, 2, 1};

    // the number 321,321,321,321 with each digit stored as array element
    int num3b[] = {3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1};

    int result[MAX_SIZE];

    result_size = addBigIntegers(num1a, num1a_size, num1b, num1b_size, result);
    printBigInteger(cout, num1a, num1a_size);
    cout << "plus" << endl;
    printBigInteger(cout, num1b, num1b_size);
    cout << "equals" << endl;
    printBigInteger(cout, result, result_size);

    cout << endl;

    result_size = addBigIntegers(num2a, num2a_size, num2b, num2b_size, result);
    printBigInteger(cout, num2a, num2a_size);
    cout << "plus" << endl;
    printBigInteger(cout, num2b, num2b_size);
    cout << "equals" << endl;
    printBigInteger(cout, result, result_size);

    cout << endl;

    result_size = addBigIntegers(num3a, num3a_size, num3b, num3b_size, result);
    printBigInteger(cout, num3a, num3a_size);
    cout << "plus" << endl;
    printBigInteger(cout, num3b, num3b_size);
    cout << "equals" << endl;
    printBigInteger(cout, result, result_size);

    return 0;
}

/* The expected output:

    999999999999999
    plus
    123456789012345
    equals
    1123456789012344

    123123123123
    plus
    12345678
    equals
    123135468801

    87654321
    plus
    321321321321
    equals
    321408975642

*/