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

int LongNumber::abs_compare(const LongNumber& x) const noexcept {
    if (length != x.length) {
        return length > x.length ? 1 : -1;
    }
    for (int i = 0; i < length; i++) {
        if (numbers[i] != x.numbers[i]) {
            return numbers[i] > x.numbers[i] ? 1 : -1;
        }
    }
    return 0;
}

LongNumber LongNumber::sub_abs(const LongNumber& x) const noexcept {
    LongNumber result(length, 1);
    
    int borrow = 0;
    int i = length - 1;
    int j = x.length - 1;
    int k = length - 1;
    
    while (i >= 0) {
        int digit1 = numbers[i];
        int digit2 = (j >= 0) ? x.numbers[j] : 0;
        
        int diff = digit1 - digit2 - borrow;
        
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result.numbers[k] = diff;
        
        i--;
        j--;
        k--;
    }
    
    int start = 0;
    while (start < result.length - 1 && result.numbers[start] == 0) {
        start++;
    }
    
    if (start == 0) {
        return result;
    } else {
        LongNumber trimmed(result.length - start, 1);
        for (int idx = 0; idx < trimmed.length; idx++) {
            trimmed.numbers[idx] = result.numbers[start + idx];
        }
        return trimmed;
    }
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
	} else {
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
        if (sign == 1) {
            if (abs_compare(x) >= 0) {
                return sub_abs(x);
            } else {
                LongNumber result = x.sub_abs(*this);
                result.sign = -1;
                return result;
            }
        } else {
            if (abs_compare(x) <= 0) {
                return x.sub_abs(*this);
            } else {
                LongNumber result = sub_abs(x);
                result.sign = -1;
                return result;
            }
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
        throw std::runtime_error("Делим на ноль!");
    }
    
    if (abs_compare(x) == -1) {
        return LongNumber("0");
    }
    
    LongNumber dividend = *this;
    dividend.sign = 1;
    
    LongNumber divisor = x;
    divisor.sign = 1;

std::string result_str = "";
    LongNumber current("0");
    
    for (int i = 0; i < dividend.length; i++) {
        LongNumber temp = current * LongNumber("10");
        
        std::string digit_str = std::to_string(dividend.numbers[i]);
        LongNumber digit(digit_str.c_str());
        
        current = temp + digit;
        
        int count = 0;
        while (current.abs_compare(divisor) >= 0) {
            current = current - divisor;
            count++;
        }
        
        if (count > 0 || !result_str.empty()) {
            result_str += char(count + '0');
        }
    }
    
    if (result_str.empty()) {
        return LongNumber("0");
    }
    
    LongNumber result(result_str.c_str());
    result.sign = sign * x.sign;
    
    return result;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
    if (x.is_zero()) {
        throw std::runtime_error("Модуль с нулём!");
    }
    
    LongNumber quotient = *this / x;
    LongNumber product = quotient * x;
    LongNumber remainder = *this - product;
    
    if (remainder.sign == -1) {
        remainder = remainder + x;
    }
    
    return remainder;
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