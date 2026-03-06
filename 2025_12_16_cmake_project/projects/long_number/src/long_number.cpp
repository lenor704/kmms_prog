#include "long_number.hpp"

using ule::LongNumber;
		
LongNumber::LongNumber() {
	length = 1;
	sign = 1;
	numbers = new int[length];
	numbers[0] = 0;
}

LongNumber::LongNumber(int length, int sign) : length(length), sign(sign) {
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = 0;
	}
}

LongNumber::LongNumber(const char* const str) {
	int str_length = get_length(str);
	sign = 1;
	length = str_length;
	int start = 0;
	
	if (str[0] == '-') {
		sign = -1;
		length -= 1;
		start += 1;
	}
	
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[i + start] - '0';
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
	sign = 1;
	length = str_length;
	int start = 0;
	
	if (str[0] == '-') {
		sign = -1;
		length -= 1;
		start += 1;
	}
	delete[] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[i + start] - '0';
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
			numbers[i] = x.numbers[i] - '0';
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
	if (x.length != length or x.sign != sign) {
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
			for (int i = 0; i < length; i++) {
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

LongNumber LongNumber::operator + (const LongNumber& x) const {
	if (x.abs() > this->abs()) {
		return x + *this;
    }
    LongNumber sum(length + 1, sign);
    int ost = 0;
    int prom = 0;
    int i = 1;
    while (i <= x.length or ost != 0) {
		if (i <= x.length) {
			prom = numbers[length - i] + x.numbers[x.length - i] * sign * x.sign + sign * x.sign * ost;
		} else if (ost != 0 and i <= length) {
			prom = numbers[length - i] + sign * x.sign * ost;
		} else {
			prom = ost;
		}
        
		if (prom < 0) {
			ost = 1;
			sum.numbers[sum.length - i] = 10 + prom;
		} else if (prom >= 10) {
			ost = 1;
			sum.numbers[sum.length - i] = prom % 10;
		} else {
			ost = 0;
			sum.numbers[sum.length - i] = prom;
		}
		i++;
	} 
	
	while (i <= length) {
		sum.numbers[sum.length - i] = numbers[length - i] + sign * ost;
		ost = 0;
		i++;
	}
	
	return sum.zero();
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	return *this + x * -1;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	if (x.length > length) {
		return x * *this;
	}
	LongNumber result(length + x.length, sign * x.sign);
	int prom = 0;
	int ost = 0;
	int ind;
	for (int i = 1; i <= x.length; i++) {
		ind = 0;
		for (int j = 1; j <= length; j++) {
			prom = numbers[length - j] * x.numbers[x.length - i] + ost; 
			result.numbers[result.length - j - i + 1] += prom % 10;
			if (result.numbers[result.length - j - i + 1] >= 10) {
				result.numbers[result.length - j - i + 1] = result.numbers[result.length - j - i + 1] % 10;
				prom += 10;
			}
			ost = prom / 10;
			ind++;
		}
		while (ost != 0) {
			prom = result.numbers[result.length - ind - i] + ost;
			result.numbers[result.length - ind - i] += prom % 10;
			ost = prom / 10;
			ind++;
		}
	}
	return result.zero();
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	LongNumber result(length, sign * x.sign);
	LongNumber delitel = x.abs();
	
	LongNumber prom = "0";
	int otv = 0;
	for (int i = 0; i < length; i++) {
		char a[2] = {char(numbers[i] + '0'), '\0'};
		prom = prom + LongNumber(a);
		while (prom > delitel - LongNumber("1")) {
			otv++;
			prom = prom - delitel;
		}
		result.numbers[i] = otv;
		otv = 0;
		prom = prom * LongNumber("10");
	}
	return result.zero();
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	LongNumber otv = *this - (*this / x) * x;
	if (otv.sign == -1) {
		return x + otv;
	}
	return otv;
}

bool LongNumber::is_negative() const noexcept {
	return sign == -1;
}

LongNumber LongNumber::abs() const {
	if (sign == -1) {
		return *this * -1;
	} else {
		return *this;
	}
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
LongNumber LongNumber::operator * (const int& x) const {
	LongNumber result = *this;
	if (x == -1) {
		result.sign = -1 * sign;
	}
	return result;
}

LongNumber LongNumber::zero() {
	int zeros = 0;
	int j = 0;
	while (numbers[j] == 0 and j + 1 < length) {
		zeros++;
		j++;
	}
	if (zeros == 0) {
		return *this;
	} else {
		LongNumber fin(length - zeros, sign);
		for (int i = 0; i < fin.length; i++) {
			fin.numbers[i] = numbers[i + zeros];
		}
		if (fin.numbers[0] == 0) {
			fin.sign = 1;
		}
		return fin;
	}
}

int LongNumber::get_length(const char* const str) const noexcept {
	if (!str) return 0;
	
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