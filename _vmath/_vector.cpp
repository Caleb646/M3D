#include <iomanip>
#include <sstream>

#include "_vector.h"
#include "../_logging/_log.h"

//pass in int/float to fill vector
template <class T, int SIZE>
Vector<T, SIZE>::Vector()
{
	for (int i = 0; i < SIZE; i++)
	{
		v[i] = static_cast<T>(1);
	}
}

template <class T, int SIZE>
Vector<T, SIZE>::Vector(T x, T y, T z, T w)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = w;
}

template <class T, int SIZE>
Vector<T, SIZE>::Vector(T x, T y, T z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

template <class T, int SIZE>
Vector<T, SIZE>::Vector(T x, T y)
{
	v[0] = x;
	v[1] = y;
}

template <class T, int SIZE>
Vector<T, SIZE>::Vector(const Vector<T, SIZE>& v0)
{
	if(!validate(*this, v0))
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR DIMS DONT MATCH");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < SIZE; i++)
	{
		v[i] = v0[i];
	}
}

template <class T, int SIZE>
Vector<T, SIZE>::Vector(T f)
{
	for (int i = 0; i < SIZE; i++)
		v[i] = f;
}
template <class T, int SIZE>
Vector<T, SIZE>::Vector(T arr[SIZE])
{
	for (int i = 0; i < SIZE; i++)
		v[i] = arr[i];
}

template <class T, int SIZE>
Vector<T, SIZE>::Vector(const Vector<T, 2>& xy, T z, T w)
{
	if (SIZE != 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT THE RIGHT SIZE. MUST BE OF SIZE 4");
		exit(EXIT_FAILURE);
	}
	v[0] = xy.x();
	v[1] = xy.y();
	v[2] = z;
	v[3] = w;
}

template <class T, int SIZE>
Vector<T, SIZE>::Vector(T x, const Vector<T, 2>& yz, T w)
{
	if (SIZE != 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT THE RIGHT SIZE. MUST BE OF SIZE 4");
		exit(EXIT_FAILURE);
	}
	v[0] = x;
	v[1] = yz.x();
	v[2] = yz.y();
	v[3] = w;
}

template <class T, int SIZE>
Vector<T, SIZE>::Vector(T x, T y, const Vector<T, 2>& zw)
{
	if (SIZE != 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT THE RIGHT SIZE. MUST BE OF SIZE 4");
		exit(EXIT_FAILURE);
	}
	v[0] = x;
	v[1] = y;
	v[2] = zw.x();
	v[3] = zw.y();
}

template <class T, int SIZE>
Vector<T, SIZE>::Vector(const Vector<T, 2>& xy, const Vector<T, 2>& zw)
{
	if (SIZE != 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT THE RIGHT SIZE. MUST BE OF SIZE 4");
		exit(EXIT_FAILURE);
	}
	v[0] = xy.x();
	v[1] = xy.y();
	v[2] = zw.x();
	v[3] = zw.y();
}

template <class T, int SIZE>
Vector<T, SIZE>::Vector(const Vector<T, 3>& xyz, T w)
{
	if (SIZE != 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT THE RIGHT SIZE. MUST BE OF SIZE 4");
		exit(EXIT_FAILURE);
	}
	v[0] = xyz.x();
	v[1] = xyz.y();
	v[2] = xyz.z();
	v[3] = w;
}

template <class T, int SIZE>
Vector<T, SIZE>::Vector(std::initializer_list<T> init_list)
{
	if (SIZE != init_list.size())
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "INIT LIST IS NOT THE RIGHT SIZE. MUST BE OF SIZE 4");
		exit(EXIT_FAILURE);
	}
	int c = 0;
	for (auto i = init_list.begin(); i != init_list.end(); i++) {
		v[c++] = static_cast<T>(*i);
	}
}

template <class T, int SIZE>
Vector<T, SIZE>::~Vector()
{

}

//Base Util Methods
template <class T, int SIZE>
int Vector<T, SIZE>::getSize()
{
	return SIZE;
}

template <class T, int SIZE>
void Vector<T, SIZE>::print()
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

