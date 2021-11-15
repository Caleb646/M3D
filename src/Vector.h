#pragma once

#include <iostream>

#include <Logi/Logi.h>

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
		value_type v[SIZE]{ 0 };

	public:
		//pass in int/float to fill vector
		Vector()
		{
			for (int i = 0; i < SIZE; i++)
			{
				v[i] = static_cast<T>(1);
			}
		}

		Vector(const Vector<T, SIZE>& v0)
		{

			ASSERT_ERROR(DEFAULT_LOGGABLE, validate(*this, v0) == true, "Dimensions do not match.");
			for (int i = 0; i < SIZE; i++)
			{
				v[i] = v0[i];
			}
		}

		Vector(T f)
		{
			for (int i = 0; i < SIZE; i++)
				v[i] = f;
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

		Vector(T arr[SIZE])
		{
			for (int i = 0; i < SIZE; i++)
				v[i] = arr[i];
		}

		Vector(const Vector<T, 2>& xy, T z, T w)
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE == 4, "Dimensions do not match.");
			v[0] = xy.x();
			v[1] = xy.y();
			v[2] = z;
			v[3] = w;
		}

		Vector(T x, const Vector<T, 2>& yz, T w)
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE == 4, "Dimensions do not match.");
			v[0] = x;
			v[1] = yz.x();
			v[2] = yz.y();
			v[3] = w;
		}

		Vector(T x, T y, const Vector<T, 2>& zw)
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE == 4, "Dimensions do not match.");
			v[0] = x;
			v[1] = y;
			v[2] = zw.x();
			v[3] = zw.y();
		}

		Vector(const Vector<T, 2>& xy, const Vector<T, 2>& zw)
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE == 4, "Dimensions do not match.");
			v[0] = xy.x();
			v[1] = xy.y();
			v[2] = zw.x();
			v[3] = zw.y();
		}

		Vector(const Vector<T, 3>& xyz, T w)
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE == 4, "Dimensions do not match.");
			v[0] = xyz.x();
			v[1] = xyz.y();
			v[2] = xyz.z();
			v[3] = w;
		}

		Vector(std::initializer_list<T> init_list)
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE == init_list.size(), "Dimensions do not match.");
			size_type c{ 0 };

			for (auto i : init_list)
			{
				v[c++] = static_cast<T>(i);
			}
		}
		~Vector() {}

		//Base Util Methods
		size_type getSize()
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
				stream << std::fixed << std::setprecision(2) << operator[] (i);
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

		inline T& operator[] (int index)
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, index < SIZE, "Dimensions do not match.");
			return v[index];
		}
		inline const T& operator [] (int index) const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, index < SIZE, "Dimensions do not match.");
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
			Vector<T, SIZE> out{};
			for (size_type i = 0; i < SIZE; i++)
			{
				out[i] = v[i] + v0[i];
			}
			return out;
		}

		inline Vector<T, SIZE> operator- (const Vector<T, SIZE>& v0)
		{
			Vector<T, SIZE> out;
			for (int i = 0; i < SIZE; i++)
			{
				out[i] = v[i] - v0[i];
			}
			return out;
		}

		inline Vector<T, SIZE> operator* (const Vector<T, SIZE>& v0)
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, validate(*this, v0), "Dimensions do not match.");
			Vector<T, SIZE> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				out[i] = v[i] * v0[i];
			}
			return out;
		}

		inline Vector<T, SIZE> operator* (float scale)
		{
			Vector<T, SIZE> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				out[i] = v[i] * scale;
			}
			return out;
		}

		inline Vector<T, SIZE> operator/ (float scale)
		{
			Vector<T, SIZE> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				out[i] = v[i] / scale;
			}
			return out;
		}

		inline Vector<T, SIZE>& operator+= (const Vector<T, SIZE>& v0)
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, validate(*this, v0), "Dimensions do not match.");
			for (size_type i = 0; i < SIZE; i++)
			{
				v[i] = v[i] + v0[i];
			}
			return *this;
		}

		inline Vector<T, SIZE>& operator-= (const Vector<T, SIZE>& v0)
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, validate(*this, v0), "Dimensions do not match.");
			for (size_type i = 0; i < SIZE; i++)
			{
				v[i] = v[i] - v0[i];
			}
			return *this;
		}

		inline Vector<T, SIZE>& operator*= (const Vector<T, SIZE>& v0)
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, validate(*this, v0), "Dimensions do not match.");
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
				v[i] = v0[i];
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
				for (size_type j = 0; j < SIZE; i++)
				{
					out[i] = -operator[][i];
				}
		}

		//Vector Util Methods
		T& x()
		{
			return v[0];
		}

		T& y()
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 2, "Dimensions do not match.");
			return v[1];
		}

		T& z()
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 3, "Dimensions do not match.");
			return v[2];
		}

		T& w()
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 4, "Dimensions do not match.");
			return v[3];
		}

		T x() const
		{
			return v[0];
		}

		T y() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 2, "Dimensions do not match.");
			return v[1];
		}

		T z() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 3, "Dimensions do not match.");
			return v[2];
		}

		T w() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 4, "Dimensions do not match.");
			return v[3];
		}

		Vector<T, 2> xy() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 2, "Dimensions do not match.");
			Vector<T, 2> out({ v[0], v[1] });
			return out;
		}

		Vector<T, 2> yz() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 2, "Dimensions do not match.");
			Vector<T, 2> out({ v[1], v[2] });
			return out;
		}

		Vector<T, 2> zw() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 2, "Dimensions do not match.");
			Vector<T, 2> out({ v[2], v[3] });
			return out;
		}

		Vector<T, 2> wx() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 2, "Dimensions do not match.");
			Vector<T, 2> out({ v[3], v[0] });
			return out;
		}


		Vector<T, 3> xyz() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 3, "Dimensions do not match.");
			Vector<T, 3> out({ v[0], v[1], v[2] });
			return out;
		}

		Vector<T, 3> yzw() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 4, "Dimensions do not match.");
			Vector<T, 3> out({ v[1], v[2], v[3] });
			return out;
		}

		Vector<T, 3> zwx() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 4, "Dimensions do not match.");
			Vector<T, 3> out({ v[2], v[3], v[0] });
			return out;
		}

		Vector<T, 3> wxy() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 4, "Dimensions do not match.");
			Vector<T, 3> out({ v[3], v[0], v[1] });
			return out;
		}

		Vector<T, 3> xyw() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 4, "Dimensions do not match.");
			Vector<T, 3> out({ v[0], v[1], v[3] });
			return out;
		}

		Vector<T, 3> yzx() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 3, "Dimensions do not match.");
			Vector<T, 3> out({ v[1], v[2], v[0] });
			return out;
		}

		Vector<T, 3> zwy() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 4, "Dimensions do not match.");
			Vector<T, 3> out({ v[2], v[3], v[1] });
			return out;
		}

		Vector<T, 3> wxz() const
		{
			ASSERT_ERROR(DEFAULT_LOGGABLE, SIZE >= 4, "Dimensions do not match.");
			Vector<T, 3> out({ v[3], v[0], v[2] });
			return out;
		}

		bool validate(const Vector<T, SIZE>& v1, const Vector<T, SIZE>& v2)
		{
			return true;
		}

		bool validate(const Vector<T, SIZE>& v, int requiredSized)
		{
			return true;
		}

		float getLength()
		{
			float l{ 0 };
			for (int i = 0; i < SIZE; i++)
				l = l + (v[i] * v[i]);
			return std::sqrtf(l);
		}

		Vector<T, SIZE> normalize()
		{
			float l{ getLength() };
			Vector<T, SIZE> out;
			for (int i = 0; i < SIZE; i++)
				out[i] = v[i] / l;
			return out;
		}

		void normalized()
		{
			float l{ getLength() };
			if (l == 0)
				return;
			for (int i = 0; i < SIZE; i++)
			{
				v[i] = v[i] / l;
			}
		}

		//Vector Static Math Operations
		static float dot(const Vector<T, SIZE>& v1, const Vector<T, SIZE>& v2)
		{
			float sum = static_cast<T>(0);
			for (int i = 0; i < SIZE; i++)
			{
				sum = sum + (v1[i] * v2[i]);
			}
			return sum;
		}

		static Vector<T, 3> cross(const Vector<T, 3>& v1, const Vector<T, 3>& v2)
		{
			Vector<T, 3> out;
			out[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
			out[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
			out[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
			return out;
		}
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

	template <typename T, std::size_t SIZE>
	inline bool operator== (const Vector<T, SIZE>& lhs, const Vector<T, SIZE>& rhs)
	{
		for (std::size_t i = 0; i < SIZE; i++)
		{
			if (lhs[i] != rhs[i])
				return false;
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

	typedef Vector<float, 2> Vec2f;
	typedef Vector<float, 3> Vec3f;
	typedef Vector<float, 4> Vec4f;

	typedef Vector<float, 2> TestVec2;
	typedef Vector<float, 3> TestVec3;
	typedef Vector<float, 4> TestVec4;

}