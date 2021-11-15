#include <gtest/gtest.h>
#include "../M3D.h"

namespace Testing_Vector_Class {


	using namespace m3d;

	bool arrayEqualToVecArray(float* arr, float* vArr, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			if (arr[i] != vArr[i])
				return false;
		}
		return true;
	}

	bool initListEqualToVecArray(std::initializer_list<float> init_list, float* vArr)
	{
		int c = 0;
		for (auto i = init_list.begin(); i != init_list.end(); i++) {
			if (vArr[c++] != *i)
				return false;
		}
		return true;
	}



	//TODO log.cpp is not being pulled into and is causing errors.

	//Test Equality Operators First

	TEST(VectorTest, Test_Vector_Equality)
	{
		TestVec4 cv4(1.0f, 12.0f, 15.0f, 17.0f);
		TestVec4 cv42(1.0f, 12.0f, 15.0f, 17.0f);
		ASSERT_EQ(true, cv4 == cv42);
		ASSERT_EQ(false, cv4 != cv42);
	}

	TEST(VectorTest, Test_Vector_Indexing)
	{
		TestVec4 cv4(1.0f, 12.0f, 15.0f, 17.0f);
		ASSERT_EQ(true, cv4[0] == 1.0f);
		ASSERT_EQ(true, cv4[1] == 12.0f);
		ASSERT_EQ(true, cv4[2] == 15.0f);
		ASSERT_EQ(true, cv4[3] == 17.0f);

		ASSERT_EQ(true, cv4.x() == 1.0f);
		ASSERT_EQ(true, cv4.y() == 12.0f);
		ASSERT_EQ(true, cv4.z() == 15.0f);
		ASSERT_EQ(true, cv4.w() == 17.0f);
	}

	TEST(VectorTest, Test_Vector_Constructors)
	{
		TestVec2 cv2(1.0f, 10.0f);
		TestVec3 cv3(1.0f, 12.0f, 15.0f);
		TestVec4 cv4(1.0f, 12.0f, 15.0f, 17.0f);
		TestVec4 cv5(cv4);
		TestVec4 cv6(cv2, 1.0f, 10.0f);
		TestVec4 cv7(1.0f, cv2, 10.0f);
		TestVec4 cv8(1.0f, 1.0f, cv2);
		TestVec4 cv9(cv2, cv2);
		TestVec4 cv10(cv3, 1.0f);
		TestVec4 cv11({ 1.0f, 10.0f, 1.0f, 10.0f });

		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 10.0f }, cv2.v));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 12.0f, 15.0f }, cv3.v));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 12.0f, 15.0f, 17.0f }, cv4.v));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 10.0f, 1.0f, 10.0f }, cv6.v));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 1.0f, 10.0f, 10.0f }, cv7.v));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 1.0f, 1.0f, 10.0f }, cv8.v));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 10.0f, 1.0f, 10.0f }, cv9.v));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 12.0f, 15.0f, 1.0f }, cv10.v));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 10.0f, 1.0f, 10.0f }, cv11.v));
		ASSERT_EQ(true, cv5 == cv4);
	}


	TEST(VectorTest, Test_Vector_Addition)
	{

		TestVec4 cv4(1.0f, 12.0f, 15.0f, 17.0f);
		TestVec4 cv42(1.0f, 2.0f, 5.0f, 7.0f);
		TestVec4 ans;
		ans = cv4 + cv42;
		cv4 += cv42;

		ASSERT_EQ(true, initListEqualToVecArray({ 2.0f, 14.0f, 20.0f, 24.0f }, ans.v));
		ASSERT_EQ(true, initListEqualToVecArray({ 2.0f, 14.0f, 20.0f, 24.0f }, cv4.v));

		const TestVec4 constCv4(1.0f, 12.0f, 15.0f, 17.0f);
		const TestVec4 constCv2(1.0f, 2.0f, 5.0f, 7.0f);
		TestVec4 constAns;
		constAns = constCv2 + constCv4;
		ASSERT_EQ(true, initListEqualToVecArray({ 2.0f, 14.0f, 20.0f, 24.0f }, constAns.v));
	}

	TEST(VectorTest, Test_Vector_Subtraction)
	{

		TestVec4 cv4(1.0f, 12.0f, 15.0f, 17.0f);
		TestVec4 cv42(1.0f, 2.0f, 5.0f, 7.0f);
		TestVec4 ans;
		ans = cv4 - cv42;
		cv4 -= cv42;

		ASSERT_EQ(true, initListEqualToVecArray({ 0.0f, 10.0f, 10.0f, 10.0f }, ans.v));	
		ASSERT_EQ(true, initListEqualToVecArray({ 0.0f, 10.0f, 10.0f, 10.0f }, cv4.v));

		const TestVec4 constCv4(1.0f, 12.0f, 15.0f, 17.0f);
		const TestVec4 constCv2(1.0f, 2.0f, 5.0f, 7.0f);
		TestVec4 constAns;
		constAns = constCv4 - constCv2;
		ASSERT_EQ(true, initListEqualToVecArray({ 0.0f, 10.0f, 10.0f, 10.0f }, constAns.v));
	}

	TEST(VectorTest, Test_Vector_Multiplication)
	{

		TestVec4 cv4(1.0f, 12.0f, 15.0f, 17.0f);
		TestVec4 cv42(1.0f, 2.0f, 5.0f, 7.0f);
		TestVec4 ans;
		ans = cv4 * cv42;
		float scaler = 10.0f;
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 24.0f, 75.0f, 119.0f }, ans.v));

		cv4 *= cv42;
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 24.0f, 75.0f, 119.0f }, cv4.v));

		ans = cv42 * scaler;
		cv42 *= scaler;
		ASSERT_EQ(true, initListEqualToVecArray({ 10.0f, 20.0f, 50.0f, 70.0f }, ans.v));
		ASSERT_EQ(true, initListEqualToVecArray({ 10.0f, 20.0f, 50.0f, 70.0f }, cv42.v));

		const TestVec4 constCv4(1.0f, 2.0f, 5.0f, 7.0f);
	    TestVec4 constAns;
		constAns = constCv4 * scaler;
		ASSERT_EQ(true, initListEqualToVecArray({ 10.0f, 20.0f, 50.0f, 70.0f }, constAns.v));

		constAns = scaler * constCv4;
		ASSERT_EQ(true, initListEqualToVecArray({ 10.0f, 20.0f, 50.0f, 70.0f }, constAns.v));


	}

	TEST(VectorTest, Test_Vector_Division)
	{

		TestVec4 cv4(10.0f, 20.0f, 30.0f, 40.0f);
		TestVec4 ans;
		float scaler = 10.0f;
		
		ans = cv4 / scaler;
		cv4 /= scaler;
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 2.0f, 3.0f, 4.0f }, ans.v));	
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 2.0f, 3.0f, 4.0f }, cv4.v));

		const TestVec4 constCv4(10.0f, 20.0f, 30.0f, 40.0f);
		TestVec4 constAns;
		constAns = constCv4 / scaler;
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 2.0f, 3.0f, 4.0f }, constAns.v));

	}

	TEST(VectorTest, Test_Vector_Normalizing)
	{
		TestVec4 cv4(2.0f, 2.0f, 2.0f, 2.0f);
		TestVec4 ans = cv4.normalize();
		cv4.normalized();
		ASSERT_EQ(true, initListEqualToVecArray({ 0.5f, 0.5f, 0.5f, 0.5f }, ans.v));
		ASSERT_EQ(true, initListEqualToVecArray({ 0.5f, 0.5f, 0.5f, 0.5f }, cv4.v));
	}

	TEST(VectorTest, Test_Vector_Operations)
	{
		TestVec3 cv4(1.0f, 2.0f, 3.0f);
		TestVec3 cv42(3.0f, 2.0f, 1.0f);
		ASSERT_EQ(10.0f, TestVec3::dot(cv4, cv42));
		TestVec3 crossProduct = TestVec3::cross(cv4, cv42);
		ASSERT_EQ(true, initListEqualToVecArray({ -4.0f, 8.0f, -4.0f }, crossProduct.v)) << crossProduct.toString();
	}
}


