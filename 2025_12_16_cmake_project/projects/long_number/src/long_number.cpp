#include "long_number.hpp"

using ule::LongNumber;
		
LongNumber::LongNumber() {
	length = 1;
	sign = 1;
	numbers = new int[length];
	numbers[0] = 0;
	//std::cout << "конструктор 0" << std::endl;
}

LongNumber::LongNumber(int length, int sign) : length(length), sign(sign) {
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = 0;
	}
	//std::cout << "конструктор без значения" << std::endl;
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
	//std::cout << "кк" << std::endl;
}

LongNumber::LongNumber(LongNumber&& x) { // конструктор перемещения
	length = x.length;
	sign = x.sign;
	numbers = x.numbers;
	x.numbers = nullptr;
	//std::cout << "кп" << std::endl;
}

LongNumber::~LongNumber() {
	//std::cout << "~" << std::endl;
	length = 0;
	delete[] numbers;
	numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str) { // оператор присваивания
	delete[] numbers;
	this->sign = LongNumber(str).sign;
	this->length = LongNumber(str).length;
	this->numbers =LongNumber(str).numbers;
	//std::cout << "=" << std::endl;
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
	//std::cout << "Присвоение копирование" << std::endl;
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
	//std::cout << "присвоение перемещение" << std::endl;
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
	
	int zero = 0;
	int j = 0;
	while (sum.numbers[j] == 0 and j + 1 < sum.length) {
		zero++;
		j++;
	}
	if (zero == 0) {
		return sum;
	} else {
		LongNumber fin_sum(sum.length - zero, sum.sign);
		for (int i = 0; i < fin_sum.length; i++) {
			fin_sum.numbers[i] = sum.numbers[i + zero];
		}
		if (fin_sum.numbers[0] == 0) {
			fin_sum.sign = 1;
		}
		return fin_sum;
	}
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	return *this + x * -1;
}

LongNumber LongNumber::operator * (const int& x) const {
	LongNumber result = *this;
	if (x == -1) {
		result.sign = -1 * sign;
	}
	return result;
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
int LongNumber::get_length(const char* const str) const noexcept {
	if (!str) return 0;
	
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	//std::cout << length << std::endl;
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