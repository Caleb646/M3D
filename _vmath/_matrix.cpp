#include <iomanip>
#include <sstream>
#include <Log.h>

#include "_matrix.h"
#include "../_logging/_log.h"

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING>::Matrix()
{
	//startCreation();
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if(i == j)
				this->operator()(i,j) = static_cast<T>(1);
			else
				this->operator()(i,j) = static_cast<T>(0);
		}
	}
	//endCreation();
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING>::Matrix(T f)
{
	//startCreation();
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->operator()(i,j) = static_cast<T>(f);
		}
	}
	//endCreation();
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING>::Matrix(T arr[SIZE][SIZE])
{
	//startCreation();
	//expects row ordered 2d array
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->operator()(i,j) = arr[i][j];
		}
	}
	//endCreation();
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING>::Matrix(const Matrix<T, SIZE, COLORDERING>& m)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->operator()(i,j) = m(i, j);
		}
	}
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING>::~Matrix()
{

}

template <class T, int SIZE, bool COLORDERING>
int Matrix<T, SIZE, COLORDERING>::getSize()
{
	return SIZE;
}

template <class T, int SIZE, bool COLORDERING>
void Matrix<T, SIZE, COLORDERING>::print()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << " || " << this->operator()(i, j) << " || " << " || "; //<< &this->operator()(i, j) << " || ";
			//std::cout << " || " << mat[(i * SIZE) + j] << " || " << " || " << &mat[(i * SIZE) + j] << " || ";
			//std::cout << " || " << mat[(i * SIZE) + j] << " || ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <class T, int SIZE, bool COLORDERING>
std::string Matrix<T, SIZE, COLORDERING>::toString()
{
	std::stringstream stream;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			size_t index = (j * SIZE) + i;
			//stream << std::fixed << std::setprecision(2) << this->operator()(i, j, true) << " || " << &this->operator()(i, j, true);
			stream << std::fixed << std::setprecision(2) << this->operator()(i, j) << " || " << index << " || ";
			//if (COLORDERING) //swap contiguous parts to be place in the row of the string instead of the column
			//	stream << std::fixed << std::setprecision(2) << this->operator()(j, i);
			//else
			//	stream << std::fixed << std::setprecision(2) << this->operator()(i, j);// << " || " << &this->operator()(i, j);
			stream << " ";
		}
		stream << "\n";
	}
	return stream.str();
}

template <class T, int SIZE, bool COLORDERING>
T& Matrix<T, SIZE, COLORDERING>::operator ()(size_t row, size_t col)
{
	ASSERT_FATAL(DEFAULT_LOGGABLE, row < SIZE&& col < SIZE, "row or col is out of bounds.");
	size_t index = (row * SIZE) + col;

	if (COLORDERING)
		index = (col * SIZE) + row;

	return mat[index];
}

template <class T, int SIZE, bool COLORDERING>
const T& Matrix<T, SIZE, COLORDERING>::operator ()(size_t row, size_t col) const
{
	ASSERT_FATAL(DEFAULT_LOGGABLE, row < SIZE&& col < SIZE, "row or col is out of bounds.");
	size_t index = (row * SIZE) + col;
	//if (created)
	//	return mat[index];

	if (COLORDERING)
		index = (col * SIZE) + row;

	return mat[index];
}

/*
*
* MATRIX OPERATOR OVERLOADS
*
*/

template <class T, int SIZE, bool COLORDERING>
void Matrix<T, SIZE, COLORDERING>::operator = (const Matrix<T, SIZE, COLORDERING>& m0)
{
	////startCreation();
	//m0.//startCreation();
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->operator()(i, j) = m0(i, j);
		}
	}
	////m.endCreation();
	////endCreation();
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::operator + (const Matrix<T, SIZE, COLORDERING>& m0)
{
	Matrix<T, SIZE, COLORDERING> out;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			out(i, j) = this->operator()(i, j) + m0(i, j);
		}
	}
	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::operator - (const Matrix<T, SIZE, COLORDERING>& m0)
{
	Matrix<T, SIZE, COLORDERING> out;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			out(i, j) = this->operator()(i,j) - m0(i, j);
		}
	}
	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::operator * (const Matrix<T, SIZE, COLORDERING>& m0)
{
	Matrix<T, SIZE, COLORDERING> out(0.0f);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int z = 0; z < SIZE; z++)
			{
				out(i, j) = out(i, j) + this->operator()(i, j) * m0(j, z);
			}
		}
	}
	return out;
}


