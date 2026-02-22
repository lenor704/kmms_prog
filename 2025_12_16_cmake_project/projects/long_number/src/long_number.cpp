#include "long_number.hpp"

using ule::LongNumber;
		
LongNumber::LongNumber() {
	length = 1;
	sign = 1;
	numbers = new int[length];
	numbers[0] = 0;
}

LongNumber::LongNumber(int length, int sign) : length(length), sign(sign) {
	for (int i = 0; i < length; i++) {
		numbers[i] = 0;
	}
}

LongNumber::LongNumber(const char* const str) {
	int str_length = get_length(str);
	int start = 0;
	
	if (str[0] == '-') {
		sign = -1;
		length = str_length - 1;
		int start = 1;
	} else {
		sign = 1;
		length = str_length;
	}
	
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[i + start];
	}
}

LongNumber::LongNumber(const LongNumber& x) { // конструктор копирования
	length = x.length;
	sign = x.sign;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) { // конструктор перемещения
	length = x.length;
	sign = x.sign;
	numbers = x.numbers;
	x.numbers = nullptr;
}

LongNumber::~LongNumber() {
	length = 0;
	delete[] numbers;
	numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str) { // оператор присваивания
	int str_length = get_length(str);
	int start = 0;
	if (str[0] == '-') {
		sign = -1;
		length = str_length - 1;
		start = 1;
	} else {
		sign = 1;
		length = str_length;
	}
	
	delete[] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[i + start];
	}
	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) { // оператор присваивания копирования
	if (&x != this) {
		length = x.length;
		sign = x.sign;
		delete[] numbers;
		numbers = new int[length];
		for (int i = 0; i < length; i++) {
			numbers[i] = x.numbers[i];
		}
	}
	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) { // оператор присваивания перемещения
	if (&x != this) {
		delete[] numbers;
		length = x.length;
		sign = x.sign;
		numbers = x.numbers;
		x.numbers = nullptr;
	}
	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (x.length != length or x.sign != x.sign) {
		return false;
	} else {
		for (int i = 0; i < length; i++) {
			if (x.numbers[i] != numbers[i]) {
				return false;
			}
		}
		return true;
	}		
}

bool LongNumber::operator != (const LongNumber& x) const {
	return !(*this == x);
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (sign != x.sign) {
		return sign > x.sign;
	} else if (sign > 0) {
		if (length != x.length) {
			return length > x.length;
		} else {
			for (int i = 0; i < length; i++) {
				if (numbers[i] > x.numbers[i]) {
					return true;
				} else if (numbers[i] < x.numbers[i]) {
					return false;
				}
			}
		} 
	} else {
		if (length != x.length) {
			return length < x.length;
		} else {
			for (int i = 0; i <= length; i++) {
				if (numbers[i] < x.numbers[i]) {
					return true;
				} else if (numbers[i] > x.numbers[i]) {
					return false;
				}
			}
			
		}
	}
	return false;
}

bool LongNumber::operator < (const LongNumber& x) const {
	return !(*this > x || *this == x);
}


// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	
	return length;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace ule {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		if (x.sign == -1) {
			os << '-';
		}
		for (int i = 0; i < x.length; i++) {
			os << x.numbers[i];
		}
		return os;
	}
}