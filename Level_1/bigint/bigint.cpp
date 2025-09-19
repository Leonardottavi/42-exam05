#include "bigint.hpp"
#include <algorithm>

bigint bigint::operator+(const bigint& other) const {
    std::string result;
    int carry = 0;
    int i = value.length() - 1;
    int j = other.value.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += value[i--] - '0';
        if (j >= 0) sum += other.value[j--] - '0';

        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    std::reverse(result.begin(), result.end());
    return bigint(result);
}
