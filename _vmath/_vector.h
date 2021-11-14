#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>


/*
* 
* 
* 
* NOTES: The v array has to be located at the top of the class for opengl vertex buffers.
*
* 
* 
* 
*/

template <class T, int SIZE>
class Vector {

public:
	T v[SIZE] = { 0 }; //init to all zeros;

public:
	//pass in int/float to fill vector
	Vector();
	Vector(const Vector<T, SIZE>& v0);
	Vector(T f);
	Vector(T x, T y, T z, T w);
	Vector(T x, T y, T z);
	Vector(T x, T y);
	Vector(T arr[SIZE]);
	Vector(const Vector<T, 2>& xy, T z, T w);
	Vector(T x, const Vector<T, 2>& yz, T w);
	Vector(T x, T y, const Vector<T, 2>& zw);
	Vector(const Vector<T, 2>& xy, const Vector<T, 2>& zw);
	Vector(const Vector<T, 3>& xyz, T w);
	Vector(std::initializer_list<T>);
	~Vector();

	//Base Util Methods
	int getSize();
	void print();
	std::string toString();

	/*
	*
	* 
	* 
	* VECTOR OPERATOR OVERLOADS
	* 
	* 
	*
	*/

	inline T& operator[] (size_t index);
	inline const T& operator [] (size_t i) const;

	//OpenGl Conversion Operators
	inline operator const T* () const;
	inline operator T* ();

	inline Vector<T, SIZE> operator + (const Vector<T, SIZE>& v0);
	inline Vector<T, SIZE> operator - (const Vector<T, SIZE>& v0);
	inline Vector<T, SIZE> operator * (const Vector<T, SIZE>& v0);
	inline Vector<T, SIZE> operator * (float scale);
	inline Vector<T, SIZE> operator / (float scale);
	inline Vector<T, SIZE>& operator += (const Vector<T, SIZE>& v0);
	inline Vector<T, SIZE>& operator -= (const Vector<T, SIZE>& v0);
	inline Vector<T, SIZE>& operator *= (const Vector<T, SIZE>& v0);
	inline Vector<T, SIZE>& operator *= (float scale);
	inline Vector<T, SIZE>& operator /= (float scale);
	inline Vector<T, SIZE>& operator = (const Vector<T, SIZE>& v0);

	/*
	*
	* UNARY VECTOR OPERATOR
	*
	*/

	Vector<T, SIZE> operator- ();

	//Vector Util Methods
	T& x();
	T& y();
	T& z();
	T& w();
	T x() const;
	T y() const;
	T z() const;
	T w() const;

	Vector<T, 2> xy() const;
	Vector<T, 2> yz() const;
	Vector<T, 2> zw() const;
	Vector<T, 2> wx() const;


	Vector<T, 3> xyz() const;
	Vector<T, 3> yzw() const;
	Vector<T, 3> zwx() const;
	Vector<T, 3> wxy() const;

	Vector<T, 3> xyw() const;
	Vector<T, 3> yzx() const;
	Vector<T, 3> zwy() const;
	Vector<T, 3> wxz() const;

	bool validate(const Vector<T, SIZE>& v1, const Vector<T, SIZE>& v2);
	bool validate(const Vector<T, SIZE>& v, int requiredSized);
	float getLength();
	Vector<T, SIZE> normalize();
	void normalized();

	//Vector Static Math Operations
	static float dot(const Vector<T, SIZE>& v1, const Vector<T, SIZE>& v2);
	static Vector<T, 3> cross(const Vector<T, 3>& v1, const Vector<T, 3>& v2);
};

/*
*
*
*
*
* NON MEMBER OPERATORS
*
*
*
*
*
*/

template <class T, int SIZE>
inline bool operator == (const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs);

template <class T, int SIZE>
inline bool operator != (const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs);

template <class T, int SIZE>
Vector<T, SIZE> operator - (const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs);

template <class T, int SIZE>
Vector<T, SIZE> operator + (const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs);

template <class T, int SIZE>
Vector<T, SIZE> operator * (const Vector<T, SIZE>& lhs, float scaler);

template <class T, int SIZE>
Vector<T, SIZE> operator * (float scaler, const Vector<T, SIZE>& rhs);

template <class T, int SIZE>
Vector<T, SIZE> operator / (const Vector<T, SIZE>& lhs, float scaler);

/*
* 
* TYPE DEFINITIONS
* 
* 
*/

typedef Vector<float, 2> Vec2f;
typedef Vector<float, 3> Vec3f;
typedef Vector<float, 4> Vec4f;

typedef Vector<float, 2> TestVec2;
typedef Vector<float, 3> TestVec3;
typedef Vector<float, 4> TestVec4;

//#include "vector.cpp"

#endif