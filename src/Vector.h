#pragma once
#include <iostream>
//#include <immintrin.h>

#include "define.h"
#include "../Fwd.h"

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

namespace m3d
{

	template <typename T, std::size_t SIZE>
	class Vector {

	public:
		using size_type = std::size_t;
		using value_type = T;

	private:
		value_type v[SIZE]{ 0 };

	public:
		//pass in int/float to fill vector
		Vector()
		{
			for (std::size_t i = 0; i < SIZE; i++)
			{
				v[i] = static_cast<T>(1);
			}
		}

		Vector(const Vector<T, SIZE>& v0)
		{
			for (std::size_t i = 0; i < SIZE; i++)
			{
				v[i] = v0[i];
			}
		}

		Vector(T f)
		{
			for (std::size_t i = 0; i < SIZE; i++)
			{
				v[i] = f;
			}
		}

		Vector(T arr[SIZE])
		{
			for (std::size_t i = 0; i < SIZE; i++)
			{
				v[i] = arr[i];
			}
		}

		Vector(T x, T y, T z, T w)
		{
			v[0] = x;
			v[1] = y;
			v[2] = z;
			v[3] = w;
		}

		Vector(T x, T y, T z)
		{
			v[0] = x;
			v[1] = y;
			v[2] = z;
		}

		Vector(T x, T y)
		{
			v[0] = x;
			v[1] = y;
		}

		Vector(const Vector<T, 2>& xy, T z, T w)
		{
			MD_ASSERT(SIZE == 4);
			v[0] = xy.x();
			v[1] = xy.y();
			v[2] = z;
			v[3] = w;
		}

		Vector(T x, const Vector<T, 2>& yz, T w)
		{
			MD_ASSERT(SIZE == 4);
			v[0] = x;
			v[1] = yz.x();
			v[2] = yz.y();
			v[3] = w;
		}

		Vector(T x, T y, const Vector<T, 2>& zw)
		{
			MD_ASSERT(SIZE == 4);
			v[0] = x;
			v[1] = y;
			v[2] = zw.x();
			v[3] = zw.y();
		}

		Vector(const Vector<T, 2>& xy, const Vector<T, 2>& zw)
		{
			MD_ASSERT(SIZE == 4);
			v[0] = xy.x();
			v[1] = xy.y();
			v[2] = zw.x();
			v[3] = zw.y();
		}

		Vector(const Vector<T, 3>& xyz, T w)
		{
			MD_ASSERT(SIZE == 4);
			v[0] = xyz.x();
			v[1] = xyz.y();
			v[2] = xyz.z();
			v[3] = w;
		}

		~Vector() {}

		//Base Util Methods
		size_type size()
		{
			return SIZE;
		}

		void print()
		{
			for (int i = 0; i < SIZE; i++)
			{
				std::cout << v[i] << " ";
			}
			std::cout << std::endl;
		}

		std::string toString()
		{
			std::stringstream stream;
			for (int i = 0; i < SIZE; i++)
			{
				//stream << std::fixed << std::setprecision(2) << operator[] (i);
				stream << operator[] (i);
				stream << " ";
			}
			return stream.str();
		}

		/*
		*
		*
		*
		* VECTOR OPERATOR OVERLOADS
		*
		*
		*
		*/

		inline T& operator[] (std::size_t index)
		{
			MD_ASSERT(index < SIZE);
			return v[index];
		}
		inline const T& operator[] (std::size_t index) const
		{
			MD_ASSERT(index < SIZE);
			return v[index];
		}

		//OpenGl Conversion Operators
		inline operator const T* () const
		{
			return v;
		}

		inline operator T* ()
		{
			return v;
		}

		inline Vector<T, SIZE> operator+ (const Vector<T, SIZE>& v0)
		{
			Vector<T, SIZE> out(*this);
			return out += v0;
		}

		inline Vector<T, SIZE> operator- (const Vector<T, SIZE>& v0)
		{
			Vector<T, SIZE> out(*this);
			return out -= v0;
		}

		inline Vector<T, SIZE> operator* (const Vector<T, SIZE>& v0)
		{
			Vector<T, SIZE> out(*this);
			return out *= v0;
		}