template <class T, int SIZE>
std::string Vector<T, SIZE>::toString()
{
	std::stringstream stream;
	for (int i = 0; i < SIZE; i++)
	{
		stream << std::fixed << std::setprecision(2) << this->operator[] (i);
		stream << " ";
	}
	return stream.str();
}

template <class T, int SIZE>
inline T& Vector<T, SIZE>::operator[](size_t index)
{
	if (index >= SIZE)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "INDEX IS OUT OF BOUNDS");
		exit(EXIT_FAILURE);
	}
	return v[index];
}

template <class T, int SIZE>
inline const T& Vector<T, SIZE>::operator [] (size_t index) const
{
	if (index >= SIZE)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "INDEX IS OUT OF BOUNDS");
		exit(EXIT_FAILURE);
	}
	return v[index];
}

//Vector Util Methods
template <class T, int SIZE>
T& Vector<T, SIZE>::x()
{
	return v[0];
}

template <class T, int SIZE>
T& Vector<T, SIZE>::y()
{
	if (SIZE < 2)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR HAS NO Y COMPONENT");
		exit(EXIT_FAILURE);
	}
	return v[1];
}

template <class T, int SIZE>
T& Vector<T, SIZE>::z()
{
	if (SIZE < 3)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR HAS NO Y COMPONENT");
		exit(EXIT_FAILURE);
	}
	return v[2];
}

template <class T, int SIZE>
T& Vector<T, SIZE>::w()
{
	if (SIZE < 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR HAS NO W COMPONENT");
		exit(EXIT_FAILURE);
	}
	return v[3];
}

template <class T, int SIZE>
T Vector<T, SIZE>::x() const
{
	return v[0];
}

template <class T, int SIZE>
T Vector<T, SIZE>::y() const
{
	if (SIZE < 2)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR HAS NO Y COMPONENT");
		exit(EXIT_FAILURE);
	}
	return v[1];
}

template <class T, int SIZE>
T Vector<T, SIZE>::z() const
{
	if (SIZE < 3)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR HAS NO Y COMPONENT");
		exit(EXIT_FAILURE);
	}
	return v[2];
}

template <class T, int SIZE>
T Vector<T, SIZE>::w() const
{
	if (SIZE < 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR HAS NO W COMPONENT");
		exit(EXIT_FAILURE);
	}
	return v[3];
}

template <class T, int SIZE>
Vector<T, 2> Vector<T, SIZE>::xy() const
{
	if (SIZE < 2)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 2> out({ v[0], v[1] });
	return out;
}

template <class T, int SIZE>
Vector<T, 2> Vector<T, SIZE>::yz() const
{
	if (SIZE < 2)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 2> out({ v[1], v[2] });
	return out;
}

template <class T, int SIZE>
Vector<T, 2> Vector<T, SIZE>::zw() const
{
	if (SIZE < 2)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 2> out({ v[2], v[3] });
	return out;
}

template <class T, int SIZE>
Vector<T, 2> Vector<T, SIZE>::wx() const
{
	if (SIZE < 2)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 2> out({ v[3], v[0] });
	return out;
}

template <class T, int SIZE>
Vector<T, 3> Vector<T, SIZE>::xyz() const
{
	if (SIZE < 3)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 3> out({ v[0], v[1], v[2] });
	return out;
}

