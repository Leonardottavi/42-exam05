#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <algorithm>

class bigint {
    std::string v;
    std::string add(const std::string& a, const std::string& b) const {
        std::string r;
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || c) {
            int s = c + (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
            r.push_back('0' + s % 10);
            c = s / 10;
        }
        std::reverse(r.begin(), r.end());
        return r;
    }
public:
    bigint() : v("0") {}
    bigint(const bigint& o) : v(o.v) {}
    bigint& operator=(const bigint& o) { if (this != &o) v = o.v; return *this; }
    ~bigint() {}
    bigint(unsigned long n) {
        if (n == 0) v = "0";
        else { v = ""; while (n) { v = char('0' + n % 10) + v; n /= 10; } }
    }
    bigint(const std::string& s) : v(s.empty() ? "0" : s) {}
    bigint operator+(const bigint& o) const { return bigint(add(v, o.v)); }
    bigint& operator+=(const bigint& o) { v = add(v, o.v); return *this; }
    bigint operator<<(size_t s) const { return bigint(v + std::string(s, '0')); }
    bigint& operator<<=(size_t s) { v += std::string(s, '0'); return *this; }
    bigint operator>>(size_t s) const { return s >= v.size() ? bigint() : bigint(v.substr(0, v.size() - s)); }
    bigint& operator>>=(size_t s) { v = (s >= v.size()) ? "0" : v.substr(0, v.size() - s); return *this; }
    bool operator<(const bigint& o) const { return v.size() != o.v.size() ? v.size() < o.v.size() : v < o.v; }
    bool operator>(const bigint& o) const { return o < *this; }
    bool operator<=(const bigint& o) const { return !(o < *this); }
    bool operator>=(const bigint& o) const { return !(*this < o); }
    bool operator==(const bigint& o) const { return v == o.v; }
    bool operator!=(const bigint& o) const { return v != o.v; }
    bigint& operator++() { return *this += bigint(1); }
    bigint operator++(int) { bigint t(*this); ++(*this); return t; }
    friend std::ostream& operator<<(std::ostream& os, const bigint& x) { return os << x.v; }
};

#endif
