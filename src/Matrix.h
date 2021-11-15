#pragma once
#include "Vector.h"

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

	template <typename T, std::size_t SIZE, bool COLORDERING>
	class Matrix
	{
	public:
		using size_type = std::size_t;
		using value_type = T;
		value_type mat[SIZE * SIZE] = { 0 };

	public:
		Matrix()
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					if (i == j)
					{
						operator()(i, j) = static_cast<T>(1);
					}
				
					else
					{
						operator()(i, j) = static_cast<T>(0);
					}	
				}
			}
		}


		Matrix(T f)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					operator()(i, j) = static_cast<T>(f);
				}
			}
		}

		Matrix(T arr[SIZE][SIZE])
		{
			//expects row ordered 2d array
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					operator()(i, j) = arr[i][j];
				}
			}
		}

		Matrix(const Matrix<T, SIZE, COLORDERING>& m)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					operator()(i, j) = m(i, j);
				}
			}
		}

		~Matrix() {}

		size_type getSize()
		{
			return SIZE;
		}

		void print()
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					std::cout << " || " << operator()(i, j) << " || " << " || "; //<< &this->operator()(i, j) << " || ";
					//std::cout << " || " << mat[(i * SIZE) + j] << " || " << " || " << &mat[(i * SIZE) + j] << " || ";
					//std::cout << " || " << mat[(i * SIZE) + j] << " || ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

		std::string toString()
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

		T& operator ()(size_type row, size_type col)
		{
			ASSERT_FATAL(DEFAULT_LOGGABLE, row < SIZE&& col < SIZE, "row or col is out of bounds.");
			size_type index{ (row * SIZE) + col };

			if (COLORDERING)
				index = (col * SIZE) + row;

			return mat[index];
		}

		const T& operator ()(size_type row, size_type col) const
		{
			ASSERT_FATAL(DEFAULT_LOGGABLE, row < SIZE&& col < SIZE, "row or col is out of bounds.");
			size_type index{ (row * SIZE) + col };

			if (COLORDERING)
				index = (col * SIZE) + row;

			return mat[index];
		}

		/*
		*
		* MATRIX OPERATOR OVERLOADS
		*
		*/

		void operator= (const Matrix<T, SIZE, COLORDERING>& m0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					operator()(i, j) = m0(i, j);
				}
			}
		}

		Matrix<T, SIZE, COLORDERING> operator+ (const Matrix<T, SIZE, COLORDERING>& m0)
		{
			Matrix<T, SIZE, COLORDERING> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					out(i, j) = operator()(i, j) + m0(i, j);
				}
			}
			return out;
		}

		Matrix<T, SIZE, COLORDERING> operator- (const Matrix<T, SIZE, COLORDERING>& m0)
		{
			Matrix<T, SIZE, COLORDERING> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					out(i, j) = operator()(i, j) - m0(i, j);
				}
			}
			return out;
		}

		Matrix<T, SIZE, COLORDERING> operator* (const Matrix<T, SIZE, COLORDERING>& m0)
		{
			Matrix<T, SIZE, COLORDERING> out(0.0f);
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					for (size_type z = 0; z < SIZE; z++)
					{
						out(i, j) = out(i, j) + operator()(i, j) * m0(j, z);
					}
				}
			}
			return out;
		}

		Matrix<T, SIZE, COLORDERING> operator* (float scaler)
		{
			Matrix<T, SIZE, COLORDERING> out;

			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					out(i, j) = operator()(i, j) * scaler;
				}
			}
			return out;
		}

		Matrix<T, SIZE, COLORDERING> operator/ (float scaler)
		{
			Matrix<T, SIZE, COLORDERING> out;

			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					out(i, j) = operator()(i, j) / scaler;
				}
			}
			return out;
		}

		Matrix<T, SIZE, COLORDERING> operator+= (const Matrix<T, SIZE, COLORDERING>& m0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					operator()(i, j) = operator()(i, j) + m0(i, j);
				}
			}
			return *this;
		}

		Matrix<T, SIZE, COLORDERING> operator-= (const Matrix<T, SIZE, COLORDERING>& m0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					operator()(i, j) = operator()(i, j) - m0(i, j);
				}
			}
			return *this;
		}

		Matrix<T, SIZE, COLORDERING> operator*= (const Matrix<T, SIZE, COLORDERING>& m0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					T row{ static_cast<T>(0) };
					for (size_type z = 0; z < SIZE; z++)
					{
						row = row + operator()(i, j) * m0(j, z);
					}
					operator()(i, j) = row;
				}
			}
			return *this;
		}

		Matrix<T, SIZE, COLORDERING> operator*= (float scaler)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					operator()(i, j) = operator()(i, j) * scaler;
				}
			}
			return *this;
		}

		Matrix<T, SIZE, COLORDERING> operator/= (float scaler)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					operator()(i, j) = operator()(i, j) / scaler;
				}
			}
			return *this;
		}

		/*
		*
		* UNARY MATRIX OPERATOR OVERLOADS
		*
		*/

		Matrix<T, SIZE, COLORDERING> operator-()
		{
			Matrix<T, SIZE, COLORDERING> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; i++)
				{
					out(i, j) = -operator()(i, j);
				}

			}

		}

		//when converting to float* return the mat array
		//example: float *ptr; Mat4f mat; ptr = (float*) mat; would
		//call one of these functions.
		operator const T* () const
		{
			return mat;
		}
		operator T* ()
		{
			return mat;
		}

		/*
		*
		* MATRIX TYPES
		*
		*/

		static Matrix<T, SIZE, !COLORDERING> transpose(const Matrix<T, SIZE, COLORDERING>& m0)
		{
			Matrix<T, SIZE, !COLORDERING> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					out(i, j) = m0(j, i);
				}
			}
			return out;
		}


		void getTranslated(std::initializer_list<T> init_list)
		{
			size_type c{ 0 };
			for (auto i : init_list)
			{
				operator()(c++, SIZE - 1) = static_cast<T>(i);
			}
		}

		void getTranslated(const Vector<T, SIZE>& v0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				operator()(i, SIZE - 1) = v0[i];
			}
		}

		void getPerspectived(float fovRads, float aspect_ratio, float near_dist, float far_dist)
		{
			float half{ std::tanf(fovRads / static_cast<T>(2)) };

			operator()(0, 0) = static_cast<T>(1) / (aspect_ratio * half);
			operator()(1, 1) = static_cast<T>(1) / half;
			operator()(2, 2) = far_dist / (near_dist - far_dist);
			operator()(3, 2) = -static_cast<T>(1);
			operator()(2, 3) = -((static_cast<T>(2) * far_dist * near_dist) / (far_dist - near_dist));
			operator()(3, 3) = static_cast<T>(0);
		}

		void getRotatedX(float radians)
		{
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };

			operator()(1, 1) = c;
			operator()(1, 2) = s;
			operator()(2, 1) = -s;
			operator()(2, 2) = c;
		}
		void getRotatedY(float radians)
		{
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };
			operator()(0, 0) = c;
			operator()(0, 2) = s;
			operator()(2, 0) = -s;
			operator()(2, 2) = c;
		}
		void getRotatedZ(float radians)
		{
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };
			this->operator()(0, 0) = c;
			this->operator()(0, 1) = s;
			this->operator()(1, 0) = -s;
			this->operator()(1, 1) = c;
		}

		void getPointedAt(const Vector<T, SIZE>& cameraPos, const Vector<T, SIZE>& targetV, const Vector<T, SIZE>& upVec)
		{


			Vector<T, SIZE> newForward{ (targetV - cameraPos).normalize() };
			float projection{ Vector<T, SIZE>::dot(upVec, newForward) };
			Vector<T, SIZE> a{ newForward * projection };
			Vector<T, SIZE> newUp{ (upVec - a).normalize() };
			Vector<T, SIZE> newRight{ Vector<T, SIZE>::cross(upVec, newForward) };

			operator()(0, 0) = newRight.x();
			operator()(0, 1) = newRight.y();
			operator()(0, 2) = newRight.z();
			operator()(0, 3) = 0.0f;
			operator()(1, 0) = newUp.x();
			operator()(1, 1) = newUp.y();
			operator()(1, 2) = newUp.z();
			operator()(1, 3) = 0.0f;
			operator()(2, 0) = newForward.x();
			operator()(2, 1) = newForward.y();
			operator()(2, 2) = newForward.z();
			operator()(2, 3) = 0.0f;
			operator()(3, 0) = cameraPos.x();
			operator()(3, 1) = cameraPos.y();
			operator()(3, 2) = cameraPos.z();
			operator()(3, 3) = 1.0f;

		}

		void getInversed()
		{
			Matrix<T, SIZE, COLORDERING> m(*this);

			operator()(0, 0) = m(0, 0);
			operator()(0, 1) = m(1, 0);
			operator()(0, 2) = m(2, 0);
			operator()(0, 3) = static_cast<T>(0);
			operator()(1, 0) = m(0, 1);
			operator()(1, 1) = m(1, 1);
			operator()(1, 2) = m(2, 1);
			operator()(1, 3) = static_cast<T>(0);
			operator()(2, 0) = m(0, 2);
			operator()(2, 1) = m(1, 2);
			operator()(2, 2) = m(2, 2);
			operator()(2, 3) = static_cast<T>(0);
			operator()(3, 0) = -(m(3, 0) * operator()(0, 0) + m(3, 1) * operator()(1, 0) + m(3, 2) * operator()(2, 0));
			operator()(3, 1) = -(m(3, 0) * operator()(0, 1) + m(3, 1) * operator()(1, 1) + m(3, 2) * operator()(2, 1));
			operator()(3, 2) = -(m(3, 0) * operator()(0, 2) + m(3, 1) * operator()(1, 2) + m(3, 2) * operator()(2, 2));
			operator()(3, 3) = static_cast<T>(1);
		}

		/*
		*
		* MATRIX STATIC METHODS
		*
		*/

		static Vector<T, SIZE> multVector(Matrix<T, SIZE, COLORDERING> m0, Vector<T, SIZE> v0)
		{
			Vector<T, SIZE> out;
			for (std::size_t i = 0; i < SIZE; i++)
			{
				for (std::size_t j = 0; j < SIZE; j++)
				{
					out[i] = out[i] + (v0[i] * m0(j, i));
				}
			}
			return out;
		}

		static Matrix<T, SIZE, COLORDERING> getTranslation(std::initializer_list<T> init_list)
		{
			Matrix<T, SIZE, COLORDERING> out;
			std::size_t c{ 0 };

			for (auto i : init_list)
			{
				out(c++, SIZE - 1) = static_cast<T>(i);
			}
			return out;
		}

		/*
		* The translation components occupy the 13th, 14th, and 15th elements of the 16-element
		* matrix, where indices are numbered from 1 to 16.
		*/
		static Matrix<T, SIZE, COLORDERING> getTranslation(const Vector<T, SIZE>& v0)
		{
			Matrix<T, SIZE, COLORDERING> out;
			for (std::size_t i = 0; i < SIZE; i++)
			{
				out(i, SIZE - 1) = v0[i];
			}
			return out;
		}

		static Matrix<T, SIZE, COLORDERING> getPerspective(float fovRads, float aspect_ratio, float near_dist, float far_dist)
		{
			Matrix<T, SIZE, COLORDERING> out;
			float half{ std::tanf(fovRads / static_cast<T>(2)) };
			out(0, 0) = static_cast<T>(1) / (aspect_ratio * half);
			out(1, 1) = static_cast<T>(1) / half;
			out(2, 2) = far_dist / (near_dist - far_dist);
			out(3, 2) = -(static_cast<T>(1)); //3, 2
			out(2, 3) = -((static_cast<T>(2) * far_dist * near_dist) / (far_dist - near_dist)); // 2, 3
			out(3, 3) = static_cast<T>(0);
			return out;
		}

		static Matrix<T, SIZE, COLORDERING> getRotateX(float radians)
		{
			Matrix<T, SIZE, COLORDERING> out;
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };
			out(1, 1) = c;
			out(1, 2) = s;
			out(2, 1) = -s;
			out(2, 2) = c;
			return out;
		}
		static Matrix<T, SIZE, COLORDERING> getRotateY(float radians)
		{
			Matrix<T, SIZE, COLORDERING> out;
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };
			out(0, 0) = c;
			out(0, 2) = s;
			out(2, 0) = -s;
			out(2, 2) = c;
			return out;
		}
		static Matrix<T, SIZE, COLORDERING> getRotateZ(float radians)
		{
			Matrix<T, SIZE, COLORDERING> out;
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };
			out(0, 0) = c;
			out(0, 1) = s;
			out(1, 0) = -s;
			out(1, 1) = c;
			return out;
		}

		static Matrix<T, SIZE, COLORDERING> getPointAt(const Vector<T, SIZE>& cameraPos, const Vector<T, SIZE>& targetV, const  Vector<T, SIZE>& upVec)
		{
			Vector<T, SIZE> newForward{ (targetV - cameraPos).normalize() };
			float projection{ Vector<T, SIZE>::dot(upVec, newForward) };
			Vector<T, SIZE> a{ newForward * projection };
			Vector<T, SIZE> newUp{ (upVec - a).normalize() };
			Vector<T, SIZE> newRight{ Vector<T, SIZE>::cross(upVec, newForward) };
			Matrix<T, SIZE, COLORDERING> out;

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
			return out;
		}
		static Matrix<T, SIZE, COLORDERING> getInverse(const Matrix<T, SIZE, COLORDERING>& m)
		{
			Matrix<T, SIZE, COLORDERING> out(m);
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
			return out;
		}
		static Matrix<T, SIZE, COLORDERING> getLookAt(const Vector<T, 3>& eye, const Vector<T, 3>& center, const  Vector<T, 3>& up)
		{

			Vector<T, 3> f(center - eye);
			f.normalized();
			Vector<T, 3> s;
			s = Vector<T, 3>::cross(f, up);
			s.normalized();
			Vector<T, 3> u;
			u = Vector<T, 3>::cross(s, f);

			Matrix<T, SIZE, COLORDERING> out;
			out(0, 0) = s.x();
			out(0, 1) = s.y();
			out(0, 2) = s.z();
			out(1, 0) = u.x();
			out(1, 1) = u.y();
			out(1, 2) = u.z();
			out(2, 0) = -f.x();
			out(2, 1) = -f.y();
			out(2, 2) = -f.z();

			out(0, 3) = -Vector<T, 3>::dot(s, eye);
			out(1, 3) = -Vector<T, 3>::dot(u, eye);
			out(2, 3) = Vector<T, 3>::dot(f, eye);

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
	template <class T, int SIZE, bool COLORDERING>
	Vector<T, SIZE> operator* (const Matrix<T, SIZE, COLORDERING>& m0, const Vector<T, SIZE>& v0)
	{
		Vector<T, SIZE> out(0.0f);
		for (std::size_t i = 0; i < SIZE; i++)
		{
			for (std::size_t j = 0; j < SIZE; j++)
			{
				out[i] = out[i] + m0(i, j) * v0[j];
			}
		}
		return out;
	}

	template <class T, int SIZE, bool COLORDERING>
	Vector<T, SIZE>  operator*= (const Matrix<T, SIZE, COLORDERING>& m0, const Vector<T, SIZE>& v0)
	{
		Vector<T, SIZE> out(0.0f);
		for (std::size_t i = 0; i < SIZE; i++)
		{
			for (std::size_t j = 0; j < SIZE; j++)
			{
				out[i] = out[i] + m0(i, j) * v0[j];
			}
		}
		return out;
	}

	template <class T, int SIZE, bool COLORDERING>
	inline bool operator== (const Matrix<T, SIZE, COLORDERING>& lhs, const Matrix<T, SIZE, COLORDERING>& rhs)
	{
		for (std::size_t i = 0; i < SIZE; i++)
		{
			for (std::size_t j = 0; j < SIZE; j++)
			{
				if (lhs(i, j) != rhs(i, j))
					return false;
			}
		}

		return true;
	}

	template <class T, int SIZE, bool COLORDERING>
	inline bool operator!= (const Matrix<T, SIZE, COLORDERING>& lhs, const Matrix<T, SIZE, COLORDERING>& rhs)
	{
		return !(lhs == rhs);
	}

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

}