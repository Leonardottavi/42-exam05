#ifndef VECT2_HPP
#define VECT2_HPP
#include <iostream>

class vect2 {
	int data[2];
public:
	vect2(){data[0]=data[1]=0;}
	vect2(int x,int y){data[0]=x;data[1]=y;}
	vect2(const vect2& other){data[0]=other.data[0];data[1]=other.data[1];}
	vect2& operator=(const vect2& other){if(this!=&other){data[0]=other.data[0];data[1]=other.data[1];}return *this;}
	~vect2(){}
	int& operator[](int i){return data[i];}
	const int& operator[](int i)const{return data[i];}
	vect2 operator+(const vect2& other)const{return vect2(data[0]+other.data[0],data[1]+other.data[1]);}
	vect2 operator-(const vect2& other)const{return vect2(data[0]-other.data[0],data[1]-other.data[1]);}
	vect2 operator*(int scalar)const{return vect2(data[0]*scalar,data[1]*scalar);}
	vect2& operator+=(const vect2& other){data[0]+=other.data[0];data[1]+=other.data[1];return *this;}
	vect2& operator-=(const vect2& other){data[0]-=other.data[0];data[1]-=other.data[1];return *this;}
	vect2& operator++(){++data[0];++data[1];return *this;}
	vect2& operator--(){--data[0];--data[1];return *this;}
	vect2 operator++(int){vect2 temp(*this);++(*this);return temp;}
	vect2 operator--(int){vect2 temp(*this);--(*this);return temp;}
	bool operator==(const vect2& other)const{return data[0]==other.data[0]&&data[1]==other.data[1];}
	bool operator!=(const vect2& other)const{return !(*this==other);}
	friend vect2 operator*(int scalar,const vect2& vec){return vec*scalar;}
	friend std::ostream& operator<<(std::ostream& os,const vect2& vec){return os<<"{"<<vec.data[0]<<", "<<vec.data[1]<<"}";}
};
#endif