template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::operator * (float scaler)
{
	Matrix<T, SIZE, COLORDERING> out;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			out(i, j) = this->operator()(i,j) * scaler;
		}
	}
	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::operator / (float scaler)
{
	Matrix<T, SIZE, COLORDERING> out;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			out(i, j) = this->operator()(i,j) / scaler;
		}
	}
	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::operator += (const Matrix<T, SIZE, COLORDERING>& m0)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->operator()(i,j) = this->operator()(i,j) + m0(i, j);
		}
	}
	return *this;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::operator -= (const Matrix<T, SIZE, COLORDERING>& m0)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->operator()(i,j) = this->operator()(i,j) - m0(i, j);
		}
	}
	return *this;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::operator *= (const Matrix<T, SIZE, COLORDERING>& m0)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			T row = static_cast<T>(0);
			for (int z = 0; z < SIZE; z++)
			{
				row = row + this->operator()(i, j) * m0(j, z);
			}
			this->operator()(i, j) = row;
		}
	}
	return *this;
}



template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::operator *= (float scaler)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->operator()(i,j) = this->operator()(i,j) * scaler;
		}
	}
	return *this;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::operator /= (float scaler)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->operator()(i,j) = this->operator()(i,j) / scaler;
		}
	}
	return *this;
}

/*
*
* UNARY MATRIX OPERATOR OVERLOADS
*
*/

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::operator- ()
{
	Matrix<T, SIZE, COLORDERING> out;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; i++)
		{
			out(i, j) = -this->operator()(i, j);
		}

	}
		
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING>::operator const T* () const
{
	return mat;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING>::operator T* ()
{
	return mat;
}

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
Vector<T, SIZE>  operator * (const Matrix<T, SIZE, COLORDERING>& m0, const Vector<T, SIZE>& v0)
{
	Vector<T, SIZE> out(0.0f);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			out[i] = out[i] + m0(i, j) * v0[j];
		}
	}
	return out;
}


template <class T, int SIZE, bool COLORDERING>
Vector<T, SIZE>  operator *= (const Matrix<T, SIZE, COLORDERING>& m0, const Vector<T, SIZE>& v0)
{
	Vector<T, SIZE> out(0.0f);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			out[i] = out[i] + m0(i, j) * v0[j];
		}
	}
	return out;
}

template <class T, int SIZE, bool COLORDERING>
inline bool operator == (const Matrix<T, SIZE, COLORDERING>& lhs, const Matrix<T, SIZE, COLORDERING>& rhs)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (lhs(i, j) != rhs(i, j))
				return false;
		}
	}
		
	return true;
}

template <class T, int SIZE, bool COLORDERING>
inline bool operator != (const Matrix<T, SIZE, COLORDERING>& lhs, const Matrix<T, SIZE, COLORDERING>& rhs)
{
	return !(lhs == rhs);
}


/*
*
* MATRIX TYPES
*
*/

template <class T, int SIZE, bool COLORDERING>
void Matrix<T, SIZE, COLORDERING>::getTranslated(std::initializer_list<T> init_list)
{
	//startCreation();
	int c = 0;
	for (auto i = init_list.begin(); i != init_list.end(); i++) {
		//this->operator()(SIZE - 1, c++) = *i;
		this->operator()(c++, SIZE - 1) = static_cast<T>(*i);
	}
	//endCreation();
}

template <class T, int SIZE, bool COLORDERING>
void Matrix<T, SIZE, COLORDERING>::getTranslated(const Vector<T, SIZE>& v0)
{
	//startCreation();
	for (int i = 0; i < SIZE; i++) {
		//this->operator()(SIZE - 1, i) = v0[i];
		this->operator()(i, SIZE - 1) = v0[i];
	}
	//endCreation();
}

template <class T, int SIZE, bool COLORDERING>
void Matrix<T, SIZE, COLORDERING>::getPerspectived(float fovRads, float aspect_ratio, float near_dist, float far_dist)
{
	//startCreation();

	float half = std::tanf(fovRads / static_cast<T>(2));

	this->operator()(0, 0) = static_cast<T>(1) / (aspect_ratio * half);
	this->operator()(1, 1) = static_cast<T>(1) / half;
	this->operator()(2, 2) = far_dist / (near_dist - far_dist);
	this->operator()(3, 2) = -static_cast<T>(1);
	this->operator()(2, 3) = -((static_cast<T>(2) * far_dist * near_dist) / (far_dist - near_dist));
	this->operator()(3, 3) = static_cast<T>(0);

	//endCreation();
}

