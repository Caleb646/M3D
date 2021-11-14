#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include "_vector.h"

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

template <class T, int SIZE, bool COLORDERING>
class Matrix
{
public:
	T mat[SIZE * SIZE] = { 0 };

//private:
//	bool created = { false };
//
//public:
//	void startCreation() { created = false; };
//	void endCreation() { created = true; };

public:
	Matrix();
	Matrix(T f);
	Matrix(T arr[SIZE][SIZE]);
	Matrix(const Matrix<T, SIZE, COLORDERING>& m);
	~Matrix();
	int getSize();
	void print();
	std::string toString();
	T& operator ()(size_t row, size_t col);
	const T& operator ()(size_t row, size_t col) const;

	//T& operator ()(size_t row, size_t col, bool creating);
	//const T& operator ()(size_t row, size_t col, bool creating) const;

	/*
	* 
	* MATRIX OPERATOR OVERLOADS
	* 
	*/

	void operator = (const Matrix<T, SIZE, COLORDERING>& m0);

	Matrix<T, SIZE, COLORDERING> operator + (const Matrix<T, SIZE, COLORDERING>& m0);
	Matrix<T, SIZE, COLORDERING> operator - (const Matrix<T, SIZE, COLORDERING>& m0);
	Matrix<T, SIZE, COLORDERING> operator * (const Matrix<T, SIZE, COLORDERING>& m0);
	Matrix<T, SIZE, COLORDERING> operator * (float scaler);
	Matrix<T, SIZE, COLORDERING> operator / (float scaler);

	Matrix<T, SIZE, COLORDERING> operator += (const Matrix<T, SIZE, COLORDERING>& m0);
	Matrix<T, SIZE, COLORDERING> operator -= (const Matrix<T, SIZE, COLORDERING>& m0);
	Matrix<T, SIZE, COLORDERING> operator *= (const Matrix<T, SIZE, COLORDERING>& m0);
	Matrix<T, SIZE, COLORDERING> operator *= (float scaler);
	Matrix<T, SIZE, COLORDERING> operator /= (float scaler);

	/*
	*
	* UNARY MATRIX OPERATOR OVERLOADS
	*
	*/

	Matrix<T, SIZE, COLORDERING> operator- ();

	//when converting to float* return the mat array
	//example: float *ptr; Mat4f mat; ptr = (float*) mat; would
	//call one of these functions.
	operator const T* () const;
	operator T* ();

	/*
	*
	* MATRIX TYPES
	*
	*/

	static Matrix<T, SIZE, !COLORDERING> transpose(const Matrix<T, SIZE, COLORDERING>& m0);


	void getTranslated(std::initializer_list<T>);
	void getTranslated(const Vector<T, SIZE>& v0);

	void getPerspectived(float fovRads, float aspect_ratio, float near_dist, float far_dist);

	void getRotatedX(float radians);
	void getRotatedY(float radians);
	void getRotatedZ(float radians);

	void getPointedAt(const Vector<T, SIZE>& cameraPos, const Vector<T, SIZE>& targetV, const Vector<T, SIZE>& upVec);

	void getInversed();

	/*
	*
	* MATRIX STATIC METHODS
	*
	*/

	static Vector<T, SIZE> multVector(Matrix<T, SIZE, COLORDERING> m0, Vector<T, SIZE> v0);

	static Matrix<T, SIZE, COLORDERING> getTranslation(std::initializer_list<T>);
	static Matrix<T, SIZE, COLORDERING> getTranslation(const Vector<T, SIZE>& v0);

	static Matrix<T, SIZE, COLORDERING> getPerspective(float fovRads, float aspect_ratio, float near_dist, float far_dist);

	static Matrix<T, SIZE, COLORDERING> getRotateX(float radians);
	static Matrix<T, SIZE, COLORDERING> getRotateY(float radians);
	static Matrix<T, SIZE, COLORDERING> getRotateZ(float radians);

	static Matrix<T, SIZE, COLORDERING> getPointAt(const Vector<T, SIZE>& cameraPos, const Vector<T, SIZE>& targetV, const  Vector<T, SIZE>& upVec);
	static Matrix<T, SIZE, COLORDERING> getInverse(const Matrix<T, SIZE, COLORDERING>& m);
	static Matrix<T, SIZE, COLORDERING> getLookAt(const Vector<T, 3>& eye, const Vector<T, 3>& center, const  Vector<T, 3>& up);


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
template <class T, int SIZE, bool COLORDERING>
Vector<T, SIZE> operator * (const Matrix<T, SIZE, COLORDERING>& m0, const Vector<T, SIZE>& v0);

template <class T, int SIZE, bool COLORDERING>
Vector<T, SIZE>  operator *= (const Matrix<T, SIZE, COLORDERING>& m0, const Vector<T, SIZE>& v0);

template <class T, int SIZE, bool COLORDERING>
inline bool operator == (const Matrix<T, SIZE, COLORDERING>& lhs, const Matrix<T, SIZE, COLORDERING>& rhs);

template <class T, int SIZE, bool COLORDERING>
inline bool operator != (const Matrix<T, SIZE, COLORDERING>& lhs, const Matrix<T, SIZE, COLORDERING>& rhs);

/*
* 
* 
* TYPE DEFINITIONS
* 
* 
* 
*/
typedef Matrix<float, 2, true> Mat2f;
typedef Matrix<float, 3, true> Mat3f;
typedef Matrix<float, 4, true> Mat4f;

typedef Matrix<float, 4, false> TestMat4Row;
typedef Matrix<float, 4, true> TestMat4Col;
//#include "matrix.cpp"
#endif