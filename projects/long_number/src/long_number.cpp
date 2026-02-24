#include "long_number.hpp"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string> 

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

bool LongNumber::operator >= (const LongNumber& x) const {
    return (*this > x) || (*this == x);
}

bool LongNumber::operator <= (const LongNumber& x) const {
    return (*this < x) || (*this == x);
}



LongNumber LongNumber::operator - () const {
	LongNumber result = *this;
	result.sign = -sign;
	return result;
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	
    if (sign != x.sign) {
        if (sign == -1) {
            return x - (-(*this));
        }
        else {
            return *this - (-x);
        }
    }
    
    int max_len = std::max(length, x.length) + 1;
    int* result = new int[max_len]();
    
    int i = length - 1;
    int j = x.length - 1;
    int k = max_len - 1;
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += numbers[i--];
        if (j >= 0) sum += x.numbers[j--];
        
        result[k--] = sum % 10;
        carry = sum / 10;
    }
    
    LongNumber res;
    delete[] res.numbers;
    
    int start = 0;
    while (start < max_len && result[start] == 0) {
        start++;
    }
    
    if (start == max_len) {
        res.length = 1;
        res.numbers = new int[1];
        res.numbers[0] = 0;
        res.sign = 1;
    } else {
        res.length = max_len - start;
        res.numbers = new int[res.length];
        for (int idx = 0; idx < res.length; idx++) {
            res.numbers[idx] = result[start + idx];
        }
        res.sign = sign;
    }
    
    delete[] result;
    return res;
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	return *this + (-x);
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
    if (this->is_zero() || x.is_zero()) {
        return LongNumber("0");
    }
    
    int res_len = length + x.length;
    int* result = new int[res_len]();
    
    for (int i = length - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = x.length - 1; j >= 0; j--) {
            int pos = i + j + 1;
            int prod = numbers[i] * x.numbers[j] + result[pos] + carry;
            result[pos] = prod % 10;
            carry = prod / 10;
        }
        result[i] += carry;
    }
    
    LongNumber res;
    delete[] res.numbers;
    
    int start = 0;
    while (start < res_len && result[start] == 0) {
        start++;
    }
    
    if (start == res_len) {
        res.length = 1;
        res.numbers = new int[1];
        res.numbers[0] = 0;
        res.sign = 1;
    } else {
        res.length = res_len - start;
        res.numbers = new int[res.length];
        for (int i = 0; i < res.length; i++) {
            res.numbers[i] = result[start + i];
        }
        res.sign = sign * x.sign;
    }
    
    delete[] result;
    return res;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
    if (x.is_zero()) {
        return LongNumber("0");
    }
    
    LongNumber result("0");
    LongNumber temp = *this;
    
    while (temp >= x) {
        temp = temp - x;
        result = result + LongNumber("1");
    }
	
    result.sign = sign * x.sign;
    return result;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
    if (x.is_zero()) {
        return LongNumber("0");
    }
    
    LongNumber ost = *this;
    
    while (ost >= x) {
        ost = ost - x;
    }
    
    ost.sign = 1;
    return ost;
}

bool LongNumber::is_negative() const noexcept {
	return sign == -1;
}

bool LongNumber::is_zero() const noexcept {
    return length == 1 && numbers[0] == 0;
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