//#include <gtest/gtest.h>
//
//#include "../M3D.h"
//
//namespace MatrixTesting_Class
//{
//	using namespace m3d;
//
//	TEST(MatrixTest, Test_Matrix_Equality)
//	{
//		TestMat4Row matRow1(5.0f);
//		TestMat4Row matRow2(5.0f);
//		ASSERT_EQ(true, matRow1 == matRow2);
//		ASSERT_EQ(false, matRow1 != matRow2);
//	}
//
//	TEST(MatrixTest, Test_Matrix_Constructors)
//	{
//		//float twoDArray[4][4] = { 0 };
//		//fillDiagonal(twoDArray, 15.0f);
//
//		float twoDArray[4][4] = {
//		{15.0f, 15.0f, 15.0f, 15.0f},
//		{15.0f, 15.0f, 15.0f, 15.0f},
//		{15.0f, 15.0f, 15.0f, 15.0f},
//		{15.0f, 15.0f, 15.0f, 15.0f},
//	};
//		TestMat4Row matRow1(twoDArray);
//		TestMat4Row matRow2(15.0f);
//		TestMat4Row matRow3(matRow1);
//		ASSERT_EQ(true, matRow1 == matRow2);
//		ASSERT_EQ(false, matRow1 != matRow2);
//		ASSERT_EQ(true, matRow1 == matRow3);
//		ASSERT_EQ(false, matRow1 != matRow3);
//	}
//
//	TEST(MatrixTest, Test_Matrix_Indexing)
//	{
//		TestMat4Row iMat{};
//		TestMat4Row matRow1 = TestMat4Row::getTranslation(iMat, vec3f(12.0f, 15.0f, 17.0f));
//		ASSERT_EQ(12.0f, matRow1[3][0]);
//		ASSERT_EQ(15.0f, matRow1[3][1]);
//		ASSERT_EQ(17.0f, matRow1[3][2]);
//		ASSERT_EQ(1.0f, matRow1[3][3]);
//	}
//
//	TEST(MatrixTest, Test_Matrix_Indexing_Column)
//	{
//		/*
//		* Everything must be done a in row major way. Then if
//		* it a col ordered matrix the Matrix class will handle 
//		* indexing into the array.
//		*/
//		TestMat4Row iMat{};
//		TestMat4Col matRow1 = TestMat4Col::getTranslation(iMat, vec3f(12.0f, 15.0f, 17.0f));
//		ASSERT_EQ(12.0f, matRow1[3][0]);
//		ASSERT_EQ(15.0f, matRow1[3][1]);
//		ASSERT_EQ(17.0f, matRow1[3][2]);
//		ASSERT_EQ(1.0f, matRow1[3][3]);
//	}
//
//	TEST(MatrixTest, Test_Matrix_Addition)
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
//		TestMat4Row matRow1(twoDArray);
//		TestMat4Row matRow2(2.0f);
//		TestMat4Row additionMatRow;
//		TestMat4Row answerMatRow(answerArray);
//		additionMatRow = matRow1 + matRow2;
//		matRow1 += matRow2;
//		ASSERT_EQ(true, answerMatRow == additionMatRow);
//		ASSERT_EQ(true, answerMatRow == matRow1);
//	}
//
//	TEST(MatrixTest, Test_Matrix_Addition_Column)
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
//		TestMat4Col matRow1(twoDArray);
//		TestMat4Col matRow2(2.0f);
//		TestMat4Col additionMatRow;
//		TestMat4Col answerMatRow(answerArray);
//		additionMatRow = matRow1 + matRow2;
//		matRow1 += matRow2;
//		ASSERT_EQ(true, answerMatRow == additionMatRow);
//		ASSERT_EQ(true, answerMatRow == matRow1);
//	}
//
//	TEST(MatrixTest, Test_Matrix_Subtraction)
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
//		TestMat4Row matRow1(twoDArray);
//		TestMat4Row matRow2(2.0f);
//		TestMat4Row subtractionMatRow;
//		TestMat4Row answerMatRow(answerArray);
//		subtractionMatRow = matRow1 - matRow2;
//		matRow1 -= matRow2;
//		ASSERT_EQ(true, answerMatRow == subtractionMatRow) << subtractionMatRow.toString();
//		ASSERT_EQ(true, answerMatRow == matRow1) << matRow1.toString();
//	}
//
//	TEST(MatrixTest, Test_Matrix_Subtraction_Column)
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
//
//	TEST(MatrixTest, Test_Matrix_Multiplication)
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
//		TestMat4Row matRow1(twoDArray);
//		TestMat4Row matRow2(twoDArray);
//		TestMat4Row multiplicationMatRow;
//		TestMat4Row answerMatRow(answerArray);
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
//		TestVec4 multiVec(10.0f, 10.0f, 10.0f, 10.0f);
//		TestVec4 multiplicationVecRow;
//		TestVec4 answerVec(300.0f, 300.0f, 300.0f, 300.0f);
//		TestMat4Row multiVecAnswerRow(answerVecArray);
//		TestMat4Row matRow3(answerVecArray);
//		multiplicationVecRow = multiVecAnswerRow * multiVec;
//		matRow3 *= multiVec;
//		ASSERT_EQ(true, answerVec == multiplicationVecRow) << answerVec.toString() << "\n\n" << multiplicationVecRow.toString();
//		ASSERT_EQ(true, multiVecAnswerRow == matRow3) << matRow3.toString();
//
//		float scaler = 10.0f;
//		float answerScalerArray[4][4] = {
//			{20.0f, 20.0f, 20.0f, 20.0f},
//			{20.0f, 20.0f, 20.0f, 20.0f},
//			{20.0f, 20.0f, 20.0f, 20.0f},
//			{20.0f, 20.0f, 20.0f, 20.0f}
//		};
//		TestMat4Row multiplicationScalerAnswerRow(answerScalerArray);
//		TestMat4Row multiplicationScalerMatRow;
//		TestMat4Row matRow4(2.0f);
//		multiplicationScalerMatRow = matRow4 * scaler;
//		matRow4 *= scaler;
//		ASSERT_EQ(true, multiplicationScalerAnswerRow == multiplicationScalerMatRow) << multiplicationScalerMatRow.toString();
//		ASSERT_EQ(true, multiplicationScalerAnswerRow == matRow4) << matRow4.toString();
//	}
//
//
//	TEST(MatrixTest, Test_Matrix_Multiplication_Column)
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
//		TestVec4 multiVec(10.0f, 10.0f, 10.0f, 10.0f);
//		TestVec4 multiplicationVecRow;
//		TestVec4 answerVec(300.0f, 300.0f, 300.0f, 300.0f);
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
//
//	TEST(MatrixTest, Test_Matrix_Division)
//	{
//		float scaler = 10.0f;
//		float answerScalerArray[4][4] = {
//			{2.0f, 2.0f, 2.0f, 2.0f},
//			{2.0f, 2.0f, 2.0f, 2.0f},
//			{2.0f, 2.0f, 2.0f, 2.0f},
//			{2.0f, 2.0f, 2.0f, 2.0f}
//		};
//		TestMat4Row divScalerRow(20.0f);
//		TestMat4Row divScalerAnswerRow(answerScalerArray);
//		TestMat4Row ret;
//		ret = divScalerRow / scaler;
//		divScalerRow /= scaler;
//		ASSERT_EQ(true, divScalerAnswerRow == ret) << ret.toString();
//		ASSERT_EQ(true, divScalerAnswerRow == divScalerRow) << divScalerRow.toString();
//	}
//
//	TEST(MatrixTest, Test_Matrix_Division_Column)
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
//
//	TEST(MatrixTest, Test_Matrix_Translation)
//	{
//		float answerArray[4][4] = {
//			{1.0f, 0.0f, 0.0f, 0.0f},
//			{0.0f, 1.0f, 0.0f, 0.0f},
//			{0.0f, 0.0f, 1.0f, 0.0f},
//			{1.0f, -1.0f, 1.0f, 1.0f}
//		};
//		TestMat4Row testMat1;
//		testMat1.getTranslated(vec3f(1.0f, -1.0f, 1.0f));
//		TestMat4Row answerMat(answerArray);
//		ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//		//testMat1.getTranslated(TestVec4({ 1.0f, -1.0f, 0.0f, 1.0f }));
//		//ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//
//		//TestMat4Row iMat{};
//		//TestMat4Row testMat2 = TestMat4Row::getTranslation(iMat, { 1.0f, -1.0f, 0.0f });
//		//ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat1.toString();
//		//testMat2 = TestMat4Row::getTranslation(iMat, TestVec4({ 1.0f, -1.0f, 0.0f, 1.0f }));
//		//ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat2.toString();
//	}
//
//	TEST(MatrixTest, Test_Matrix_Translation_Column)
//	{
//		float answerArray[4][4] = {
//			{1.0f, 0.0f, 0.0f, 1.0f},
//			{0.0f, 1.0f, 0.0f, -1.0f},
//			{0.0f, 0.0f, 1.0f, 0.0f},
//			{0.0f, 0.0f, 0.0f, 1.0f}
//		};
//		TestMat4Col testMat1;
//		testMat1.getTranslated(vec3f(1.0f, -1.0f, 1.0f));
//		TestMat4Col answerMat(answerArray);
//		ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//		testMat1.getTranslated(TestVec4({ 1.0f, -1.0f, 0.0f, 1.0f }));
//		ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//
//		TestMat4Col iMat;
//		TestMat4Col testMat2 = TestMat4Col::getTranslation(iMat, vec3f(12.0f, 15.0f, 17.0f));
//		ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat1.toString();
//		testMat2 = TestMat4Col::getTranslation(iMat, TestVec4({ 1.0f, -1.0f, 0.0f, 1.0f }));
//		ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat2.toString();
//	}
//
//	TEST(MatrixTest, Test_Matrix_RotationX)
//	{
//
//		float radians = degreesToRadians(45.0f);
//		float c = std::cosf(radians);
//		float s = std::sinf(radians);
//
//		float answerArray[4][4] = {
//			{1.0f, 0.0f, 0.0f, 0.0f},
//			{0.0f, c, s, 0.0f},
//			{0.0f, -s, c, 0.0f},
//			{0.0f, 0.0f, 0.0f, 1.0f}
//		};
//		TestMat4Row testMat1;
//		testMat1.getRotatedX(radians);
//		TestMat4Row answerMat(answerArray);
//		ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//
//
//		TestMat4Row testMat2 = TestMat4Row::getRotateX(radians);
//		ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat2.toString();
//	}
//
//	TEST(MatrixTest, Test_Matrix_RotationY)
//	{
//
//		float radians = degreesToRadians(45.0f);
//		float c = std::cosf(radians);
//		float s = std::sinf(radians);
//
//		float answerArray[4][4] = {
//			{c, 0.0f, s, 0.0f},
//			{0.0f, 1.0f, 0.0f, 0.0f},
//			{-s, 0.0f, c, 0.0f},
//			{0.0f, 0.0f, 0.0f, 1.0f}
//		};
//		TestMat4Row testMat1;
//		testMat1.getRotatedY(radians);
//		TestMat4Row answerMat(answerArray);
//		ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//
//
//		TestMat4Row testMat2 = TestMat4Row::getRotateY(radians);
//		ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat2.toString();
//	}
//
//	TEST(MatrixTest, Test_Matrix_RotationZ)
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
//		TestMat4Row testMat1;
//		testMat1.getRotatedZ(radians);
//		TestMat4Row answerMat(answerArray);
//		ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//
//
//		TestMat4Row testMat2 = TestMat4Row::getRotateZ(radians);
//		ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat2.toString();
//	}
//
//	TEST(MatrixTest, Test_Matrix_RotationZ_Column)
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
//	TEST(MatrixTest, Test_Matrix_Perspective)
//	{
//		float fovRads = degreesToRadians(45.0f);
//		float aspectRatio = 600.0f / 400.0f;
//		float nearDist = 0.1f;
//		float farDist = 100.0f;
//
//		float fovHalf = std::tanf(fovRads / 2.0f);
//
//		float answerArray[4][4] = {
//			{1.0f / (aspectRatio * fovHalf), 0.0f, 0.0f, 0.0f},
//			{0.0f, 1.0f / fovHalf, 0.0f, 0.0f},
//			{0.0f, 0.0f, farDist / (nearDist - farDist), -(2.0f * farDist * nearDist) / (farDist - nearDist)},
//			{0.0f, 0.0f, -1.0f, 0.0f}
//		};
//
//		TestMat4Row answerMat(answerArray);
//		TestMat4Row testMat2 = TestMat4Row::getPerspective(fovRads, aspectRatio, nearDist, farDist);
//		ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat2.toString();
//	}
//
//	TEST(MatrixTest, Test_Matrix_Perspective_Column)
//	{
//		float fovRads = degreesToRadians(45.0f);
//		float aspectRatio = 600.0f / 400.0f;
//		float nearDist = 0.1f;
//		float farDist = 100.0f;
//
//		float fovHalf = std::tanf(fovRads / 2.0f);
//
//		float answerArray[4][4] = {
//			{1.0f / (aspectRatio * fovHalf), 0.0f, 0.0f, 0.0f},
//			{0.0f, 1.0f / fovHalf, 0.0f, 0.0f},
//			{0.0f, 0.0f, farDist / (nearDist - farDist), -(2.0f * farDist * nearDist) / (farDist - nearDist)},
//			{0.0f, 0.0f, -1.0f, 0.0f}
//		};
//
//		TestMat4Col answerMat(answerArray);
//		TestMat4Col testMat2 = TestMat4Col::getPerspective(fovRads, aspectRatio, nearDist, farDist);
//		ASSERT_EQ(true, answerMat == testMat2) << answerMat.toString() << "\n\n" << testMat2.toString();
//	}
//
//	TEST(MatrixTest, Test_Matrix_LookAt)
//	{
//
//		TestVec3 eye(0.0f, 0.0f, 0.0f);
//		TestVec3 center(0.0f, 1.0f, 1.0f);
//		TestVec3 up(0.0f, 1.0f, 0.0f);
//		TestVec3 testF(center - eye);
//		testF.normalized();
//		TestVec3 testS = TestVec3::cross(testF, up);
//		testS.normalized();
//		TestVec3 testU = TestVec3::cross(testS, testF);
//		float zeroThree = TestVec3::dot(testS, eye);
//		float oneThree = TestVec3::dot(testU, eye);
//		float twoThree = TestVec3::dot(testF, eye);
//
//		float answerArray[4][4] = {
//			{testS.x(), testS.y(), testS.z(), -zeroThree},
//			{testU.x(), testU.y(), testU.z(), -oneThree},
//			{-testF.x(), -testF.y(), -testF.z(), twoThree},
//			{0.0f, 0.0f, 0.0f, 1.0f}
//		};
//
//		TestMat4Row testMat1 = TestMat4Row::getLookAt(eye, center, up);
//		TestMat4Row answerMat(answerArray);
//		ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//	}
//
//	TEST(MatrixTest, Test_Matrix_LookAt_Column)
//	{
//
//		TestVec3 eye(0.0f, 0.0f, 0.0f);
//		TestVec3 center(0.0f, 1.0f, 1.0f);
//		TestVec3 up(0.0f, 1.0f, 0.0f);
//		TestVec3 testF(center - eye);
//		testF.normalized();
//		TestVec3 testS = TestVec3::cross(testF, up);
//		testS.normalized();
//		TestVec3 testU = TestVec3::cross(testS, testF);
//		float zeroThree = TestVec3::dot(testS, eye);
//		float oneThree = TestVec3::dot(testU, eye);
//		float twoThree = TestVec3::dot(testF, eye);
//
//
//		float answerArray[4][4] = {
//			{testS.x(), testS.y(), testS.z(), -zeroThree},
//			{testU.x(), testU.y(), testU.z(), -oneThree},
//			{-testF.x(), -testF.y(), -testF.z(), twoThree},
//			{0.0f, 0.0f, 0.0f, 1.0f}
//		};
//
//		//float answerArray[4][4] = {
//		//	{testS.x(), testU.x(), -testF.x(), 0.0f},
//		//	{testS.y(), testU.y(), -testF.y(), 0.0f},
//		//	{testS.z(), testU.z(), -testF.z(), 0.0f},
//		//	{-zeroThree, -oneThree, twoThree, 1.0f}
//		//};
//
//		TestMat4Col testMat1 = TestMat4Col::getLookAt(eye, center, up);
//		TestMat4Col answerMat(answerArray);
//		ASSERT_EQ(true, answerMat == testMat1) << answerMat.toString() << "\n\n" << testMat1.toString();
//	}
//
//}
