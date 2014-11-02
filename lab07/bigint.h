// include guards
#ifndef BIG_INT_H
#define BIG_INT_H

#include <iostream>
#include <algorithm>

/** addBigIntegers(num1, num1_size, num2, num2_size, result_num)
* @desc adds the number represented by the arrays using long addition,
* placing the result into result_array
* @param int num1[] [in/out] – a number stored as an array
* @param int num1_size [in] - the # of digits in the first number
* @param int num2[] [in/out] – a second number stored as an array
* @param int num2_size [in] - the # of digits in the second number
* @param int result_num[] [in/out] – an array to store the result number
* @pre declared size of result_num is > max(num1_size, num2_size)
* @post the number representing the sum of num1 and num2 is stored in
* the result_num array
* @post the digits in num1, num2 and result_num are in proper order
* @return the number of digits in result_num array
**/

int addBigIntegers(int num1[], int num1_size, int num2[], int num2_size, int result_num[]);


/** printBigInteger(outputstream, num, size)
* @desc prints the number represented by the digits in the num array
* to the output stream
* @param ostream & outputstream [in/out] - the stream to write to
* @param int num[] [in/out] - the number to print as an array
* @param int size [in] - the size of the array
* @pre outputstream is open for writing
* @post the digits in num have been written to the output stream
* @return none
**/

void printBigInteger(std::ostream &outputstream, int num[], int size);


/** reverseArray(array, size)
* @desc reverses the elements in an array
* @param int array[] [in/out] – the array to reverse the elements of
* @param int size [in] - the used size of the array
* @pre none
* @post the first element is now the last and the last is now the first;
* the second element is now the second to last...
* @return none
**/

void reverseArray(int array[], int size);

#endif