		inline Vector<T, SIZE> operator* (float scaler)
		{
			Vector<T, SIZE> out(*this);
			return out *= scaler;
		}

		inline Vector<T, SIZE> operator/ (float scaler)
		{
			Vector<T, SIZE> out(*this);
			return out /= scaler;
		}

		inline Vector<T, SIZE>& operator+= (const Vector<T, SIZE>& v0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				v[i] = v[i] + v0[i];
			}
			return *this;
		}

		inline Vector<T, SIZE>& operator-= (const Vector<T, SIZE>& v0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				v[i] = v[i] - v0[i];
			}
			return *this;
		}

		//if row and col params are added to Matrix template
		//template this function to accept them
		inline Vector<T, SIZE>& operator*= (const Matrix<T, SIZE>& m0)
		{
			Vector<T, SIZE> out(static_cast<T>(0));
			for (std::size_t i = 0; i < SIZE; i++)
			{
				for (std::size_t j = 0; j < SIZE; j++)
				{
					out[i] += operator[](j) * m0[i][j];
				}
			}
			*this = out;
			return *this;
		}

		inline Vector<T, SIZE>& operator*= (const Vector<T, SIZE>& v0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				v[i] = v[i] * v0[i];
			}
			return *this;
		}

		inline Vector<T, SIZE>& operator*= (float scale)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				v[i] = v[i] * scale;
			}
			return *this;
		}

		inline Vector<T, SIZE>& operator/= (float scale)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				v[i] = v[i] / scale;
			}
			return *this;
		}

		inline Vector<T, SIZE>& operator= (const Vector<T, SIZE>& v0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				v[i] = v0[i];
			}
				
			return *this;
		}

		/*
		*
		* UNARY VECTOR OPERATOR
		*
		*/

		Vector<T, SIZE> operator-()
		{
			Vector<T, SIZE> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				out[i] = -operator[](i);
			}
				
		}

		//Vector Util Methods
		T& x()
		{
			return v[0];
		}

		T& y()
		{
			MD_ASSERT(SIZE >= 2);
			return v[1];
		}

		T& z()
		{
			MD_ASSERT(SIZE >= 3);
			return v[2];
		}

		T& w()
		{
			MD_ASSERT(SIZE >= 4);
			return v[3];
		}

		T x() const
		{
			return v[0];
		}

		T y() const
		{
			MD_ASSERT(SIZE >= 2);
			return v[1];
		}

		T z() const
		{
			MD_ASSERT(SIZE >= 3);
			return v[2];
		}

		T w() const
		{
			MD_ASSERT(SIZE >= 4);
			return v[3];
		}

		Vector<T, 2> xy() const
		{
			MD_ASSERT(SIZE >= 2);
			return { v[0], v[1] };
		}

		Vector<T, 2> yz() const
		{
			MD_ASSERT(SIZE >= 2);
			return { v[1], v[2] };
		}

		Vector<T, 2> zw() const
		{
			MD_ASSERT(SIZE >= 2);
			Vector<T, 2> out({ v[2], v[3] });
			return out;
		}

		Vector<T, 2> wx() const
		{
			MD_ASSERT(SIZE >= 2);
			Vector<T, 2> out({ v[3], v[0] });
			return out;
		}


		Vector<T, 3> xyz() const
		{
			MD_ASSERT(SIZE >= 3);
			Vector<T, 3> out({ v[0], v[1], v[2] });
			return out;
		}

		Vector<T, 3> yzw() const
		{
			MD_ASSERT(SIZE >= 4);
			Vector<T, 3> out({ v[1], v[2], v[3] });
			return out;
		}

		Vector<T, 3> zwx() const
		{
			MD_ASSERT(SIZE >= 4);
			Vector<T, 3> out({ v[2], v[3], v[0] });
			return out;
		}

		Vector<T, 3> wxy() const
		{
			MD_ASSERT(SIZE >= 4);
			Vector<T, 3> out({ v[3], v[0], v[1] });
			return out;
		}

		Vector<T, 3> xyw() const
		{
			MD_ASSERT(SIZE >= 4);
			Vector<T, 3> out({ v[0], v[1], v[3] });
			return out;
		}

		Vector<T, 3> yzx() const
		{
			MD_ASSERT(SIZE >= 3);
			Vector<T, 3> out({ v[1], v[2], v[0] });
			return out;
		}

		Vector<T, 3> zwy() const
		{
			MD_ASSERT(SIZE >= 4);
			Vector<T, 3> out({ v[2], v[3], v[1] });
			return out;
		}

		Vector<T, 3> wxz() const
		{
			MD_ASSERT(SIZE >= 4);
			Vector<T, 3> out({ v[3], v[0], v[2] });
			return out;
		}
	};

	/*
	*
	*
	* NON-MEMBER FUNCTIONS
	*
	*
	*/
	template<typename T, std::size_t SIZE>
	T length(const Vector<T, SIZE>& v)
	{
		return static_cast<T>(std::sqrtf(dot(v, v)));
	}

	template<typename T, std::size_t SIZE>
	Vector<T, SIZE> normalize(const Vector<T, SIZE>& v)
	{
		T l{ length(v) };
		Vector<T, SIZE> out;
		for (std::size_t i = 0; i < SIZE; i++)
		{
			out[i] = v[i] / l;
		}

		return out;
	}

	template<typename T, std::size_t SIZE>
	T dot(const Vector<T, SIZE>& v1, const Vector<T, SIZE>& v2)
	{
		T sum = static_cast<T>(0);
		for (std::size_t i = 0; i < SIZE; i++)
		{
			sum = sum + (v1[i] * v2[i]);
		}
		return sum;
	}

	/*
	*
	*
	* SPECIALIZED FUNCTIONS
	*
	*
	*/
	template<typename T>
	Vector<T, 3>  cross(const Vector<T, 3>& v1, const Vector<T, 3>& v2)
	{
		Vector<T, 3> out{};
		out[0] = (v1.y() * v2.z()) - (v1.z() * v2.y());
		out[1] = (v1.z() * v2.x()) - (v1.x() * v2.z());
		out[2] = (v1.x() * v2.y()) - (v1.y() * v2.x());
		return out;
	}


	/*
	*
	*
	* NON MEMBER OPERATORS
	*
	*
	*/
	template <typename T, std::size_t SIZE>
	inline bool operator== (const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs)
	{
		for (std::size_t i = 0; i < SIZE; i++)
		{
			if (lhs[i] != rhs[i])
			{
				return false;
			}	
		}
		return true;
	}

	template <typename T, std::size_t SIZE>
	inline bool operator!= (const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T, std::size_t SIZE>
	Vector<T, SIZE> operator- (const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs)
	{
		Vector<T, SIZE> out;
		for (std::size_t i = 0; i < SIZE; i++)
		{
			out[i] = lhs[i] - rhs[i];
		}

		return out;
	}

	template <typename T, std::size_t SIZE>
	Vector<T, SIZE> operator+ (const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs)
	{
		Vector<T, SIZE> out;
		for (std::size_t i = 0; i < SIZE; i++)
		{
			out[i] = lhs[i] + rhs[i];
		}

		return out;
	}

	template <typename T, std::size_t SIZE>
	Vector<T, SIZE> operator * (const Vector<T, SIZE>& lhs, float scaler)
	{
		Vector<T, SIZE> out;
		for (std::size_t i = 0; i < SIZE; i++)
		{
			out[i] = lhs[i] * scaler;
		}

		return out;
	}

	template <typename T, std::size_t SIZE>
	Vector<T, SIZE> operator * (float scaler, const Vector<T, SIZE>& rhs)
	{
		Vector<T, SIZE> out;
		for (std::size_t i = 0; i < SIZE; i++)
		{
			out[i] = scaler * rhs[i];
		}

		return out;
	}

	template <typename T, std::size_t SIZE>
	Vector<T, SIZE> operator / (const Vector<T, SIZE>& lhs, float scaler)
	{
		Vector<T, SIZE> out;
		for (std::size_t i = 0; i < SIZE; i++)
		{
			out[i] = lhs[i] / scaler;
		}

		return out;
	}

	/*
	*
	* TYPE DEFINITIONS
	*
	*
	*/
	typedef Vector<float, 2> vec2f;
	typedef Vector<float, 3> vec3f;
	typedef Vector<float, 4> vec4f;
}