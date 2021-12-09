#pragma once
#include "Vector.h"

#include <vector>

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
	class Matrix
	{
	public:	
		using size_type = std::size_t;
		using value_type = T;
		using vector_type = Vector<value_type, SIZE>;
		using mat_t = Matrix;
	private:
		vector_type mat[SIZE]{};

	public:
		Matrix()
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				vector_type v( static_cast<value_type>(0) );
				v[i] = static_cast<value_type>(1);
				operator[](i) = v;
			}
		}


		Matrix(T f)
		{

			for (size_type i = 0; i < SIZE; i++)
			{
				vector_type v(static_cast<value_type>(0));
				v[i] = f;
				operator[](i) = v;
			}
		}

		Matrix(const std::vector<std::vector<T>>& vec)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				vector_type v(vec[i]);
				operator[](i) = v;
			}
		}

		Matrix(T arr[SIZE][SIZE])
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				vector_type v(arr[i]);
				operator[](i) = v;
			}
		}

		Matrix(const Matrix<T, SIZE>& m)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				operator[](i) = m[i];
			}
		}

		~Matrix() {}

		size_type size()
		{
			return SIZE;
		}

		void print()
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				std::cout << "||" << operator[](i).print() << "||" << std::endl;
			}
			std::cout << std::endl;
		}

		std::string toString()
		{
			std::stringstream stream;
			for (int i = 0; i < SIZE; i++)
			{
				stream << "||";
				stream << operator[](i).toString();
				stream << "||";
				stream << "\n";
			}
			return stream.str();
		}

		/*
		*
		* 
		* OPERATOR OVERLOADS
		* 
		*
		*/
		vector_type& operator[] (size_type index)
		{
			return mat[index];
		}

		const vector_type& operator[] (size_type index) const
		{
			return mat[index];
		}

		Matrix<T, SIZE>& operator= (const Matrix<T, SIZE>& m0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				operator[](i) = m0[i];
			}
			return *this;
		}

		Matrix<T, SIZE> operator+ (const Matrix<T, SIZE>& m0)
		{
			Matrix<T, SIZE> out(*this);
			return out += m0;
		}

		Matrix<T, SIZE> operator- (const Matrix<T, SIZE>& m0)
		{
			Matrix<T, SIZE> out(*this);
			return out -= m0;
		}

		Matrix<T, SIZE> operator* (const Matrix<T, SIZE>& m0)
		{
			Matrix<T, SIZE> out(*this);
			return out *= m0;
		}

		Matrix<T, SIZE> operator* (float scaler)
		{
			Matrix<T, SIZE> out(*this);
			return out *= scaler;
		}

		Matrix<T, SIZE> operator/ (float scaler)
		{
			Matrix<T, SIZE> out(*this);
			return out /= scaler;
		}

		Matrix<T, SIZE> operator+= (const Matrix<T, SIZE>& m0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				operator[](i) += m0[i];
			}
			return *this;
		}

		Matrix<T, SIZE> operator-= (const Matrix<T, SIZE>& m0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				operator[](i) -= m0[i];
			}
			return *this;
		}

		Matrix<T, SIZE> operator*= (const Matrix<T, SIZE>& m0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					value_type row{ static_cast<value_type>(0) };
					for (size_type z = 0; z < SIZE; z++)
					{
						row = row + operator[](i)[j] * m0[j][z];
					}
					operator[](i)[j] = row;
				}
			}
			return *this;
		}

		Matrix<T, SIZE> operator*= (float scaler)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				operator[](i) *= scaler;
			}
			return *this;
		}

		Matrix<T, SIZE> operator/= (float scaler)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				operator[](i) /= scaler;
			}
			return *this;
		}

		/*
		*
		* UNARY MATRIX OPERATOR OVERLOADS
		*
		*/

		Matrix<T, SIZE>& operator- ()
		{
			Matrix<T, SIZE> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				operator[](i) = -operator[](i);
			}
			return *this;
		}

		//when converting to float* return the mat array
		//example: float *ptr; Mat4f mat; ptr = (float*) mat; would
		//call one of these functions.
		operator const value_type* () const
		{
			//return *mat;
			return &mat[0][0];
		}
		operator value_type* ()
		{
			//return *mat;
			return &mat[0][0];
		}

		private:
			/**
			 * @brief
			*/
			value_type& operator() (size_type row, size_type col)
			{
				MD_ASSERT(row < SIZE&& col < SIZE);
				return operator[](row)[col];
			}

			const value_type& operator ()(size_type row, size_type col) const
			{
				MD_ASSERT(row < SIZE&& col < SIZE);
				return operator[](row)[col];
			}
	};


	/**
	* 
	* 
	* NON-MEMBER FUNCTIONS
	* 
	* 
	*/
	template<typename T, std::size_t SIZE>
	Matrix<T, SIZE> transpose(const Matrix<T, SIZE>& m0)
	{
		//TODO THIS DOES NOT WORK
		Matrix<T, SIZE> out;
		for (std::size_t i = 0; i < SIZE; i++)
		{
			for (std::size_t j = 0; j < SIZE; j++)
			{
				out(i, j) = m0(j, i);
			}
		}
		return out;
	}

	template<typename T, std::size_t SIZE>
	Matrix<T, SIZE> translate(const Matrix<T, SIZE>& m, const Vector<T, SIZE>& v)
	{
		Matrix<T, SIZE> out;
		for (std::size_t i = 0; i < SIZE; i++)
		{
			out[SIZE - 1] += m[i] * v[i];
		}
		return out;
	}


	/*
	* 
	* 
	* SPECIALIZATION FUNCTIONS
	* 
	* 
	*/
	template<typename T>
	Matrix<T, 4> perspective_ROW(T angle, T aspect, T zNear, T zFar)
	{
		Matrix<T, 4> out;
		float half{ std::tanf(angle / static_cast<T>(2)) };
		out[0][0] = static_cast<T>(1) / (aspect * half);
		out[1][1] = static_cast<T>(1) / half;
		out[2][2] = zFar / (zNear - zFar);
		out[3][2] = -(static_cast<T>(1)); //3, 2
		out[2][3] = -((static_cast<T>(2) * zFar * zNear) / (zFar - zNear)); // 2, 3
		out[3][3] = static_cast<T>(0);
		return out;
	}

	template<typename T>
	Matrix<T, 4> perspective_ROW_Depth01(T angle, T aspect, T zNear, T zFar)
	{
		Matrix<T, 4> out;
		float half{ std::tanf(angle / static_cast<T>(2)) };
		out[0][0] = static_cast<T>(1) / (aspect * half);
		out[1][1] = static_cast<T>(1) / (half);
		out[2][2] = zFar / (zNear - zFar);
		out[3][2] = -static_cast<T>(1);
		out[2][3] = -(zFar * zNear) / (zFar - zNear);
		out[3][3] = static_cast<T>(0);
		return out;
	}

	template<typename T>
	Matrix<T, 4> perspective_COL(T angle, T aspect, T zNear, T zFar)
	{
		Matrix<T, 4> out;
		float half{ std::tanf(angle / static_cast<T>(2)) };
		out[0][0] = static_cast<T>(1) / (aspect * half);
		out[1][1] = static_cast<T>(1) / half;
		out[2][2] = zFar / (zNear - zFar);
		out[2][3] = -(static_cast<T>(1)); //3, 2
		out[3][2] = -((static_cast<T>(2) * zFar * zNear) / (zFar - zNear)); // 2, 3
		out[3][3] = static_cast<T>(0);
		return out;
	}

	template<typename T>
	Matrix<T, 4> perspective_COL_Depth01(T angle, T aspect, T zNear, T zFar)
	{
		Matrix<T, 4> out;
		float half{ std::tanf(angle / static_cast<T>(2)) };
		out[0][0] = static_cast<T>(1) / (aspect * half);
		out[1][1] = static_cast<T>(1) / (half);
		out[2][2] = zFar / (zNear - zFar);
		out[2][3] = -static_cast<T>(1);
		out[3][2] = -(zFar * zNear) / (zFar - zNear);
		out[3][3] = static_cast<T>(0);
		return out;
	}

	template<typename T>
	Matrix<T, 4> perspective(T angle, T aspect, T zNear, T zFar)
	{
		if constexpr (md_config::FORCE_COL_ORDERING == md_config::DISABLED && md_config::FORCE_DEPTH_ZERO_TO_ONE == md_config::DISABLED)
		{
			return perspective_ROW(angle, aspect, zNear, zFar);
		}

		else if constexpr (md_config::FORCE_COL_ORDERING == md_config::DISABLED && md_config::FORCE_DEPTH_ZERO_TO_ONE == md_config::ENABLED)
		{
			return perspective_ROW_Depth01(angle, aspect, zNear, zFar);
		}

		else if constexpr (md_config::FORCE_COL_ORDERING == md_config::ENABLED && md_config::FORCE_DEPTH_ZERO_TO_ONE == md_config::DISABLED)
		{
			return perspective_COL(angle, aspect, zNear, zFar);
		}

		else if constexpr (md_config::FORCE_COL_ORDERING == md_config::ENABLED && md_config::FORCE_DEPTH_ZERO_TO_ONE == md_config::ENABLED)
		{
			return perspective_COL_Depth01(angle, aspect, zNear, zFar);
		}
		else
		{
			MD_ASSERT(false); //improper config;
		}
	}

	template<typename T>
	Matrix<T, 4> rotate_COL(T angle, const Vector<T, 3>& _axis, const Matrix<T, 4>& m = Matrix<T, 4>(static_cast<T>(1)))
	{
		//TODO
		T const a = angle;
		T const c = std::cos(a);
		T const s = std::sin(a);

		Vector<T, 3> axis = normalize(_axis);
		Vector<T, 3> temp((static_cast<T>(1) - c) * axis);

		Matrix<T, 4> rotation;
		//
		rotation[0][0] = c + temp[0] * axis[0];
		rotation[0][1] = temp[0] * axis[1] + s * axis[2];
		rotation[0][2] = temp[0] * axis[2] - s * axis[1];

		rotation[1][0] = temp[1] * axis[0] - s * axis[2];
		rotation[1][1] = c + temp[1] * axis[1];
		rotation[1][2] = temp[1] * axis[2] + s * axis[0];

		rotation[2][0] = temp[2] * axis[0] + s * axis[1];
		rotation[2][1] = temp[2] * axis[1] - s * axis[0];
		rotation[2][2] = c + temp[2] * axis[2];

		Matrix<T, 4> out;
		out[0] = m[0] * rotation[0][0] + m[1] * rotation[0][1] + m[2] * rotation[0][2];
		out[1] = m[0] * rotation[1][0] + m[1] * rotation[1][1] + m[2] * rotation[1][2];
		out[2] = m[0] * rotation[2][0] + m[1] * rotation[2][1] + m[2] * rotation[2][2];
		out[3] = m[3];
		return out;
	}

	template<typename T>
	Matrix<T, 4> rotate_ROW(T angle, const Vector<T, 3>& _axis, const Matrix<T, 4>& m = Matrix<T, 4>(static_cast<T>(1)))
	{
		//TODO
		T const a = angle;
		T const c = std::cos(a);
		T const s = std::sin(a);

		Vector<T, 3> axis = normalize(_axis);

		Vector<T, 3> temp((static_cast<T>(1) - c) * axis);

		Matrix<T, 4> rotation;
		//
		rotation[0][0] = c + temp[0] * axis[0];
		rotation[1][0] = temp[0] * axis[1] + s * axis[2];
		rotation[2][0] = temp[0] * axis[2] - s * axis[1];

		rotation[0][1] = temp[1] * axis[0] - s * axis[2];
		rotation[1][1] = c + temp[1] * axis[1];
		rotation[2][1] = temp[1] * axis[2] + s * axis[0];

		rotation[0][2] = temp[2] * axis[0] + s * axis[1];
		rotation[1][2] = temp[2] * axis[1] - s * axis[0];
		rotation[2][2] = c + temp[2] * axis[2];

		Matrix<T, 4> out;
		out[0] = m[0] * rotation[0][0] + m[1] * rotation[0][1] + m[2] * rotation[0][2];
		out[1] = m[0] * rotation[1][0] + m[1] * rotation[1][1] + m[2] * rotation[1][2];
		out[2] = m[0] * rotation[2][0] + m[1] * rotation[2][1] + m[2] * rotation[2][2];
		out[3] = m[3];
		return out;
	}

	template<typename T>
	Matrix<T, 4> rotate(T angle, const Vector<T, 3>& axis, const Matrix<T, 4>& m = Matrix<T, 4>(static_cast<T>(1)))
	{
		//TODO
		if constexpr (md_config::FORCE_COL_ORDERING == md_config::DISABLED)
		{
			return rotate_ROW(angle, axis, m);
		}
		else if constexpr (md_config::FORCE_COL_ORDERING == md_config::ENABLED)
		{
			return rotate_COL(angle, axis, m);
		}
		else
		{
			MD_ASSERT(false); //improper config
		}
	}

	template<typename T>
	Matrix<T, 4> translate(const Matrix<T, 4>& m, const Vector<T, 3>& v) 
	{
		Matrix<T, 4> out;
		out[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
		return out;
	}

	template<typename T>
	Matrix<T, 4> lookAt_RH_ROW(const Vector<T, 3>& eye, const Vector<T, 3>& center, const Vector<T, 3>& up)
	{
		Vector<T, 3> f(normalize(center - eye));
		Vector<T, 3> s = normalize(cross(f, up));
		Vector<T, 3> u = cross(s, f);

		Matrix<T, 4> out;
		out[0][0] = s.x();
		out[0][1] = s.y();
		out[0][2] = s.z();
		out[1][0] = u.x();
		out[1][1] = u.y();
		out[1][2] = u.z();
		out[2][0] = -f.x();
		out[2][1] = -f.y();
		out[2][2] = -f.z();
		//translation is always in this position regardless of row column ordering
		out[3][0] = -dot(s, eye);
		out[3][1] = -dot(u, eye);
		out[3][2] = dot(f, eye);
		return out;
	}

	template<typename T>
	Matrix<T, 4> lookAt_RH_COL(const Vector<T, 3>& eye, const Vector<T, 3>& center, const Vector<T, 3>& up)
	{
		Vector<T, 3> f(normalize(center - eye));
		Vector<T, 3> s = normalize(cross(f, up));
		Vector<T, 3> u = cross(s, f);

		Matrix<T, 4> out;
		out[0][0] = s.x();
		out[1][0] = s.y();
		out[2][0] = s.z();
		out[0][1] = u.x();
		out[1][1] = u.y();
		out[2][1] = u.z();
		out[0][2] = -f.x();
		out[1][2] = -f.y();
		out[2][2] = -f.z();
		//translation is always in this position regardless of row column ordering
		out[3][0] = -dot(s, eye);
		out[3][1] = -dot(u, eye);
		out[3][2] = dot(f, eye);
		return out;
	}

	template<typename T>
	Matrix<T, 4> lookAt(const Vector<T, 3>& eye, const Vector<T, 3>& center, const Vector<T, 3>& up)
	{
		if constexpr (md_config::FORCE_COL_ORDERING == md_config::ENABLED)
		{
			return lookAt_RH_COL(eye, center, up);
		}

		else if constexpr (md_config::FORCE_COL_ORDERING == md_config::DISABLED)
		{
			return lookAt_RH_ROW(eye, center, up);
		}

		else
		{
			MD_ASSERT(false); //improper config
		}
	}

	/*
	*
	*
	*
	* NON-MEMBER OPERATORS
	*
	*
	*
	*/

	template <typename T, std::size_t SIZE>
	Vector<T, SIZE> operator* (const Matrix<T, SIZE>& m0, const Vector<T, SIZE>& v0)
	{
		Vector<T, SIZE> out(v0);
		return out *= m0;
	}

	template <typename T, std::size_t SIZE>
	inline bool operator!= (const Matrix<T, SIZE>& lhs, const Matrix<T, SIZE>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T, std::size_t SIZE>
	inline bool operator== (const Matrix<T, SIZE>& lhs, const Matrix<T, SIZE>& rhs)
	{
		for (std::size_t i = 0; i < SIZE; i++)
		{
			for (std::size_t j = 0; j < SIZE; j++)
			{
				if (lhs[i][j] != rhs[i][j])
				{
					return false;
				}	
			}
		}

		return true;
	}

	/*
	*
	*
	* TYPE DEFINITIONS
	*
	*
	*
	*/
	typedef Matrix<float, 2> mat2f;
	typedef Matrix<float, 3> mat3f;
	typedef Matrix<float, 4> mat4f;
}