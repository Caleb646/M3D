#include <gtest/gtest.h>

#define M3D_UNIT_TESTING
#include "../M3D.h"

namespace Testing_Vector_Class {


	using namespace m3d;

	bool arrayEqualToVecArray(float* arr, float* vArr, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			if (arr[i] != vArr[i])
			{
				return false;
			}	
		}
		return true;
	}

	bool initListEqualToVecArray(std::initializer_list<float> init_list, float* vArr)
	{
		int c = 0;
		for (auto i : init_list) {
			if (vArr[c++] != i)
			{
				return false;
			}
				
		}
		return true;
	}



	//TODO log.cpp is not being pulled into and is causing errors.

	//Test Equality Operators First

	TEST(VectorTest, Test_Vector_Equality)
	{
		vec4f cv4(1.0f, 12.0f, 15.0f, 17.0f);
		vec4f cv42(1.0f, 12.0f, 15.0f, 17.0f);
		ASSERT_EQ(true, cv4 == cv42);
		ASSERT_EQ(false, cv4 != cv42);
	}

	TEST(VectorTest, Test_Vector_Indexing)
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

	TEST(VectorTest, Test_Vector_Constructors)
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

		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 10.0f }, cv2.getUnderlyingArray()));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 12.0f, 15.0f }, cv3.getUnderlyingArray()));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 12.0f, 15.0f, 17.0f }, cv4.getUnderlyingArray()));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 10.0f, 1.0f, 10.0f }, cv6.getUnderlyingArray()));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 1.0f, 10.0f, 10.0f }, cv7.getUnderlyingArray()));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 1.0f, 1.0f, 10.0f }, cv8.getUnderlyingArray()));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 10.0f, 1.0f, 10.0f }, cv9.getUnderlyingArray()));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 12.0f, 15.0f, 1.0f }, cv10.getUnderlyingArray()));
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 10.0f, 1.0f, 10.0f }, cv11.getUnderlyingArray()));
		ASSERT_EQ(true, cv5 == cv4);
	}


	TEST(VectorTest, Test_Vector_Addition)
	{

		vec4f cv4(1.0f, 12.0f, 15.0f, 17.0f);
		vec4f cv42(1.0f, 2.0f, 5.0f, 7.0f);
		vec4f ans;
		ans = cv4 + cv42;
		cv4 += cv42;

		ASSERT_EQ(true, initListEqualToVecArray({ 2.0f, 14.0f, 20.0f, 24.0f }, ans.getUnderlyingArray()));
		ASSERT_EQ(true, initListEqualToVecArray({ 2.0f, 14.0f, 20.0f, 24.0f }, cv4.getUnderlyingArray()));

		const vec4f constCv4(1.0f, 12.0f, 15.0f, 17.0f);
		const vec4f constCv2(1.0f, 2.0f, 5.0f, 7.0f);
		vec4f constAns;
		constAns = constCv2 + constCv4;
		ASSERT_EQ(true, initListEqualToVecArray({ 2.0f, 14.0f, 20.0f, 24.0f }, constAns.getUnderlyingArray()));
	}

	TEST(VectorTest, Test_Vector_Subtraction)
	{

		vec4f cv4(1.0f, 12.0f, 15.0f, 17.0f);
		vec4f cv42(1.0f, 2.0f, 5.0f, 7.0f);
		vec4f ans;
		ans = cv4 - cv42;
		cv4 -= cv42;

		ASSERT_EQ(true, initListEqualToVecArray({ 0.0f, 10.0f, 10.0f, 10.0f }, ans.getUnderlyingArray()));	
		ASSERT_EQ(true, initListEqualToVecArray({ 0.0f, 10.0f, 10.0f, 10.0f }, cv4.getUnderlyingArray()));

		const vec4f constCv4(1.0f, 12.0f, 15.0f, 17.0f);
		const vec4f constCv2(1.0f, 2.0f, 5.0f, 7.0f);
		vec4f constAns;
		constAns = constCv4 - constCv2;
		ASSERT_EQ(true, initListEqualToVecArray({ 0.0f, 10.0f, 10.0f, 10.0f }, constAns.getUnderlyingArray()));
	}

	TEST(VectorTest, Test_Vector_Multiplication)
	{

		vec4f cv4(1.0f, 12.0f, 15.0f, 17.0f);
		vec4f cv42(1.0f, 2.0f, 5.0f, 7.0f);
		vec4f ans;
		ans = cv4 * cv42;
		float scaler = 10.0f;
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 24.0f, 75.0f, 119.0f }, ans.getUnderlyingArray()));

		cv4 *= cv42;
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 24.0f, 75.0f, 119.0f }, cv4.getUnderlyingArray()));

		ans = cv42 * scaler;
		cv42 *= scaler;
		ASSERT_EQ(true, initListEqualToVecArray({ 10.0f, 20.0f, 50.0f, 70.0f }, ans.getUnderlyingArray()));
		ASSERT_EQ(true, initListEqualToVecArray({ 10.0f, 20.0f, 50.0f, 70.0f }, cv42.getUnderlyingArray()));

		const vec4f constCv4(1.0f, 2.0f, 5.0f, 7.0f);
	    vec4f constAns;
		constAns = constCv4 * scaler;
		ASSERT_EQ(true, initListEqualToVecArray({ 10.0f, 20.0f, 50.0f, 70.0f }, constAns.getUnderlyingArray()));

		constAns = scaler * constCv4;
		ASSERT_EQ(true, initListEqualToVecArray({ 10.0f, 20.0f, 50.0f, 70.0f }, constAns.getUnderlyingArray()));


	}

	TEST(VectorTest, Test_Vector_Division)
	{

		vec4f cv4(10.0f, 20.0f, 30.0f, 40.0f);
		vec4f ans;
		float scaler = 10.0f;
		
		ans = cv4 / scaler;
		cv4 /= scaler;
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 2.0f, 3.0f, 4.0f }, ans.getUnderlyingArray()));	
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 2.0f, 3.0f, 4.0f }, cv4.getUnderlyingArray()));

		const vec4f constCv4(10.0f, 20.0f, 30.0f, 40.0f);
		vec4f constAns;
		constAns = constCv4 / scaler;
		ASSERT_EQ(true, initListEqualToVecArray({ 1.0f, 2.0f, 3.0f, 4.0f }, constAns.getUnderlyingArray()));

	}

	TEST(VectorTest, Test_Vector_Normalizing)
	{
		vec4f cv4(2.0f, 2.0f, 2.0f, 2.0f);
		vec4f ans = normalize(cv4);
		ASSERT_EQ(true, initListEqualToVecArray({ 0.5f, 0.5f, 0.5f, 0.5f }, ans.getUnderlyingArray()));
		ASSERT_EQ(true, initListEqualToVecArray({ 0.5f, 0.5f, 0.5f, 0.5f }, normalize(cv4).getUnderlyingArray()));
	}

	TEST(VectorTest, Test_Vector_Operations)
	{
		vec3f cv4(1.0f, 2.0f, 3.0f);
		vec3f cv42(3.0f, 2.0f, 1.0f);
		ASSERT_EQ(10.0f, dot(cv4, cv42));
		vec3f crossProduct = cross(cv4, cv42);

		ASSERT_EQ(true, initListEqualToVecArray({ -4.0f, 8.0f, -4.0f }, crossProduct.getUnderlyingArray())) << crossProduct.toString();
	}
}


