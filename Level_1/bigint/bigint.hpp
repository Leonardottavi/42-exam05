#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
private:
    std::string value;

public:
    bigint() : value("0") {}
    bigint(unsigned long long num) : value(std::to_string(num)) {}
    bigint(const std::string& str) : value(str.empty() ? "0" : str) {}

    // Arithmetic operators
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other) { return *this = *this + other; }

    // Digit shift operators
    bigint operator<<(size_t shift) const {
        bigint result(*this);
        result.value.append(shift, '0');
        return result;
    }
    bigint& operator<<=(size_t shift) {
        value.append(shift, '0');
        return *this;
    }
    bigint operator>>(size_t shift) const {
        if (shift >= value.length()) return bigint(0);
        return bigint(value.substr(0, value.length() - shift));
    }
    bigint& operator>>=(size_t shift) {
        if (shift >= value.length()) value = "0";
        else value = value.substr(0, value.length() - shift);
        return *this;
    }

    // Comparison operators
    bool operator<(const bigint& other) const {
        if (value.length() != other.value.length())
            return value.length() < other.value.length();
        return value < other.value;
    }
    bool operator>(const bigint& other) const { return other < *this; }
    bool operator<=(const bigint& other) const { return !(other < *this); }
    bool operator>=(const bigint& other) const { return !(*this < other); }
    bool operator==(const bigint& other) const { return value == other.value; }
    bool operator!=(const bigint& other) const { return !(*this == other); }

    // Increment operators
    bigint& operator++() { return *this += bigint(1); }
    bigint operator++(int) { bigint temp(*this); ++(*this); return temp; }

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const bigint& num) {
        return os << num.value;
    }
};

#endif
