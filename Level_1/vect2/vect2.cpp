//must support addition, substraction and multiplication!
#include "vect2.hpp"

// Arithmetic operators
vect2 vect2::operator+(const vect2& other) const {
    return vect2(_data[0] + other._data[0], _data[1] + other._data[1]);
}

vect2 vect2::operator-(const vect2& other) const {
    return vect2(_data[0] - other._data[0], _data[1] - other._data[1]);
}

vect2 vect2::operator*(int scalar) const {
    return vect2(_data[0] * scalar, _data[1] * scalar);
}

// Post-increment/Decrement operators
vect2 vect2::operator++(int) {
    vect2 temp = *this;
    ++(*this);
    return temp;
}

vect2 vect2::operator--(int) {
    vect2 temp = *this;
    --(*this);
    return temp;
}

// Compound assignment operators
vect2& vect2::operator+=(const vect2& other) {
    _data[0] += other._data[0];
    _data[1] += other._data[1];
    return *this;
}

vect2& vect2::operator-=(const vect2& other) {
    _data[0] -= other._data[0];
    _data[1] -= other._data[1];
    return *this;
}
