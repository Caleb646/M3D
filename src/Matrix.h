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
		//value_type mat[SIZE * SIZE] = { 0 };
		//value_type mat[SIZE][SIZE] = { 0 };
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
				vector_type v(f);
				operator[](i) = v;
			}
		}

		Matrix(std::vector<std::vector<T>> vec)
		{
			//expects row ordered 2d array
			for (size_type i = 0; i < SIZE; i++)
			{
				vector_type v(vec[i]);
				operator[](i) = v;
			}
		}

		Matrix(T arr[SIZE][SIZE])
		{
			//expects row ordered 2d array
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

		size_type getSize()
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

		/**
		 * @brief All of the calculations in the Matrix class are done 
		 * in a Row Major way unless the Column Major Macro is defined. The only aspect
		 * that will change is index operator will swap the row and col indices essentially
		 * transposing a Row Major matrix.
		*/
		value_type& operator() (size_type row, size_type col)
		{
			MD_ASSERT(row < SIZE && col < SIZE);
//#if MD_FORCE_COLUMN_MAJOR_ORDERING == MD_ENABLED
			return operator[](col)[row];
//#else
			return operator[](row)[col];
//#endif
		}

		const value_type& operator ()(size_type row, size_type col) const
		{
			MD_ASSERT(row < SIZE && col < SIZE);
//#if MD_FORCE_COLUMN_MAJOR_ORDERING == MD_ENABLED
			return operator[](col)[row];
//#else
			return operator[](row)[col];
//#endif
		}

		vector_type& operator[] (size_type index)
		{
			return mat[index];
		}

		const vector_type& operator[] (size_type index) const
		{
			return mat[index];
		}

		/*
		*
		* MATRIX OPERATOR OVERLOADS
		*
		*/

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
			Matrix<T, SIZE> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				out[i] = operator[](i) + m0[i];
			}
			return out;
		}

		Matrix<T, SIZE> operator- (const Matrix<T, SIZE>& m0)
		{
			Matrix<T, SIZE> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				out[i] = operator[](i) - m0[i];
			}
			return out;
		}

		Matrix<T, SIZE> operator* (const Matrix<T, SIZE>& m0)
		{
			Matrix<T, SIZE> out(0.0f);
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					for (size_type z = 0; z < SIZE; z++)
					{
						out[i][j] = out[i][j] + operator[](i)[j] * m0[j][z];
						//out(i, j) = out(i, j) + operator()(i, j) * m0(j, z);
					}
				}
			}
			return out;
		}

		Matrix<T, SIZE> operator* (float scaler)
		{
			Matrix<T, SIZE> out;

			for (size_type i = 0; i < SIZE; i++)
			{
				//for (size_type j = 0; j < SIZE; j++)
				//{
				out[i] = operator[](i) * scaler;
					//out(i, j) = operator()(i, j) * scaler;
				//}
			}
			return out;
		}

		Matrix<T, SIZE> operator/ (float scaler)
		{
			Matrix<T, SIZE> out;

			for (size_type i = 0; i < SIZE; i++)
			{
				//for (size_type j = 0; j < SIZE; j++)
				//{
				out[i] = operator[](i) / scaler;
					//out(i, j) = operator()(i, j) / scaler;
				//}
			}
			return out;
		}

		Matrix<T, SIZE> operator+= (const Matrix<T, SIZE>& m0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				operator[](i) = operator[](i) + m0[i];
				//for (size_type j = 0; j < SIZE; j++)
				//{
				//	operator()(i, j) = operator()(i, j) + m0(i, j);
				//}
			}
			return *this;
		}

		Matrix<T, SIZE> operator-= (const Matrix<T, SIZE>& m0)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				operator[](i) = operator[](i) - m0[i];
				//for (size_type j = 0; j < SIZE; j++)
				//{
				//	operator()(i, j) = operator()(i, j) - m0(i, j);
				//}
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
						//row = row + operator()(i, j) * m0(j, z);
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
				operator[](i) = operator[](i) * scaler;
				//for (size_type j = 0; j < SIZE; j++)
				//{
				//	operator()(i, j) = operator()(i, j) * scaler;
				//}
			}
			return *this;
		}

		Matrix<T, SIZE> operator/= (float scaler)
		{
			for (size_type i = 0; i < SIZE; i++)
			{
				operator[](i) = operator[](i) / scaler;
				//for (size_type j = 0; j < SIZE; j++)
				//{
				//	operator()(i, j) = operator()(i, j) / scaler;
				//}
			}
			return *this;
		}

		/*
		*
		* UNARY MATRIX OPERATOR OVERLOADS
		*
		*/

		Matrix<T, SIZE> operator-()
		{
			Matrix<T, SIZE> out;
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

		/*
		*
		* MATRIX TYPES
		*
		*/

		static Matrix<T, SIZE> transpose(const Matrix<T, SIZE>& m0)
		{
			Matrix<T, SIZE> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				for (size_type j = 0; j < SIZE; j++)
				{
					out(i, j) = m0(j, i);
				}
			}
			return out;
		}

		Matrix<T, SIZE>& getTranslated(const Vector<T, SIZE>& v0)
		{
			for (size_type i = 0; i < SIZE - 1; i++)
			{
				operator[](SIZE - 1) += operator[](i) * v0[i];
			}
			return *this;
		}

		Matrix<T, 4>& getTranslated(const Vector<T, 3>& v0)
		{
			for (size_type i = 0; i < SIZE - 1; i++)
			{
				operator[](SIZE - 1) += operator[](i) * v0[i];
			}
			return *this;
		}

		Matrix<T, SIZE>& getRotatedX(float radians)
		{
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };

			operator()(1, 1) = c;
			operator()(1, 2) = s;
			operator()(2, 1) = -s;
			operator()(2, 2) = c;

			return *this;
		}
		Matrix<T, SIZE>& getRotatedY(float radians)
		{
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };
			operator()(0, 0) = c;
			operator()(0, 2) = s;
			operator()(2, 0) = -s;
			operator()(2, 2) = c;
			return *this;
		}
		void getRotatedZ(float radians)
		{
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };
			operator()(0, 0) = c;
			operator()(0, 1) = s;
			operator()(1, 0) = -s;
			operator()(1, 1) = c;
		}

		void getPointedAt(const Vector<T, SIZE>& cameraPos, const Vector<T, SIZE>& targetV, const Vector<T, SIZE>& upVec)
		{


			Vector<value_type, SIZE> newForward{ (targetV - cameraPos).normalize() };
			float projection{ Vector<value_type, SIZE>::dot(upVec, newForward) };
			Vector<value_type, SIZE> a{ newForward * projection };
			Vector<value_type, SIZE> newUp{ (upVec - a).normalize() };
			Vector<value_type, SIZE> newRight{ Vector<value_type, SIZE>::cross(upVec, newForward) };

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
			Matrix<T, SIZE> m(*this);

			operator()(0, 0) = m(0, 0);
			operator()(0, 1) = m(1, 0);
			operator()(0, 2) = m(2, 0);
			operator()(0, 3) = static_cast<value_type>(0);
			operator()(1, 0) = m(0, 1);
			operator()(1, 1) = m(1, 1);
			operator()(1, 2) = m(2, 1);
			operator()(1, 3) = static_cast<value_type>(0);
			operator()(2, 0) = m(0, 2);
			operator()(2, 1) = m(1, 2);
			operator()(2, 2) = m(2, 2);
			operator()(2, 3) = static_cast<value_type>(0);
			operator()(3, 0) = -(m(3, 0) * operator()(0, 0) + m(3, 1) * operator()(1, 0) + m(3, 2) * operator()(2, 0));
			operator()(3, 1) = -(m(3, 0) * operator()(0, 1) + m(3, 1) * operator()(1, 1) + m(3, 2) * operator()(2, 1));
			operator()(3, 2) = -(m(3, 0) * operator()(0, 2) + m(3, 1) * operator()(1, 2) + m(3, 2) * operator()(2, 2));
			operator()(3, 3) = static_cast<value_type>(1);
		}

		/*
		*
		* MATRIX STATIC METHODS
		*
		*/


		friend Matrix<T, 4> translate(Matrix<T, 4> m, Vector<T, 3> v)
		{
			Matrix<T, SIZE> out;
			out[SIZE - 1] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
			return out;
		}
	
		friend Matrix<T, 4> lookAt(Vector<T, 3> eye, Vector<T, 3> center, Vector<T, 3> up)
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

		friend Matrix<T, 4> lookAt_RH_ROW(Vector<T, 3> eye, Vector<T, 3> center, Vector<T, 3> up)
		{
			Vector<T, 3> f(center - eye);
			f.normalized();
			Vector<T, 3> s;
			s = Vector<T, 3>::cross(f, up);
			s.normalized();
			Vector<T, 3> u;
			u = Vector<T, 3>::cross(s, f);

			Matrix<T, SIZE> out;

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

		friend Matrix<T, 4> lookAt_RH_COL(Vector<T, 3> eye, Vector<T, 3> center, Vector<T, 3> up)
		{
			Vector<T, 3> f(center - eye);
			f.normalized();
			Vector<T, 3> s;
			s = Vector<T, 3>::cross(f, up);
			s.normalized();
			Vector<T, 3> u;
			u = Vector<T, 3>::cross(s, f);

			Matrix<T, SIZE> out;

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


		static Vector<T, SIZE> multVector(Matrix<T, SIZE> m0, Vector<T, SIZE> v0)
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

		static Matrix<T, SIZE> getTranslation(const mat_t& m0, const Vector<T, SIZE>& v0)
		{
			Matrix<T, SIZE> out;
			for (size_type i = 0; i < SIZE; i++)
			{
				out[SIZE - 1] += m0[i] * v0[i];
			}
			return out;
		}

		/*
		* The translation components occupy the 13th, 14th, and 15th elements of the 16-element
		* matrix, where indices are numbered from 1 to 16.
		*/
		static Matrix<T, 4> getTranslation(const Matrix<T, 4>& m0, const Vector<T, 3>& v0)
		{

			//mat<4, 4, T, Q> Result(m);
			//Result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
			//return Result;

			Matrix<T, SIZE> out;
			out[SIZE - 1] = m0[0] * v0[0] + m0[1] * v0[1] + m0[2] * v0[2] + m0[3];
			return out;
		}

		static Matrix<T, SIZE> getPerspective(float fovRads, float aspect, float zNear, float zFar)
		{
			Matrix<T, SIZE> out;
			float half{ std::tanf(fovRads / static_cast<T>(2)) };

//#if MD_FORCE_DEPTH_ZERO_TO_ONE == MD_ENABLED
			out(0, 0) = static_cast<T>(1) / (aspect * half);
			out(1, 1) = static_cast<T>(1) / (half);
			out(2, 2) = zFar / (zNear - zFar);
			out(3, 2) = -static_cast<T>(1);
			out(2, 3) = -(zFar * zNear) / (zFar - zNear);
			out(3, 3) = static_cast<T>(0);
//#else
			out(0, 0) = static_cast<T>(1) / (aspect * half);
			out(1, 1) = static_cast<T>(1) / half;
			out(2, 2) = zFar / (zNear - zFar);
			out(3, 2) = -(static_cast<T>(1)); //3, 2
			out(2, 3) = -((static_cast<T>(2) * zFar * zNear) / (zFar - zNear)); // 2, 3
			out(3, 3) = static_cast<T>(0);
//#endif
			return out;
		}

		static Matrix<T, SIZE> getRotateX(float radians)
		{
			Matrix<T, SIZE> out;
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };
			out(1, 1) = c;
			out(1, 2) = s;
			out(2, 1) = -s;
			out(2, 2) = c;
			return out;
		}
		static Matrix<T, SIZE> getRotateY(float radians)
		{
			Matrix<T, SIZE> out;
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };
			out(0, 0) = c;
			out(0, 2) = s;
			out(2, 0) = -s;
			out(2, 2) = c;
			return out;
		}
		static Matrix<T, SIZE> getRotateZ(float radians)
		{
			Matrix<T, SIZE> out;
			float c{ std::cosf(radians) };
			float s{ std::sinf(radians) };
			out(0, 0) = c;
			out(0, 1) = s;
			out(1, 0) = -s;
			out(1, 1) = c;
			return out;
		}

		static Matrix<T, SIZE> getPointAt(const Vector<T, SIZE>& cameraPos, const Vector<T, SIZE>& targetV, const  Vector<T, SIZE>& upVec)
		{
			Vector<T, SIZE> newForward{ (targetV - cameraPos).normalize() };
			float projection{ Vector<T, SIZE>::dot(upVec, newForward) };
			Vector<T, SIZE> a{ newForward * projection };
			Vector<T, SIZE> newUp{ (upVec - a).normalize() };
			Vector<T, SIZE> newRight{ Vector<T, SIZE>::cross(upVec, newForward) };
			Matrix<T, SIZE> out;

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
		static Matrix<T, 4> getInverse(const Matrix<T, 4>& m)
		{
			Matrix<T, SIZE> out(m);
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
		static Matrix<T, 4> getLookAt(const Vector<T, 3>& eye, const Vector<T, 3>& center, const  Vector<T, 3>& up)
		{
			Vector<T, 3> f(center - eye);
			f.normalized();
			Vector<T, 3> s;
			s = Vector<T, 3>::cross(f, up);
			s.normalized();
			Vector<T, 3> u;
			u = Vector<T, 3>::cross(s, f);

			Matrix<T, SIZE> out;



			//vec<3, T, Q> const f(normalize(center - eye));
			//vec<3, T, Q> const s(normalize(cross(f, up)));
			//vec<3, T, Q> const u(cross(s, f));

			//mat<4, 4, T, Q> Result(1);
			//Result[0][0] = s.x;
			//Result[1][0] = s.y;
			//Result[2][0] = s.z;
			//Result[0][1] = u.x;
			//Result[1][1] = u.y;
			//Result[2][1] = u.z;
			//Result[0][2] = -f.x;
			//Result[1][2] = -f.y;
			//Result[2][2] = -f.z;
			//Result[3][0] = -dot(s, eye);
			//Result[3][1] = -dot(u, eye);
			//Result[3][2] = dot(f, eye);
			//return Result;

			out(0, 0) = s.x();
			out(0, 1) = s.y();
			out(0, 2) = s.z();
			out(1, 0) = u.x();
			out(1, 1) = u.y();
			out(1, 2) = u.z();
			out(2, 0) = -f.x();
			out(2, 1) = -f.y();
			out(2, 2) = -f.z();

			out[3][0] = -Vector<T, 3>::dot(s, eye);
			out[3][1] = -Vector<T, 3>::dot(u, eye);
			out[3][2] = Vector<T, 3>::dot(f, eye);

			return out;

			//How a column major look at matrix is laid out
			//out[0][0] = s.x();
			//out[1][0] = s.y();
			//out[2][0] = s.z();

			//out[0][1] = u.x();
			//out[1][1] = u.y();
			//out[2][1] = u.z();

			//out[0][2] = -f.x();
			//out[1][2] = -f.y();
			//out[2][2] = -f.z();

			//out[3][0] = -Vector<T, 3>::dot(s, eye);
			//out[3][1] = -Vector<T, 3>::dot(u, eye);
			//out[3][2] = Vector<T, 3>::dot(f, eye);
		}

		private:
	};



	/*
	* 
	* 
	* FRIEND FUNCTIONS
	* 
	* 
	*/
	template<typename T>
	Matrix<T, 4> translate(Matrix<T, 4> m, Vector<T, 3> v)
	{
		Matrix<T, SIZE> out;
		out[SIZE - 1] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
		return out;
	}

	template<typename T>
	Matrix<T, 4> lookAt(Vector<T, 3> eye, Vector<T, 3> center, Vector<T, 3> up)
	{
		if constexpr (md_config::FORCE_COL_ORDERING == md_config::ENABLED)
		{
			return lookAt_RH_COL(eye, center, up);
		}

		else if constexpr (md_config::FORCE_COL_ORDERING == md_config::DISABLED)
		{
			return lookAt_RH_ROW(eye, center, up);
		}

		else constexpr
		{
			MD_ASSERT(false); //improper config
		}
	}

	template<typename T>
	Matrix<T, 4> lookAt_RH_ROW(Vector<T, 3> eye, Vector<T, 3> center, Vector<T, 3> up)
	{
		Vector<T, 3> f(center - eye);
		f.normalized();
		Vector<T, 3> s;
		s = Vector<T, 3>::cross(f, up);
		s.normalized();
		Vector<T, 3> u;
		u = Vector<T, 3>::cross(s, f);

		Matrix<T, SIZE> out;

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
		out[3] = Vector<T, 3>(-dot(s, eye), -dot(u, eye), dot(f, eye));

		return out;
	}

	template<typename T>
	Matrix<T, 4> lookAt_RH_COL(Vector<T, 3> eye, Vector<T, 3> center, Vector<T, 3> up)
	{
		Vector<T, 3> f(center - eye);
		f.normalized();
		Vector<T, 3> s;
		s = Vector<T, 3>::cross(f, up);
		s.normalized();
		Vector<T, 3> u;
		u = Vector<T, 3>::cross(s, f);

		Matrix<T, SIZE> out;

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
		out[3] = Vector<T, 3>(-dot(s, eye), -dot(u, eye), dot(f, eye));

		return out;
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
	template <class T, int SIZE>
	Vector<T, SIZE> operator* (const Matrix<T, SIZE>& m0, const Vector<T, SIZE>& v0)
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

	template <class T, int SIZE>
	Vector<T, SIZE>  operator*= (const Matrix<T, SIZE>& m0, const Vector<T, SIZE>& v0)
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

	template <class T, int SIZE>
	inline bool operator== (const Matrix<T, SIZE>& lhs, const Matrix<T, SIZE>& rhs)
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

	template <class T, int SIZE>
	inline bool operator!= (const Matrix<T, SIZE>& lhs, const Matrix<T, SIZE>& rhs)
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
	typedef Matrix<float, 2> mat2f;
	typedef Matrix<float, 3> mat3f;
	typedef Matrix<float, 4> mat4f;

	typedef Matrix<float, 4> TestMat4Row;
	typedef Matrix<float, 4> TestMat4Col;

}