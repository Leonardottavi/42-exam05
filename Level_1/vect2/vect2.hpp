#ifndef VECT2_HPP
#define VECT2_HPP
#include <iostream>

class vect2 {
	int x, y;
public:
	vect2():x(0),y(0){}
	vect2(int a,int b):x(a),y(b){}
	vect2(const vect2& other):x(other.x),y(other.y){}
	vect2& operator=(const vect2& other){x=other.x;y=other.y;return *this;}
	~vect2(){}
	int& operator[](int i){return i?y:x;}
	const int& operator[](int i)const{return i?y:x;}
	vect2 operator+(const vect2& other)const{return vect2(x+other.x,y+other.y);}
	vect2 operator-(const vect2& other)const{return vect2(x-other.x,y-other.y);}
	vect2 operator*(int s)const{return vect2(x*s,y*s);}
	vect2& operator+=(const vect2& other){x+=other.x;y+=other.y;return *this;}
	vect2& operator-=(const vect2& other){x-=other.x;y-=other.y;return *this;}
	vect2& operator++(){++x;++y;return *this;}
	vect2& operator--(){--x;--y;return *this;}
	vect2 operator++(int){vect2 t(*this);++*this;return t;}
	vect2 operator--(int){vect2 t(*this);--*this;return t;}
	bool operator==(const vect2& other)const{return x==other.x&&y==other.y;}
	bool operator!=(const vect2& other)const{return !(*this==other);}
	friend vect2 operator*(int s,const vect2& v){return v*s;}
	friend std::ostream& operator<<(std::ostream& os,const vect2& v){return os<<"{"<<v.x<<", "<<v.y<<"}";}
};
#endif
