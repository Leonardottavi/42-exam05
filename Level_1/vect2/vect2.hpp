#ifndef VECT2_HPP
#define VECT2_HPP
#include <iostream>

class vect2 {
    int _data[2];
public:
    vect2() { _data[0] = _data[1] = 0; }
    vect2(int x, int y) { _data[0] = x; _data[1] = y; }
    vect2(const vect2& o) { _data[0] = o._data[0]; _data[1] = o._data[1]; }
    vect2& operator=(const vect2& o) {
        if (this != &o) { _data[0] = o._data[0]; _data[1] = o._data[1]; }
        return *this;
    }
    ~vect2() {}

    int& operator[](int i) { return _data[i]; }
    const int& operator[](int i) const { return _data[i]; }

    vect2 operator+(const vect2& o) const { return vect2(_data[0] + o._data[0], _data[1] + o._data[1]); }
    vect2 operator-(const vect2& o) const { return vect2(_data[0] - o._data[0], _data[1] - o._data[1]); }
    vect2 operator*(int s) const { return vect2(_data[0] * s, _data[1] * s); }

    vect2& operator+=(const vect2& o) { _data[0] += o._data[0]; _data[1] += o._data[1]; return *this; }
    vect2& operator-=(const vect2& o) { _data[0] -= o._data[0]; _data[1] -= o._data[1]; return *this; }

    vect2& operator++() { ++_data[0]; ++_data[1]; return *this; }
    vect2& operator--() { --_data[0]; --_data[1]; return *this; }
    vect2 operator++(int) { vect2 t(*this); ++(*this); return t; }
    vect2 operator--(int) { vect2 t(*this); --(*this); return t; }

    bool operator==(const vect2& o) const { return _data[0] == o._data[0] && _data[1] == o._data[1]; }
    bool operator!=(const vect2& o) const { return !(*this == o); }

    friend vect2 operator*(int s, const vect2& v) { return v * s; }
    friend std::ostream& operator<<(std::ostream& os, const vect2& v) {
        return os << "{" << v._data[0] << ", " << v._data[1] << "}";
    }
};
#endif
