#include "long_number.hpp"
#include <cstring>
#include <iostream>

using dim::LongNumber;
		
LongNumber::LongNumber() {
	
	numbers = new int[1];
	
	numbers[0] = 0;
	
	length = 1;
	
	sign = 1;
}

LongNumber::LongNumber(int length, int sign) {
	
	this->length = length;
	this->sign = sign;
	
	numbers = new int[length];
	
	for (int i = 0; i < length; i++) {
		numbers[i] = 0;
	}
}

LongNumber::LongNumber(const char* const str) {
	
	int start = 0;
	
	if (str[0] == '-') {
		sign = -1;
		start = 1;
	} else {
		sign = 1;
		start = 0;
	}
	
	length = get_length(str + start);
	
	numbers = new int[length];
	
	for (int i = 0; i < length; i++) {
		numbers[i] = str[start + i] - '0';
	}
	
	if (length == 1 && numbers[0] == 0) {
		sign = 1;
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	length = x.length;
	sign = x.sign;
	
	numbers = new int[length];
	
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) {
	numbers = x.numbers;
	length = x.length;
	sign = x.sign;
	
	x.numbers = nullptr;
	x.length = 0;
	x.sign = 1;
	
	
}

LongNumber::~LongNumber() {
	
	delete[] numbers;
	
	numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str) {
	
	LongNumber temp(str);
	
	delete[] numbers;
	
	length = temp.length;
	sign = temp.sign;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = temp.numbers[i];
	}
	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	
	if (this == &x) {
		return *this;
	}
	
	delete[] numbers;
	
	length = x.length;
	sign = x.sign;
	
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}
	
	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	if (this == &x) {
		return *this;
	}
	
	delete[] numbers;
	
	numbers = x.numbers;
	length = x.length;
	sign = x.sign;
	
	x.numbers = nullptr;
	x.length = 0;
	x.sign = 1;
	
	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	
	if (sign != x.sign) return false; 
	
	if (length != x.length) return false;
	
	for (int i = 0; i < length; i++) {
		if (numbers[i] != x.numbers[i]) return false;
	}
	
	return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	return !(*this == x);
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (sign != x.sign) {
		return sign > x.sign;
	}
	
	if (sign == 1) {
		if (length != x.length) {
			return length > x.length;
		}
		for (int i = 0; i < length; i++) {
			if (numbers[i] != x.numbers[i]) {
				return numbers[i] > x.numbers[i];
			}
		}
	}
	
	else {
		if (length != x.length) {
			return length < x.length;
		}
		for (int i = 0; i < length; i++) {
			if (numbers[i] != x.numbers[i]) {
				return numbers[i] < x.numbers[i];
			}
		}
	}
	return false;
	
}

bool LongNumber::operator < (const LongNumber& x) const {
	return !(*this > x) && !(*this == x);
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	return LongNumber("0");
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	return LongNumber("0");
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	return LongNumber("0");
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	return LongNumber("0");
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	return LongNumber("0");
}

bool LongNumber::is_negative() const noexcept {
	return sign == -1;
}

int LongNumber::get_length(const char* const str) const noexcept {
	int len = 0;
	
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

namespace dim {
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