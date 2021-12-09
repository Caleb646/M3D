#include <gtest/gtest.h>

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#define M3D_UNIT_TESTING
#include "../M3D.h"

namespace MatrixTesting
{
	using namespace m3d;

	bool Mat4f_GlmMat_Equality(mat4f& mm, glm::mat4& gm)
	{
		for (std::size_t i = 0; i < 4; i++)
		{
			for (std::size_t j = 0; j < 4; j++)
			{
				float colv = mm[i][j];
				float glmv = gm[i][j];
				if (colv != glmv)
				{
					return false;
				}
				float value = gm[i][j];
				bool f = false;
			}
		}
		return true;
	}

	std::string glmToString(glm::mat4& m)
	{
		std::stringstream stream;
		for (int i = 0; i < 4; i++)
		{
			stream << "|| ";
			for (std::size_t j = 0; j < 4; j++)
			{
				
				stream << m[i][j];	
				stream << " ";
			}
			stream << " ||";
			stream << "\n";
		}
		return stream.str();
	}

	bool almostEqual(mat4f m, mat4f m2, float tolerance = 0.001f)
	{
		for (std::size_t i = 0; i < 4; i++)
		{
			for (std::size_t j = 0; j < 4; j++)
			{
				if (std::abs(m[i][j] - m2[i][j]) > tolerance)
				{
					return false;
				}
			}
		}
		return true;
	}
	TEST(MatrixTest, Equality)
	{
		mat4f A(5.0f);
		mat4f B(5.0f);
		ASSERT_EQ(true, A == B);
		ASSERT_EQ(false, A != B);
	}

	TEST(MatrixTest, Constructors)
	{
		float twoDArray[4][4] = {
		{15.0f, 0.0f, 0.0f, 0.0f},
		{0.0f, 15.0f, 0.0f, 0.0f},
		{0.0f, 0.0f, 15.0f, 0.0f},
		{0.0f, 0.0f, 0.0f, 15.0f},
	};
		mat4f A(twoDArray);
		mat4f B(15.0f);
		mat4f C(A);
		ASSERT_EQ(true, A == B);
		ASSERT_EQ(false, A != B);
		ASSERT_EQ(true, A == C);
		ASSERT_EQ(false, A != C);
	}

	TEST(MatrixTest, Indexing)
	{
		mat4f I(1.0f);
		mat4f A = translate(I, vec3f(12.0f, 15.0f, 17.0f));
		mat4f B = translate(I, vec4f(12.0f, 15.0f, 17.0f, 1.0f));
		ASSERT_EQ(12.0f, A[3][0]);
		ASSERT_EQ(15.0f, A[3][1]);
		ASSERT_EQ(17.0f, A[3][2]);
		ASSERT_EQ(1.0f , A[3][3]);

		ASSERT_EQ(12.0f, B[3][0]);
		ASSERT_EQ(15.0f, B[3][1]);
		ASSERT_EQ(17.0f, B[3][2]);
		ASSERT_EQ(2.0f , B[3][3]);
	}

	TEST(MatrixTest, Addition)
	{
		float twoDArray[4][4] = { 
			{10.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 10.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 10.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 10.0f}
		};
		float answerArray[4][4] = {
			{12.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 12.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 12.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 12.0f}
		};
		mat4f A(twoDArray);
		mat4f B(2.0f);
		mat4f C;
		mat4f D(answerArray);
		C = A + B;
		A += B;
		ASSERT_EQ(true, D == C);
		ASSERT_EQ(true, D == A);
	}

	TEST(MatrixTest, Subtraction)
	{
		float twoDArray[4][4] = {
			{10.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 10.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 10.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 10.0f}
		};
		float answerArray[4][4] = {
			{8.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 8.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 8.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 8.0f}
		};

		mat4f A(twoDArray);
		mat4f B(2.0f);
		mat4f C;
		mat4f D(answerArray);
		C = A - B;
		A -= B;
		ASSERT_EQ(true, D == C) << C.toString();
		ASSERT_EQ(true, D == A) << A.toString();
	}