template <class T, int SIZE, bool COLORDERING>
void Matrix<T, SIZE, COLORDERING>::getRotatedX(float radians)
{
	//startCreation();

	float c = std::cosf(radians);
	float s = std::sinf(radians);

	this->operator()(1, 1) = c;
	this->operator()(1, 2) = s;
	this->operator()(2, 1) = -s;
	this->operator()(2, 2) = c;

	//endCreation();
}

template <class T, int SIZE, bool COLORDERING>
void Matrix<T, SIZE, COLORDERING>::getRotatedY(float radians)
{
	//startCreation();

	float c = std::cosf(radians);
	float s = std::sinf(radians);

	this->operator()(0, 0) = c;
	this->operator()(0, 2) = s;
	this->operator()(2, 0) = -s;
	this->operator()(2, 2) = c;

	//endCreation();
}
template <class T, int SIZE, bool COLORDERING>
void Matrix<T, SIZE, COLORDERING>::getRotatedZ(float radians)
{
	//startCreation();

	float c = std::cosf(radians);
	float s = std::sinf(radians);

	this->operator()(0, 0) = c;
	this->operator()(0, 1) = s;
	this->operator()(1, 0) = -s;
	this->operator()(1, 1) = c;

	//endCreation();
}

template <class T, int SIZE, bool COLORDERING>
void Matrix<T, SIZE, COLORDERING>::getPointedAt(const Vector<T, SIZE>& cameraPos, const Vector<T, SIZE>& targetV, const Vector<T, SIZE>& upVec)
{
	

	Vector<T, SIZE> newForward = (targetV - cameraPos).normalize();
	float projection = Vector<T, SIZE>::dot(upVec, newForward);
	Vector<T, SIZE> a = newForward * projection;
	Vector<T, SIZE> newUp = (upVec - a).normalize();
	Vector<T, SIZE> newRight = Vector<T, SIZE>::cross(upVec, newForward);

	//startCreation();

	this->operator()(0, 0) = newRight.x();
	this->operator()(0, 1) = newRight.y();
	this->operator()(0, 2) = newRight.z();
	this->operator()(0, 3) = 0.0f;
	this->operator()(1, 0) = newUp.x();
	this->operator()(1, 1) = newUp.y();
	this->operator()(1, 2) = newUp.z();
	this->operator()(1, 3) = 0.0f;
	this->operator()(2, 0) = newForward.x();
	this->operator()(2, 1) = newForward.y();
	this->operator()(2, 2) = newForward.z();
	this->operator()(2, 3) = 0.0f;
	this->operator()(3, 0) = cameraPos.x();
	this->operator()(3, 1) = cameraPos.y();
	this->operator()(3, 2) = cameraPos.z();
	this->operator()(3, 3) = 1.0f;

	//endCreation();

}

template <class T, int SIZE, bool COLORDERING>
void Matrix<T, SIZE, COLORDERING>::getInversed()
{
	Matrix<T, SIZE, COLORDERING> m(*this);

	//startCreation();
	//m.startCreation();

	this->operator()(0, 0) = m(0, 0);
	this->operator()(0, 1) = m(1, 0);
	this->operator()(0, 2) = m(2, 0);
	this->operator()(0, 3) = static_cast<T>(0);
	this->operator()(1, 0) = m(0, 1);
	this->operator()(1, 1) = m(1, 1);
	this->operator()(1, 2) = m(2, 1);
	this->operator()(1, 3) = static_cast<T>(0);
	this->operator()(2, 0) = m(0, 2);
	this->operator()(2, 1) = m(1, 2);
	this->operator()(2, 2) = m(2, 2);
	this->operator()(2, 3) = static_cast<T>(0);
	this->operator()(3, 0) = -(m(3, 0) * this->operator()(0, 0) + m(3, 1) * this->operator()(1, 0) + m(3, 2) * this->operator()(2, 0));
	this->operator()(3, 1) = -(m(3, 0) * this->operator()(0, 1) + m(3, 1) * this->operator()(1, 1) + m(3, 2) * this->operator()(2, 1));
	this->operator()(3, 2) = -(m(3, 0) * this->operator()(0, 2) + m(3, 1) * this->operator()(1, 2) + m(3, 2) * this->operator()(2, 2));
	this->operator()(3, 3) = static_cast<T>(1);

	//m.endCreation();
	//endCreation();
}