template <class T, int SIZE>
Vector<T, 3> Vector<T, SIZE>::yzw() const
{
	if (SIZE < 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 3> out({ v[1], v[2], v[3] });
	return out;
}

template <class T, int SIZE>
Vector<T, 3> Vector<T, SIZE>::zwx() const
{
	if (SIZE < 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 3> out({ v[2], v[3], v[0] });
	return out;
}

template <class T, int SIZE>
Vector<T, 3> Vector<T, SIZE>::wxy() const
{
	if (SIZE < 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 3> out({ v[3], v[0], v[1] });
	return out;
}

template <class T, int SIZE>
Vector<T, 3> Vector<T, SIZE>::xyw() const
{
	if (SIZE < 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 3> out({ v[0], v[1], v[3] });
	return out;
}

template <class T, int SIZE>
Vector<T, 3> Vector<T, SIZE>::yzx() const
{
	if (SIZE < 3)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 3> out({ v[1], v[2], v[0] });
	return out;
}

template <class T, int SIZE>
Vector<T, 3> Vector<T, SIZE>::zwy() const
{
	if (SIZE < 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 3> out({ v[2], v[3], v[1] });
	return out;
}

template <class T, int SIZE>
Vector<T, 3> Vector<T, SIZE>::wxz() const
{
	if (SIZE < 4)
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTOR IS NOT LARGE ENOUGH");
		exit(EXIT_FAILURE);
	}
	Vector<T, 3> out({ v[3], v[0], v[2] });
	return out;
}
/*
*
* 
* 
* 
* 
* 
* 
* VECTOR BASE UTILS
*
*
*
*
*
*
*/

template <class T, int SIZE>
bool Vector<T, SIZE>::validate(const Vector<T, SIZE>& v1, const Vector<T, SIZE>& v2)
{
	return true;
}

template <class T, int SIZE>
bool Vector<T, SIZE>::validate(const Vector<T, SIZE>& v, int requiredSized)
{
	return true;
}

template <class T, int SIZE>
float Vector<T, SIZE>::getLength()
{
	float l = 0;
	for (int i = 0; i < SIZE; i++)
		l = l + (v[i] * v[i]);
	return std::sqrtf(l);
}

template <class T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::normalize()
{
	float l = getLength();
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
		out[i] = v[i] / l;
	return out;
}

template <class T, int SIZE>
void Vector<T, SIZE>::normalized()
{
	float l = getLength();
	if (l == 0)
		return;
	for (int i = 0; i < SIZE; i++)
	{
		v[i] = v[i] / l;
	}
}

/*
*
* 
* 
* 
* 
* 
* END VECTOR BASE UTILS
*
*
*
*
*
*
*/

/*
*
* 
* 
* 
* 
* 
* VECTOR OPERATORS
* 
* 
* 
* 
* 
* 
*/

//template<class T, int SIZE>
//Vector<T, SIZE>& Vector<T, SIZE>::operator = (const Vector<T, SIZE>& v0)
//{
//	if (this != &v0)
//	{
//		for (int i = 0; i < v0.SIZE; i++)
//			v[i] = v0[i];
//	}
//	return *this;
//}

template <class T, int SIZE>
inline Vector<T, SIZE> Vector<T, SIZE>::operator + (const Vector<T, SIZE>& v0)
{
	Vector<T, SIZE> out{};
	for (int i = 0; i < SIZE; i++)
	{
		out[i] = v[i] + v0[i];
	}
	return out;
}

template <class T, int SIZE>
inline Vector<T, SIZE> Vector<T, SIZE>::operator - (const Vector<T, SIZE>& v0)
{
	//if (!validate(*this, v0))
	//{
	//	logError(__FILE__, __FUNCTION__, __LINE__, "VECTORS MUST BE THE SAME SIZE");
	//	exit(EXIT_FAILURE);
	//}
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
	{
		out[i] = v[i] - v0[i];
	}
	return out;
}

template <class T, int SIZE>
inline Vector<T, SIZE> Vector<T, SIZE>::operator * (const Vector<T, SIZE>& v0)
{
	if (!validate(*this, v0))
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTORS MUST BE THE SAME SIZE");
		exit(EXIT_FAILURE);
	}
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
	{
		out[i] = v[i] * v0[i];
	}
	return out;
}

template <class T, int SIZE>
inline Vector<T, SIZE> Vector<T, SIZE>::operator * (float scale)
{
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
	{
		out[i] = v[i] * scale;
	}
	return out;
}

template <class T, int SIZE>
inline Vector<T, SIZE> Vector<T, SIZE>::operator / (float scale)
{
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
	{
		out[i] = v[i] / scale;
	}
	return out;
}

template <class T, int SIZE>
inline Vector<T, SIZE>& Vector<T, SIZE>::operator += (const Vector<T, SIZE>& v0)
{
	if (!validate(*this, v0))
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTORS MUST BE THE SAME SIZE");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < SIZE; i++)
	{
		v[i] = v[i] + v0[i];
	}
	return *this;
}

template <class T, int SIZE>
inline Vector<T, SIZE>& Vector<T, SIZE>::operator -= (const Vector<T, SIZE>& v0)
{
	if (!validate(*this, v0))
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTORS MUST BE THE SAME SIZE");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < SIZE; i++)
	{
		v[i] = v[i] - v0[i];
	}
	return *this;
}

template <class T, int SIZE>
inline Vector<T, SIZE>& Vector<T, SIZE>::operator *= (const Vector<T, SIZE>& v0)
{
	if (!validate(*this, v0))
	{
		logError(__FILE__, __FUNCTION__, __LINE__, "VECTORS MUST BE THE SAME SIZE");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < SIZE; i++)
	{
		v[i] = v[i] * v0[i];
	}
	return *this;
}

template <class T, int SIZE>
inline Vector<T, SIZE>& Vector<T, SIZE>::operator *= (float scale)
{
	for (int i = 0; i < SIZE; i++)
	{
		v[i] = v[i] * scale;
	}
	return *this;
}

template <class T, int SIZE>
inline Vector<T, SIZE>& Vector<T, SIZE>::operator /= (float scale)
{
	for (int i = 0; i < SIZE; i++)
	{
		v[i] = v[i] / scale;
	}
	return *this;
}

template <class T, int SIZE>
inline Vector<T, SIZE>& Vector<T, SIZE>::operator = (const Vector<T, SIZE>& v0)
{
	for (int i = 0; i < SIZE; i++)
		v[i] = v0[i];
	return *this;
}

// OpenGl Conversion Operators
template <class T, int SIZE>
inline Vector<T, SIZE>::operator const T* () const
{
	return v;
	//return *this;
}

template <class T, int SIZE>
inline Vector<T, SIZE>::operator T* ()
{
	return v;
	//return *this;
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

/*
*
* EQUALITY VECTOR OPERATOR
*
*/
template <class T, int SIZE>
inline bool operator==(const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs)
{
	for(int i = 0; i < SIZE; i++)
	{
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

template <class T, int SIZE>
inline bool operator!=(const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs)
{
	return !(lhs == rhs);
}

template <class T, int SIZE>
Vector<T, SIZE> operator + (const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs)
{
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
	{
		out[i] = lhs[i] + rhs[i];
	}

	return out;
}

template <class T, int SIZE>
Vector<T, SIZE> operator - (const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs)
{
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
	{
		out[i] = lhs[i] - rhs[i];
	}

	return out;
}

template <class T, int SIZE>
Vector<T, SIZE> operator * (const Vector<T, SIZE>& lhs, float scaler)
{
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
	{
		out[i] = lhs[i] * scaler;
	}

	return out;
}

template <class T, int SIZE>
Vector<T, SIZE> operator * (float scaler, const Vector<T, SIZE>& rhs)
{
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
	{
		out[i] =  scaler * rhs[i];
	}

	return out;
}

template <class T, int SIZE>
Vector<T, SIZE> operator / (const Vector<T, SIZE>& lhs, float scaler)
{
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
	{
		out[i] = lhs[i] / scaler;
	}

	return out;
}

/*
*
* UNARY MATRIX OPERATOR OVERLOADS
*
*/

template <class T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator- ()
{
	Vector<T, SIZE> out;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; i++)
		{
			out[i] = -this->operator[][i];
		}
}

/*
*
* 
* END VECTOR OPERATORS
* 
* 
*/

/*
*
* VECTOR STATIC METHODS
* 
* 
* 
*/

template <class T, int SIZE>
float Vector<T, SIZE>::dot(const Vector<T, SIZE>& v1, const Vector<T, SIZE>& v2)
{
	float sum = static_cast<T>(0);
	for (int i = 0; i < SIZE; i++)
	{
		sum = sum + (v1[i] * v2[i]);
	}
	return sum;
}

template <class T, int SIZE>
Vector<T, 3> Vector<T, SIZE>::cross(const Vector<T, 3>& v1, const Vector<T, 3>& v2)
{
	Vector<T, 3> out;
	out[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
	out[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
	out[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
	return out;
}


