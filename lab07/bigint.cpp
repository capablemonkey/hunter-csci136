#include "bigint.h"

void printBigInteger(std::ostream &outputstream, int num[], int size) {
	for (int index = 0; index < size; index++) {
		outputstream << num[index];
	}

	outputstream << std::endl;
}

void reverseArray(int array[], int size) {
	std::reverse(&array[0], &array[size]);
}

int addBigIntegers(int num1[], int num1Size, int num2[], int num2Size, int numResult[]) {
	// reverse num1 and num2
	reverseArray(num1, num1Size);
	reverseArray(num2, num2Size);

	// figure out which of num1 or num2 has the most digits:
	int biggerSize = (num1Size > num2Size) ? num1Size : num2Size;

	// values temporarily held in these variables for calculation:
	int a, b;
	int carryDigit = 0;

	for (int index = 0; index < biggerSize; index++) {
		// if there is no digit at the current index for num1 or num2, use 0:
		a = (index < num1Size) ? num1[index] : 0;
		b = (index < num2Size) ? num2[index] : 0;

		numResult[index] = (a + b + carryDigit) % 10;

		// set carry digit:
		if (a + b + carryDigit >= 10) { carryDigit = 1; }
		else { carryDigit = 0; }
	}

	int resultSize;

	// if there's a carry digit, tack it on at the end of numResult[]
	if (carryDigit > 0) {
		numResult[biggerSize] = carryDigit;
		resultSize = biggerSize + 1;
	} else {
		resultSize = biggerSize;
	}

	// put arrays back in their original order:
	reverseArray(num1, num1Size);
	reverseArray(num2, num2Size);
	reverseArray(numResult, resultSize);

	return resultSize;
}