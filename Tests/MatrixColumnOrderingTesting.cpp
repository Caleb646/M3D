#include <gtest/gtest.h>
#include <string>
#include <iostream>

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
//
#define MD_FORCE_DEPTH_ZERO_TO_ONE
#define MD_FORCE_COLUMN_MAJOR_ORDERING
#include "../M3D.h"
//
//namespace MatrixColumnOrder_Testing
//{
//	using namespace m3d;
//
//
//	bool Mat4f_GlmMat_Equality(TestMat4Col& colMat, glm::mat4& glmMat)
//	{
//		float* buff = colMat;
//		std::size_t index {};
//		for (std::size_t i = 0; i < 4; i++)
//		{
//			for (std::size_t j = 0; j < 4; j++)
//			{
//				index = (i * 4) + j;
//				float value = buff[index];
//				bool f = false;
//			}
//		}
//		for (std::size_t i = 0; i < 4; i++)
//		{
//			for (std::size_t j = 0; j < 4; j++)
//			{
//				float colv = colMat[i][j];
//				float glmv = glmMat[i][j];
//				if (colv != glmv)
//				{
//					return false;
//				}
//				float value = glmMat[i][j];
//				bool f = false;
//			}
//		}
//		return true;
//	}
//
//	std::string glmToString(glm::mat4& m)
//	{
//		std::stringstream stream;
//		for (int i = 0; i < 4; i++)
//		{
//			stream << "|| ";
//			for (std::size_t j = 0; j < 4; j++)
//			{
//				
//				stream << m[i][j];	
//				stream << " ";
//			}
//			stream << " ||";
//			stream << "\n";
//		}
//		return stream.str();
//	}
//	
	TEST(MatrixColumnOrderTest, Test_Matrix_Indexing)
	{
		glm::rotate(10.0f, glm::vec3());
		/*
		* Everything must be done a in row major way. Then if
		* it a col ordered matrix the Matrix class will handle
		* indexing into the array.
		*/
		/*TestMat4Col emptyMat{};
		TestMat4Col matRow1 = TestMat4Col::getTranslation(emptyMat, vec3f(12.0f, 15.0f, 17.0f ));
		glm::mat4 glmMat{1.0f};
		glmMat = glm::translate(glmMat, glm::vec3(12.0f, 15.0f, 17.0f));
		ASSERT_EQ(true, Mat4f_GlmMat_Equality(matRow1, glmMat));*/
	}
