#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
private:
    int _data[2];

public:
    // Constructors
    vect2() { _data[0] = 0; _data[1] = 0; }
    vect2(int v1, int v2) { _data[0] = v1; _data[1] = v2; }
    vect2(const vect2& original) { _data[0] = original._data[0]; _data[1] = original._data[1]; }
    ~vect2() {}

    // Assignment operator
    vect2& operator=(const vect2& other) {
        if (this != &other) {
            _data[0] = other._data[0];
            _data[1] = other._data[1];
        }
        return *this;
    }

    // Accessor operators
    int& operator[](int index) { return _data[index]; }
    const int& operator[](int index) const { return _data[index]; }

    // Arithmetic operators
    vect2 operator+(const vect2& other) const;
    vect2 operator-(const vect2& other) const;
    vect2 operator*(int scalar) const;

    // Increment/Decrement operators
    vect2& operator++() { ++_data[0]; ++_data[1]; return *this; }
    vect2 operator++(int);
    vect2& operator--() { --_data[0]; --_data[1]; return *this; }
    vect2 operator--(int);

    // Compound assignment operators
    vect2& operator+=(const vect2& other);
    vect2& operator-=(const vect2& other);

    // Comparison operators
    bool operator==(const vect2& other) const {
        return _data[0] == other._data[0] && _data[1] == other._data[1];
    }
    bool operator!=(const vect2& other) const { return !(*this == other); }

    // Friend function for scalar multiplication
    friend vect2 operator*(int scalar, const vect2& vector) { return vector * scalar; }
    friend std::ostream& operator<<(std::ostream& out, const vect2& v) {
        out << "{" << v._data[0] << ", " << v._data[1] << "}";
        return out;
    }
};

#endif // VECT2_HPP
