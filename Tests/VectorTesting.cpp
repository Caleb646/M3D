#include <gtest/gtest.h>

#define M3D_UNIT_TESTING
#include "../M3D.h"

namespace VectorTesting {


	using namespace m3d;

	template<typename T, std::size_t SIZE>
	bool initListEqualToVec(std::initializer_list<float> init_list, const Vector<T, SIZE>& v)
	{
		int c = 0;
		for (auto i : init_list) {
			if (v[c++] != i)
			{
				return false;
			}
				
		}
		return true;
	}
	TEST(VectorTest, Equality)
	{
		vec4f cv4(1.0f, 12.0f, 15.0f, 17.0f);
		vec4f cv42(1.0f, 12.0f, 15.0f, 17.0f);
		ASSERT_EQ(true, cv4 == cv42);
		ASSERT_EQ(false, cv4 != cv42);
	}

	TEST(VectorTest, Indexing)
	{
		vec4f cv4(1.0f, 12.0f, 15.0f, 17.0f);
		ASSERT_EQ(true, cv4[0] == 1.0f);
		ASSERT_EQ(true, cv4[1] == 12.0f);
		ASSERT_EQ(true, cv4[2] == 15.0f);
		ASSERT_EQ(true, cv4[3] == 17.0f);

		ASSERT_EQ(true, cv4.x() == 1.0f);
		ASSERT_EQ(true, cv4.y() == 12.0f);
		ASSERT_EQ(true, cv4.z() == 15.0f);
		ASSERT_EQ(true, cv4.w() == 17.0f);
	}

	TEST(VectorTest, Constructors)
	{
		vec2f cv2(1.0f, 10.0f);
		vec3f cv3(1.0f, 12.0f, 15.0f);
		vec4f cv4(1.0f, 12.0f, 15.0f, 17.0f);
		vec4f cv5(cv4);
		vec4f cv6(cv2, 1.0f, 10.0f);
		vec4f cv7(1.0f, cv2, 10.0f);
		vec4f cv8(1.0f, 1.0f, cv2);
		vec4f cv9(cv2, cv2);
		vec4f cv10(cv3, 1.0f);
		vec4f cv11({ 1.0f, 10.0f, 1.0f, 10.0f });

		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 10.0f }, cv2));
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 12.0f, 15.0f }, cv3));
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 12.0f, 15.0f, 17.0f }, cv4));
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 10.0f, 1.0f, 10.0f }, cv6));
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 1.0f, 10.0f, 10.0f }, cv7));
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 1.0f, 1.0f, 10.0f }, cv8));
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 10.0f, 1.0f, 10.0f }, cv9));
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 12.0f, 15.0f, 1.0f }, cv10));
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 10.0f, 1.0f, 10.0f }, cv11));
		ASSERT_EQ(true, cv5 == cv4);
	}


	TEST(VectorTest, Addition)
	{

		vec4f cv4(1.0f, 12.0f, 15.0f, 17.0f);
		vec4f cv42(1.0f, 2.0f, 5.0f, 7.0f);
		vec4f ans;
		ans = cv4 + cv42;
		cv4 += cv42;

		ASSERT_EQ(true, initListEqualToVec({ 2.0f, 14.0f, 20.0f, 24.0f }, ans));
		ASSERT_EQ(true, initListEqualToVec({ 2.0f, 14.0f, 20.0f, 24.0f }, cv4));

		const vec4f constCv4(1.0f, 12.0f, 15.0f, 17.0f);
		const vec4f constCv2(1.0f, 2.0f, 5.0f, 7.0f);
		vec4f constAns;
		constAns = constCv2 + constCv4;
		ASSERT_EQ(true, initListEqualToVec({ 2.0f, 14.0f, 20.0f, 24.0f }, constAns));
	}

	TEST(VectorTest, Subtraction)
	{

		vec4f cv4(1.0f, 12.0f, 15.0f, 17.0f);
		vec4f cv42(1.0f, 2.0f, 5.0f, 7.0f);
		vec4f ans;
		ans = cv4 - cv42;
		cv4 -= cv42;

		ASSERT_EQ(true, initListEqualToVec({ 0.0f, 10.0f, 10.0f, 10.0f }, ans));	
		ASSERT_EQ(true, initListEqualToVec({ 0.0f, 10.0f, 10.0f, 10.0f }, cv4));

		const vec4f constCv4(1.0f, 12.0f, 15.0f, 17.0f);
		const vec4f constCv2(1.0f, 2.0f, 5.0f, 7.0f);
		vec4f constAns;
		constAns = constCv4 - constCv2;
		ASSERT_EQ(true, initListEqualToVec({ 0.0f, 10.0f, 10.0f, 10.0f }, constAns));
	}

	TEST(VectorTest, Multiplication)
	{

		vec4f cv4(1.0f, 12.0f, 15.0f, 17.0f);
		vec4f cv42(1.0f, 2.0f, 5.0f, 7.0f);
		vec4f ans;
		ans = cv4 * cv42;
		float scaler = 10.0f;
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 24.0f, 75.0f, 119.0f }, ans));

		cv4 *= cv42;
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 24.0f, 75.0f, 119.0f }, cv4));

		ans = cv42 * scaler;
		cv42 *= scaler;
		ASSERT_EQ(true, initListEqualToVec({ 10.0f, 20.0f, 50.0f, 70.0f }, ans));
		ASSERT_EQ(true, initListEqualToVec({ 10.0f, 20.0f, 50.0f, 70.0f }, cv42));

		const vec4f constCv4(1.0f, 2.0f, 5.0f, 7.0f);
	    vec4f constAns;
		constAns = constCv4 * scaler;
		ASSERT_EQ(true, initListEqualToVec({ 10.0f, 20.0f, 50.0f, 70.0f }, constAns));

		constAns = scaler * constCv4;
		ASSERT_EQ(true, initListEqualToVec({ 10.0f, 20.0f, 50.0f, 70.0f }, constAns));
	}

	TEST(VectorTest, Division)
	{

		vec4f cv4(10.0f, 20.0f, 30.0f, 40.0f);
		vec4f ans;
		float scaler = 10.0f;
		
		ans = cv4 / scaler;
		cv4 /= scaler;
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 2.0f, 3.0f, 4.0f }, ans));	
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 2.0f, 3.0f, 4.0f }, cv4));

		const vec4f constCv4(10.0f, 20.0f, 30.0f, 40.0f);
		vec4f constAns;
		constAns = constCv4 / scaler;
		ASSERT_EQ(true, initListEqualToVec({ 1.0f, 2.0f, 3.0f, 4.0f }, constAns));

	}

	TEST(VectorTest, Normalizing)
	{
		vec4f cv4(2.0f, 2.0f, 2.0f, 2.0f);
		ASSERT_EQ(true, initListEqualToVec({ 0.5f, 0.5f, 0.5f, 0.5f }, normalize(cv4)));
	}

	TEST(VectorTest, Operations)
	{
		vec3f cv4(1.0f, 2.0f, 3.0f);
		vec3f cv42(3.0f, 2.0f, 1.0f);
		ASSERT_EQ(10.0f, dot(cv4, cv42));
		ASSERT_EQ(true, initListEqualToVec({ -4.0f, 8.0f, -4.0f }, cross(cv4, cv42)));
	}
}