	TEST(MatrixTest, Multiplication)
	{
		{
			float twoDArray[4][4] = {
				{10.0f, 5.0f, 10.0f, 5.0f},
				{10.0f, 5.0f, 10.0f, 5.0f},
				{10.0f, 5.0f, 10.0f, 5.0f},
				{10.0f, 5.0f, 10.0f, 5.0f}
			};
			float answerArray[4][4] = {
				{300.0f, 150.0f, 300.0f, 150.0f},
				{300.0f, 150.0f, 300.0f, 150.0f},
				{300.0f, 150.0f, 300.0f, 150.0f},
				{300.0f, 150.0f, 300.0f, 150.0f}
			};

			mat4f A(twoDArray);
			mat4f B(twoDArray);
			mat4f C;
			mat4f D(answerArray);
			C = A * B;
			A *= B;
			ASSERT_EQ(true, D == C) << D.toString() << "\n" << C.toString();
			ASSERT_EQ(true, D == A) << D.toString() << "\n" << A.toString();
		}

		//vector matrix multiplication
		{
			float answerVecArray[4][4] = {
			{10.0f, 5.0f, 10.0f, 5.0f},
			{10.0f, 5.0f, 10.0f, 5.0f},
			{10.0f, 5.0f, 10.0f, 5.0f},
			{10.0f, 5.0f, 10.0f, 5.0f}
			};

			vec4f A(10.0f, 10.0f, 10.0f, 10.0f);
			vec4f C{};
			vec4f aA(300.0f, 300.0f, 300.0f, 300.0f);
			mat4f mA(answerVecArray);

			C = mA * A;
			A *= mA;
			ASSERT_EQ(true, aA == C) << aA.toString() << "\n" << C.toString();
			ASSERT_EQ(true, aA == A) << aA.toString() << "\n" << A.toString();
		}

		//matrix scaler multiplication
		{
			float scaler = 10.0f;
			float answerScalerArray[4][4] = {
				{20.0f, 0.0f, 0.0f, 0.0f},
				{0.0f, 20.0f, 0.0f, 0.0f},
				{0.0f, 0.0f, 20.0f, 0.0f},
				{0.0f, 0.0f, 0.0f, 20.0f}
			};
			mat4f AA(answerScalerArray);
			mat4f A;
			mat4f B(2.0f);
			A = B * scaler;
			B *= scaler;
			ASSERT_EQ(true, AA == A) << AA.toString() << "\n" << A.toString();
			ASSERT_EQ(true, AA == B) << AA.toString() << "\n" << B.toString();
		}

	}

	TEST(MatrixTest, Division)
	{
		float scaler = 10.0f;
		float answerScalerArray[4][4] = {
			{2.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 2.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 2.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 2.0f}
		};
		mat4f A(20.0f);
		mat4f AA(answerScalerArray);
		mat4f B;
		B = A / scaler;
		A /= scaler;
		ASSERT_EQ(true, AA == B) << AA.toString() << "\n" << B.toString();
		ASSERT_EQ(true, AA == A) << AA.toString() << "\n" << A.toString();
	}

	TEST(MatrixTest, Translation)
	{
		float answerArray[4][4] = {
			{1.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f, 0.0f},
			{1.0f, -1.0f, 1.0f, 1.0f}
		};
		mat4f A = translate(mat4f(1.0f), vec3f(1.0f, -1.0f, 1.0f));
		mat4f B = translate(mat4f(1.0f), vec4f(1.0f, -1.0f, 1.0f, 0.0f));
		mat4f AA(answerArray);
		ASSERT_EQ(true, AA == A) << AA.toString() << "\n" << A.toString();
		ASSERT_EQ(true, AA == B) << AA.toString() << "\n" << B.toString();
	}

	TEST(MatrixTest, Rotate)
	{
		float const angle = 45.0f;
		{
			float XYZ[4][4] = //angle 45 degrees
			{
				{0.683548f,	-0.333043f, 0.649495f, 0.f},
				{0.649495f,	0.683548f, -0.333043f, 0.f},
				{-0.333043f, 0.649495f, 0.683548f, 0.f},
				{0.f, 0.f, 0.f, 1.f}
			};

			float YZ[4][4] = //angle 45 degrees
			{
				{0.525322,	-0.60168, 0.60168, 0.f},
				{0.60168,	0.762661, 0.237339, 0.f},
				{-0.60168, 0.237339, 0.762661, 0.f},
				{0.f, 0.f, 0.f, 1.f}
			};

			float XZ[4][4] = //angle 45 degrees
			{
				{0.762661, - 0.60168, 0.237339, 0.f},
				{0.60168, 0.525322, - 0.60168, 0.f},
				{0.237339, 0.60168, 0.762661, 0.f},
				{0.f, 0.f, 0.f, 1.f}
			};

			mat4f A = rotate_ROW(angle, vec3f(1.f, 1.f, 1.f));
			mat4f B = rotate_ROW(angle, vec3f(0.f, 1.f, 1.f));
			mat4f C = rotate_ROW(angle, vec3f(1.f, 0.f, 1.f));

			mat4f AA(XYZ);
			mat4f BB(YZ);
			mat4f CC(XZ);
			ASSERT_EQ(true, almostEqual(AA, A)) << AA.toString() << "\n" << A.toString();
			ASSERT_EQ(true, almostEqual(BB, B)) << BB.toString() << "\n" << B.toString();
			ASSERT_EQ(true, almostEqual(CC, C)) << CC.toString() << "\n" << C.toString();
		}

		{
			float XYZ[4][4] = //angle 45 degrees
			{
				{0.683548f,	0.649495f, -0.333043f, 0.f},
				{-0.333043f, 0.683548f, 0.649495f, 0.f},
				{0.649495f, -0.333043f, 0.683548f, 0.f},
				{0.f, 0.f, 0.f, 1.f}
			};

			float YZ[4][4] = //angle 45 degrees
			{
				{0.525322,	0.60168, -0.60168, 0.f},
				{-0.60168,	0.762661, 0.237339, 0.f},
				{0.60168, 0.237339, 0.762661, 0.f},
				{0.f, 0.f, 0.f, 1.f}
			};

			float XZ[4][4] = //angle 45 degrees
			{
				{0.762661, 0.60168, 0.237339, 0.f},
				{-0.60168, 0.525322, 0.60168, 0.f},
				{0.237339, -0.60168, 0.762661, 0.f},
				{0.f, 0.f, 0.f, 1.f}
			};

			mat4f A = rotate_COL(angle, vec3f(1.f, 1.f, 1.f));
			mat4f B = rotate_COL(angle, vec3f(0.f, 1.f, 1.f));
			mat4f C = rotate_COL(angle, vec3f(1.f, 0.f, 1.f));

			mat4f AA(XYZ);
			mat4f BB(YZ);
			mat4f CC(XZ);
			ASSERT_EQ(true, almostEqual(AA, A)) << AA.toString() << "\n" << A.toString();
			ASSERT_EQ(true, almostEqual(BB, B)) << BB.toString() << "\n" << B.toString();
			ASSERT_EQ(true, almostEqual(CC, C)) << CC.toString() << "\n" << C.toString();
		}

	}

