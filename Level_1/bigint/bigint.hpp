#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <iostream>
#include <string>
#include <sstream>

class bigint {
    std::string value;

    std::string to_string(unsigned long num) const {
        std::ostringstream oss;
        oss << num;
        return oss.str();
    }

public:
    bigint() : value("0") {}
    bigint(unsigned long num) : value(to_string(num)) {}
    bigint(const std::string& str) : value(str.empty() ? "0" : str) {}

    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other) { return *this = *this + other; }

    bigint operator<<(size_t shift) const { bigint result(*this); result.value.append(shift, '0'); return result; }
    bigint& operator<<=(size_t shift) { value.append(shift, '0'); return *this; }
    bigint operator>>(size_t shift) const { return shift >= value.length() ? bigint(0) : bigint(value.substr(0, value.length() - shift)); }
    bigint& operator>>=(size_t shift) { shift >= value.length() ? value = "0" : value = value.substr(0, value.length() - shift); return *this; }

    bool operator<(const bigint& other) const { return value.length() != other.value.length() ? value.length() < other.value.length() : value < other.value; }
    bool operator>(const bigint& other) const { return other < *this; }
    bool operator<=(const bigint& other) const { return !(other < *this); }
    bool operator>=(const bigint& other) const { return !(*this < other); }
    bool operator==(const bigint& other) const { return value == other.value; }
    bool operator!=(const bigint& other) const { return !(*this == other); }

    bigint& operator++() { return *this += bigint(1); }
    bigint operator++(int) { bigint temp(*this); ++(*this); return temp; }

    friend std::ostream& operator<<(std::ostream& os, const bigint& num) { return os << num.value; }
};
#endif