/*
*
* 
* 
* 
* MATRIX STATIC METHODS
* 
* 
* 
*
*/

template <class T, int SIZE, bool COLORDERING>
Vector<T, SIZE> Matrix<T, SIZE, COLORDERING>::multVector(Matrix<T, SIZE, COLORDERING> m0, Vector<T, SIZE> v0)
{
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			out[i] = out[i] + (v0[i] * m0(j, i));
		}
	}
	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::getTranslation(std::initializer_list<T> init_list)
{
	Matrix<T, SIZE, COLORDERING> out;
	int c = 0;

	//out.startCreation();

	for (auto i = init_list.begin(); i != init_list.end(); i++) 
	{
		out(c++, SIZE - 1) = static_cast<T>(*i);
		//out(SIZE - 1, c++) = *i;
	}
	//out.endCreation();

	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::getTranslation(const Vector<T, SIZE>& v0)
{
	/*
	* The translation components occupy the 13th, 14th, and 15th elements of the 16-element
	* matrix, where indices are numbered from 1 to 16.
	* 
	*/

	Matrix<T, SIZE, COLORDERING> out;

	////out.startCreation();
	for (int i = 0; i < SIZE; i++)
	{
		out(i, SIZE - 1) = v0[i];
		//out(SIZE - 1, i) = v0[i];
	}

	////out.endCreation();
	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, !COLORDERING> Matrix<T, SIZE, COLORDERING>::transpose(const Matrix<T, SIZE, COLORDERING>& m0)
{
	Matrix<T, SIZE, !COLORDERING> out;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			out(i, j) = m0(j, i);
		}
	}
		
	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::getPerspective(float fovRads, float aspect_ratio, float near_dist, float far_dist)
{
	Matrix<T, SIZE, COLORDERING> out;
	float half = std::tanf(fovRads / static_cast<T>(2));

	//out.startCreation();

	out(0, 0) = static_cast<T>(1) / (aspect_ratio * half);
	out(1, 1) = static_cast<T>(1) / half;
	out(2, 2) = far_dist / (near_dist - far_dist);
	out(3, 2) = -(static_cast<T>(1)); //3, 2
	out(2, 3) = -((static_cast<T>(2) * far_dist * near_dist) / (far_dist - near_dist)); // 2, 3
	out(3, 3) = static_cast<T>(0);

	//out.endCreation();

	return out;
}
template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::getRotateX(float radians)
{
	Matrix<T, SIZE, COLORDERING> out;

	float c = std::cosf(radians);
	float s = std::sinf(radians);

	//out.startCreation();

	out(1, 1) = c;
	out(1, 2) = s;
	out(2, 1) = -s;
	out(2, 2) = c;

	//out.endCreation();

	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::getRotateY(float radians)
{
	Matrix<T, SIZE, COLORDERING> out;

	float c = std::cosf(radians);
	float s = std::sinf(radians);

	//out.startCreation();

	out(0, 0) = c;
	out(0, 2) = s;
	out(2, 0) = -s;
	out(2, 2) = c;

	//out.endCreation();

	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::getRotateZ(float radians)
{
	Matrix<T, SIZE, COLORDERING> out;

	float c = std::cosf(radians);
	float s = std::sinf(radians);

	//out.startCreation();

	out(0, 0) = c;
	out(0, 1) = s;
	out(1, 0) = -s;
	out(1, 1) = c;

	//out.endCreation();

	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::getPointAt(const Vector<T, SIZE>& cameraPos, const Vector<T, SIZE>& targetV, const  Vector<T, SIZE>& upVec)
{
	Vector<T, SIZE> newForward = (targetV - cameraPos).normalize();
	float projection = Vector<T, SIZE>::dot(upVec, newForward);
	Vector<T, SIZE> a = newForward * projection;
	Vector<T, SIZE> newUp = (upVec - a).normalize();
	Vector<T, SIZE> newRight = Vector<T, SIZE>::cross(upVec, newForward);

	Matrix<T, SIZE, COLORDERING> out;

	//out.startCreation();

	out(0, 0) = newRight.x();
	out(0, 1) = newRight.y();
	out(0, 2) = newRight.z();
	out(0, 3) = 0.0;
	out(1, 0) = newUp.x();
	out(1, 1) = newUp.y();
	out(1, 2) = newUp.z();
	out(1, 3) = 0.0;
	out(2, 0) = newForward.x();
	out(2, 1) = newForward.y();
	out(2, 2) = newForward.z();
	out(2, 3) = 0.0;
	out(3, 0) = cameraPos.x();
	out(3, 1) = cameraPos.y();
	out(3, 2) = cameraPos.z();
	out(3, 3) = 1.0;

	//out.endCreation();

	return out;
}
template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::getInverse(const Matrix<T, SIZE, COLORDERING>& m)
{
	Matrix<T, SIZE, COLORDERING> out(m);

	//out.startCreation();
	//m.startCreation();

	out(0, 0) = m(0, 0);
	out(0, 1) = m(1, 0);
	out(0, 2) = m(2, 0);
	out(0, 3) = static_cast<T>(0);
	out(1, 0) = m(0, 1);
	out(1, 1) = m(1, 1);
	out(1, 2) = m(2, 1);
	out(1, 3) = static_cast<T>(0);
	out(2, 0) = m(0, 2);
	out(2, 1) = m(1, 2);
	out(2, 2) = m(2, 2);
	out(2, 3) = static_cast<T>(0);
	out(3, 0) = -(m(3, 0) * out(0, 0) + m(3, 1) * out(1, 0) + m(3, 2) * out(2, 0));
	out(3, 1) = -(m(3, 0) * out(0, 1) + m(3, 1) * out(1, 1) + m(3, 2) * out(2, 1));
	out(3, 2) = -(m(3, 0) * out(0, 2) + m(3, 1) * out(1, 2) + m(3, 2) * out(2, 2));
	out(3, 3) = static_cast<T>(1);

	out(0, 0) = m(0, 0);
	out(0, 1) = m(1, 0);
	out(0, 2) = m(2, 0);
	out(0, 3) = static_cast<T>(0);
	out(1, 0) = m(0, 1);
	out(1, 1) = m(1, 1);
	out(1, 2) = m(2, 1);
	out(1, 3) = static_cast<T>(0);
	out(2, 0) = m(0, 2);
	out(2, 1) = m(1, 2);
	out(2, 2) = m(2, 2);
	out(2, 3) = static_cast<T>(0);
	out(3, 0) = -(m(3, 0) * out(0, 0) + m(3, 1) * out(1, 0) + m(3, 2) * out(2, 0));
	out(3, 1) = -(m(3, 0) * out(0, 1) + m(3, 1) * out(1, 1) + m(3, 2) * out(2, 1));
	out(3, 2) = -(m(3, 0) * out(0, 2) + m(3, 1) * out(1, 2) + m(3, 2) * out(2, 2));
	out(3, 3) = static_cast<T>(1);

	//m.endCreation();
	//endCreation();

	return out;
}

template <class T, int SIZE, bool COLORDERING>
Matrix<T, SIZE, COLORDERING> Matrix<T, SIZE, COLORDERING>::getLookAt(const Vector<T, 3>& eye, \
	const Vector<T, 3>& center, const Vector<T, 3>& up)
{
	
	Vector<T, 3> f(center - eye);
	f.normalized();
	Vector<T, 3> s;
	s = Vector<T, 3>::cross(f, up);
	s.normalized();
	Vector<T, 3> u;
	u = Vector<T, 3>::cross(s, f);

	Matrix<T, SIZE, COLORDERING> out;

	//out.startCreation();

	out(0, 0) = s.x();
	out(0, 1) = s.y();
	out(0, 2) = s.z();
	out(1, 0) = u.x();
	out(1, 1) = u.y();
	out(1, 2) = u.z();
	out(2, 0) = - f.x();
	out(2, 1) = - f.y();
	out(2, 2) = - f.z();

	out(0, 3) = - Vector<T, 3>::dot(s, eye);
	out(1, 3) = - Vector<T, 3>::dot(u, eye);
	out(2, 3) = Vector<T, 3>::dot(f, eye);

	//out.endCreation();

	return out;
}