	TEST(MatrixTest, Perspective)
	{
		float const angle = 45.0f;
		float const aspect = 600.0f / 400.0f;
		float const nearDist = 0.1f;
		float const farDist = 100.0f;

		{
			float ROW[4][4] = 
			{
				{1.19506f, 0.0f, 0.0f, 0.0f},
				{0.0f, 1.79259f, 0.0f, 0.0f},
				{0.0f, 0.0f, -1.001f, -0.2002f},
				{0.0f, 0.0f, -1.0f, 0.0f}
			};

			float ROW_DEPTH[4][4] =
			{
				{1.19506f, 0.0f, 0.0f, 0.0f},
				{0.0f, 1.79259f, 0.0f, 0.0f},
				{0.0f, 0.0f, -1.001f, -0.1001},
				{0.0f, 0.0f, -1.0f, 0.0f}
			};

			mat4f A = perspective_ROW(angle, aspect, nearDist, farDist);
			mat4f B = perspective_ROW_Depth01(angle, aspect, nearDist, farDist);
			mat4f AA(ROW);
			mat4f BB(ROW_DEPTH);
			ASSERT_EQ(true, almostEqual(AA, A)) << AA.toString() << "\n" << A.toString();
			ASSERT_EQ(true, almostEqual(BB, B)) << BB.toString() << "\n" << B.toString();
		}

		{
			float COL[4][4] =
			{
				{1.19506f, 0.0f, 0.0f, 0.0f},
				{0.0f, 1.79259f, 0.0f, 0.0f},
				{0.0f, 0.0f, -1.001f, -1.f},
				{0.0f, 0.0f, -0.2002, 0.0f}
			};

			float COL_DEPTH[4][4] =
			{
				{1.19506f, 0.0f, 0.0f, 0.0f},
				{0.0f, 1.79259f, 0.0f, 0.0f},
				{0.0f, 0.0f, -1.001f, -1.f},
				{0.0f, 0.0f, -0.1001, 0.0f}
			};

			mat4f A = perspective_COL(angle, aspect, nearDist, farDist);
			mat4f B = perspective_COL_Depth01(angle, aspect, nearDist, farDist);
			mat4f AA(COL);
			mat4f BB(COL_DEPTH);
			ASSERT_EQ(true, almostEqual(AA, A)) << AA.toString() << "\n" << A.toString();
			ASSERT_EQ(true, almostEqual(BB, B)) << AA.toString() << "\n" << A.toString();
		}
	}

	TEST(MatrixTest, LookAt)
	{
		vec3f eye(0.0f, 0.0f, 0.0f);
		vec3f center(0.0f, 1.0f, 1.0f);
		vec3f up(0.0f, 1.0f, 0.0f);
		{
			float RH_ROW[4][4] =
			{
				{-1, 0, 0, 0},
				{0, 0.707107, -0.707107, 0},
				{-0, -0.707107, -0.707107, 0},
				{-0, -0, 0, 1}
			};
			mat4f A = lookAt_RH_ROW(eye, center, up);
			mat4f AA(RH_ROW);
			ASSERT_EQ(true, almostEqual(AA, A)) << AA.toString() << "\n" << A.toString();
		}

		{
			float COL_ROW[4][4] =
			{
				{-1, 0, -0, 0},
				{0, 0.707107, -0.707107, 0},
				{0, -0.707107, -0.707107, 0},
				{-0, -0, 0, 1}
			};
			mat4f A = lookAt_RH_COL(eye, center, up);
			mat4f AA(COL_ROW);
			ASSERT_EQ(true, almostEqual(AA, A)) << AA.toString() << "\n" << A.toString();
		}
	}
}