//	TEST(MatrixColumnOrderTest, Test_Matrix_Addition)
//	{
//		float twoDArray[4][4] = {
//			{10.0f, 0.0f, 0.0f, 0.0f},
//			{0.0f, 10.0f, 0.0f, 0.0f},
//			{0.0f, 0.0f, 10.0f, 0.0f},
//			{0.0f, 0.0f, 0.0f, 10.0f}
//		};
//		float answerArray[4][4] = {
//			{12.0f, 2.0f, 2.0f, 2.0f},
//			{2.0f, 12.0f, 2.0f, 2.0f},
//			{2.0f, 2.0f, 12.0f, 2.0f},
//			{2.0f, 2.0f, 2.0f, 12.0f}
//		};
//
//		TestMat4Col matRow1(twoDArray);
//		TestMat4Col matRow2(2.0f);
//		TestMat4Col additionMatRow;
//		TestMat4Col answerMatRow(answerArray);
//		additionMatRow = matRow1 + matRow2;
//		matRow1 += matRow2;
//		ASSERT_EQ(true, answerMatRow == additionMatRow);
//		ASSERT_EQ(true, answerMatRow == matRow1);
//	}
//	TEST(MatrixColumnOrderTest, Test_Matrix_Subtraction)
//	{
//		float twoDArray[4][4] = {
//			{10.0f, 0.0f, 0.0f, 0.0f},
//			{0.0f, 10.0f, 0.0f, 0.0f},
//			{0.0f, 0.0f, 10.0f, 0.0f},
//			{0.0f, 0.0f, 0.0f, 10.0f}
//		};
//		float answerArray[4][4] = {
//			{8.0f, -2.0f, -2.0f, -2.0f},
//			{-2.0f, 8.0f, -2.0f, -2.0f},
//			{-2.0f, -2.0f, 8.0f, -2.0f},
//			{-2.0f, -2.0f, -2.0f, 8.0f}
//		};
//		TestMat4Col matRow1(twoDArray);
//		TestMat4Col matRow2(2.0f);
//		TestMat4Col subtractionMatRow;
//		TestMat4Col answerMatRow(answerArray);
//		subtractionMatRow = matRow1 - matRow2;
//		matRow1 -= matRow2;
//		ASSERT_EQ(true, answerMatRow == subtractionMatRow) << subtractionMatRow.toString();
//		ASSERT_EQ(true, answerMatRow == matRow1) << matRow1.toString();
//	}
//	TEST(MatrixColumnOrderTest, Test_Matrix_Multiplication)
//	{
//		float twoDArray[4][4] = {
//			{10.0f, 5.0f, 10.0f, 5.0f},
//			{10.0f, 5.0f, 10.0f, 5.0f},
//			{10.0f, 5.0f, 10.0f, 5.0f},
//			{10.0f, 5.0f, 10.0f, 5.0f}
//		};
//		float answerArray[4][4] = {
//			{300.0f, 150.0f, 300.0f, 150.0f},
//			{300.0f, 150.0f, 300.0f, 150.0f},
//			{300.0f, 150.0f, 300.0f, 150.0f},
//			{300.0f, 150.0f, 300.0f, 150.0f}
//		};
//		TestMat4Col matRow1(twoDArray);
//		TestMat4Col matRow2(twoDArray);
//		TestMat4Col multiplicationMatRow;
//		TestMat4Col answerMatRow(answerArray);
//		multiplicationMatRow = matRow1 * matRow2;
//		matRow1 *= matRow2;
//		ASSERT_EQ(true, answerMatRow == multiplicationMatRow) << answerMatRow.toString() << "\n\n" << multiplicationMatRow.toString();
//		ASSERT_EQ(true, answerMatRow == matRow1) << answerMatRow.toString() << "\n\n" << matRow1.toString();
//
//
//		float answerVecArray[4][4] = {
//			{10.0f, 5.0f, 10.0f, 5.0f},
//			{10.0f, 5.0f, 10.0f, 5.0f},
//			{10.0f, 5.0f, 10.0f, 5.0f},
//			{10.0f, 5.0f, 10.0f, 5.0f}
//		};
//		vec4f multiVec(10.0f, 10.0f, 10.0f, 10.0f);
//		vec4f multiplicationVecRow;
//		vec4f answerVec(300.0f, 300.0f, 300.0f, 300.0f);
//		TestMat4Col multiVecAnswerRow(answerVecArray);
//		TestMat4Col matRow3(answerVecArray);
//		multiplicationVecRow = multiVecAnswerRow * multiVec;
//		matRow3 *= multiVec;
//		ASSERT_EQ(true, answerVec == multiplicationVecRow) << answerVec.toString() << "\n\n" << multiplicationVecRow.toString();
//		ASSERT_EQ(true, multiVecAnswerRow == matRow3) << answerVec.toString() << "\n\n" << matRow3.toString();
//
//		float scaler = 10.0f;
//		float answerScalerArray[4][4] = {
//			{20.0f, 20.0f, 20.0f, 20.0f},
//			{20.0f, 20.0f, 20.0f, 20.0f},
//			{20.0f, 20.0f, 20.0f, 20.0f},
//			{20.0f, 20.0f, 20.0f, 20.0f}
//		};
//		TestMat4Col multiplicationScalerAnswerRow(answerScalerArray);
//		TestMat4Col multiplicationScalerMatRow;
//		TestMat4Col matRow4(2.0f);
//		multiplicationScalerMatRow = matRow4 * scaler;
//		matRow4 *= scaler;
//		ASSERT_EQ(true, multiplicationScalerAnswerRow == multiplicationScalerMatRow) << multiplicationScalerMatRow.toString();
//		ASSERT_EQ(true, multiplicationScalerAnswerRow == matRow4) << matRow4.toString();
//	}
//	TEST(MatrixColumnOrderTest, Test_Matrix_Division_Column)
//	{
//		float scaler = 10.0f;
//		float answerScalerArray[4][4] = {
//			{2.0f, 2.0f, 2.0f, 2.0f},
//			{2.0f, 2.0f, 2.0f, 2.0f},
//			{2.0f, 2.0f, 2.0f, 2.0f},
//			{2.0f, 2.0f, 2.0f, 2.0f}
//		};
//		TestMat4Col divScalerRow(20.0f);
//		TestMat4Col divScalerAnswerRow(answerScalerArray);
//		TestMat4Col ret;
//		ret = divScalerRow / scaler;
//		divScalerRow /= scaler;
//		ASSERT_EQ(true, divScalerAnswerRow == ret) << ret.toString();
//		ASSERT_EQ(true, divScalerAnswerRow == divScalerRow) << divScalerRow.toString();
//	}
//	TEST(MatrixColumnOrderTest, Test_Matrix_Translation)
//	{
//		float answerArray[4][4] = {
//			{1.0f, 0.0f, 0.0f, 0.0f},
//			{0.0f, 1.0f, 0.0f, 0.0f},
//			{0.0f, 0.0f, 1.0f, 0.0f},
//			{1.0f, -1.0f, 1.0f, 1.0f}
//		};
//		TestMat4Col testMat1;
//		testMat1.getTranslated(vec3f(1.0f, -1.0f, 1.0f ));
//		TestMat4Col answerMat(answerArray);
//		ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//		//testMat1.getTranslated(vec4f({ 1.0f, -1.0f, 0.0f, 1.0f }));
//		//ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//
//		//TestMat4Col iMat{};
//		//TestMat4Col testMat2 = TestMat4Col::getTranslation(iMat, { 1.0f, -1.0f, 0.0f });
//		//ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat1.toString();
//		//testMat2 = TestMat4Col::getTranslation(iMat, vec4f({ 1.0f, -1.0f, 0.0f, 1.0f }));
//		//ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat2.toString();
//	}
//
//	TEST(MatrixColumnOrderTest, Test_Matrix_RotationZ)
//	{
//
//		float radians = degreesToRadians(45.0f);
//		float c = std::cosf(radians);
//		float s = std::sinf(radians);
//
//		float answerArray[4][4] = {
//			{c, s, 0.0f, 0.0f},
//			{-s, c, 0.0f, 0.0f},
//			{0.0f, 0.0f, 1.0f, 0.0f},
//			{0.0f, 0.0f, 0.0f, 1.0f}
//		};
//		TestMat4Col testMat1;
//		testMat1.getRotatedZ(radians);
//		TestMat4Col answerMat(answerArray);
//		ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//
//
//		TestMat4Col testMat2 = TestMat4Col::getRotateZ(radians);
//		ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat2.toString();
//	}
//
//	TEST(MatrixColumnOrderTest, Test_Matrix_Perspective)
//	{
//		float fovRads = degreesToRadians(45.0f);
//		float aspectRatio = 600.0f / 400.0f;
//		float nearDist = 0.1f;
//		float farDist = 100.0f;
//
//		float fovHalf = std::tanf(fovRads / 2.0f);
//
//		float answerArray[4][4] = {
//			{1.60948, 0.0f, 0.0f, 0.0f},
//			{0.0f, 2.41421, 0.0f, 0.0f},
//			{0.0f, 0.0f, -1.002, -1},
//			{0.0f, 0.0f, -0.1001, 0.0f}
//		};
//
//		TestMat4Col testMat1 = TestMat4Col::getPerspective(fovRads, aspectRatio, nearDist, farDist);
//		TestMat4Col answerMat(answerArray);
//
//		ASSERT_EQ(true, testMat1 == answerMat);
//	}
//
//	TEST(MatrixColumnOrderTest, Test_Matrix_LookAt)
//	{
//
//		vec3f eye(1.0f, 2.0f, 3.0f);
//		vec3f center(1.0f, 1.0f, 1.0f);
//		vec3f up(0.0f, 1.0f, 0.0f);
//		vec3f testF(normalize(center - eye));
//		vec3f testS = normalize(cross(testF, up));
//		vec3f testU = cross(testS, testF);
//		float zeroThree = dot(testS, eye);
//		float oneThree = dot(testU, eye);
//		float twoThree = dot(testF, eye);
//
//
//		float answerArray[4][4] = {
//			{1.0f, testS.y(), testS.z(), -zeroThree},
//			{testU.x(), testU.y(), testU.z(), -oneThree},
//			{-testF.x(), -testF.y(), -testF.z(), twoThree},
//			{0.0f, 0.0f, 0.0f, 1.0f}
//		};
//
//
//		glm::mat4 gLookat = glm::lookAt(glm::vec3(1.0f, 2.0f, 3.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		mat4f mdLookat = lookAt(eye, center, up);
//
//		ASSERT_EQ(true, Mat4f_GlmMat_Equality(mdLookat, gLookat)) << glmToString(gLookat) << "\n\n" << mdLookat.toString();
//
//		//ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//	}
//
//}
