#include "String.h"

String::String() {
	this->chars[0] = '\0';
	this->length = 0;
}

String::String(char input[]) {
	this->copy(input);
}

void String::copy(char input[]) {
	for (this->length = 0; this->length < 79; this->length++) {
		if (input[this->length] == '\0') { break; }

		this->chars[this->length] = input[this->length];
	}

	this->chars[this->length] = '\0';
}

void String::concat(char input[]) {
	int indexInput = 0;
	for (this->length; this->length < 79; this->length++) {
		if (input[indexInput] == '\0') { break; }

		this->chars[this->length] = input[indexInput];
		indexInput++;
	}

	this->chars[this->length] = '\0';
}

const char* String::str() const {
	return this->chars;
}

int String::size() const {
	return this->length;
};