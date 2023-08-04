#include "pch.h"
#include "../oop_lab4_prog/lab4.h"

TEST(ConvertTimeToSeconds, ExtremeValues) {
	CTime TimeExample1(-1, 4, 13.0), TimeExample11(0, 0, 0.0);
	EXPECT_EQ(TimeExample1.ConvertTimeToSeconds(), -1);
	EXPECT_EQ(TimeExample11.ConvertTimeToSeconds(TimeExample1), -1);

	CTime TimeExample2(1, -4, 13.0), TimeExample22(0, 0, 0.0);
	EXPECT_EQ(TimeExample2.ConvertTimeToSeconds(), -1);
	EXPECT_EQ(TimeExample22.ConvertTimeToSeconds(TimeExample2), -1);

	CTime TimeExample3(1, -4, -13.0), TimeExample33(0, 0, 0.0);
	EXPECT_EQ(TimeExample3.ConvertTimeToSeconds(), -1);
	EXPECT_EQ(TimeExample33.ConvertTimeToSeconds(TimeExample3), -1);

	CTime TimeExample4(1, 4, NAN), TimeExample44(0, 0, 0.0);
	EXPECT_TRUE(std::isnan(TimeExample4.ConvertTimeToSeconds()));
	EXPECT_TRUE(std::isnan(TimeExample44.ConvertTimeToSeconds(TimeExample4)));

	CTime TimeExample5(1, 4, INFINITY), TimeExample55(0, 0, 0.0);
	EXPECT_TRUE(std::isinf(TimeExample5.ConvertTimeToSeconds()));
	EXPECT_TRUE(std::isinf(TimeExample55.ConvertTimeToSeconds(TimeExample5)));
}

TEST(ConvertTimeToSeconds, ValidInput) {
	CTime TimeExample1(1, 4, 19.0), TimeExample11(0, 0, 1.0);
	EXPECT_DOUBLE_EQ(TimeExample1.ConvertTimeToSeconds(), 3859.0);
	EXPECT_DOUBLE_EQ(TimeExample1.ConvertTimeToSeconds(TimeExample11), 3860.0);

	CTime TimeExample2(2, 10, 3.0), TimeExample22(0, 1, 0.0);
	EXPECT_DOUBLE_EQ(TimeExample2.ConvertTimeToSeconds(), 7803.0);
	EXPECT_DOUBLE_EQ(TimeExample2.ConvertTimeToSeconds(TimeExample22), 7863.0);

	CTime TimeExample3(0, 2, 10.0), TimeExample33(1, 0, 1.0);
	EXPECT_DOUBLE_EQ(TimeExample3.ConvertTimeToSeconds(), 130.0);
	EXPECT_DOUBLE_EQ(TimeExample3.ConvertTimeToSeconds(TimeExample33), 3731.0);
}

TEST(SubtractionDifferenceInSeconds, ExtremeValues) {
	CTime TimeExample1(1, 2, NAN), TimeExample2(1, 2, 3.0);
	EXPECT_TRUE(std::isnan(TimeExample1.SubtractionDifferenceInSeconds(TimeExample2)));
	EXPECT_TRUE(std::isnan(TimeExample1.SubtractionDifferenceInSeconds(1, 2, 3.0)));

	CTime TimeExample3(1, 3, 3.0), TimeExample4(1, 2, NAN);
	EXPECT_TRUE(std::isnan(TimeExample3.SubtractionDifferenceInSeconds(TimeExample4)));
	EXPECT_TRUE(std::isnan(TimeExample3.SubtractionDifferenceInSeconds(1, 2, NAN)));

	CTime TimeExample5(1, 2, 2.0), TimeExample6(1, 2, INFINITY);
	EXPECT_TRUE(std::isinf(TimeExample5.SubtractionDifferenceInSeconds(TimeExample6)));
	EXPECT_TRUE(std::isinf(TimeExample5.SubtractionDifferenceInSeconds(1, 2, INFINITY)));

	CTime TimeExample7(1, 2, INFINITY), TimeExample8(1, 2, 2.0);
	EXPECT_TRUE(std::isinf(TimeExample7.SubtractionDifferenceInSeconds(TimeExample8)));
	EXPECT_TRUE(std::isinf(TimeExample7.SubtractionDifferenceInSeconds(1, 2, 2.0)));
}

TEST(SubtractionDifferenceInSeconds, ValidInput) {
	CTime TimeExample1(1, 2, 3.0), TimeExample2(1, 2, 3.0);
	EXPECT_DOUBLE_EQ(TimeExample1.SubtractionDifferenceInSeconds(TimeExample2), 0.0);
	EXPECT_DOUBLE_EQ(TimeExample1.SubtractionDifferenceInSeconds(1, 2, 3.0), 0.0);

	CTime TimeExample3(1, 3, 3.0), TimeExample4(1, 2, 3.0);
	EXPECT_DOUBLE_EQ(TimeExample3.SubtractionDifferenceInSeconds(TimeExample4), 60.0);
	EXPECT_DOUBLE_EQ(TimeExample3.SubtractionDifferenceInSeconds(1, 2, 3.0), 60.0);

	CTime TimeExample5(1, 2, 2.0), TimeExample6(1, 2, 3.0);
	EXPECT_DOUBLE_EQ(TimeExample5.SubtractionDifferenceInSeconds(TimeExample6), -1.0);
	EXPECT_DOUBLE_EQ(TimeExample5.SubtractionDifferenceInSeconds(1, 2, 3.0), -1.0);
}

TEST(Add, ValidInput) {
	CTime TimeExample1(1, 2, 3.0), TimeExample2(1, 2, 3.0), TimeExample11(1, 2, 3.0);

	TimeExample1 = TimeExample1.Add(TimeExample2);
	EXPECT_EQ(TimeExample1.GetHours(), 2);
	EXPECT_EQ(TimeExample1.GetMinutes(), 4);
	EXPECT_DOUBLE_EQ(TimeExample1.GetSeconds(), 6.0);

	TimeExample11 = TimeExample11.Add(3723);
	EXPECT_EQ(TimeExample11.GetHours(), 2);
	EXPECT_EQ(TimeExample11.GetMinutes(), 4);
	EXPECT_DOUBLE_EQ(TimeExample11.GetSeconds(), 6.0);


	CTime TimeExample3(2, 34, 43.0), TimeExample4(1, 30, 26.0), TimeExample33(2, 34, 43.0);

	TimeExample3 = TimeExample3.Add(TimeExample4);
	EXPECT_EQ(TimeExample3.GetHours(), 4);
	EXPECT_EQ(TimeExample3.GetMinutes(), 5);
	EXPECT_DOUBLE_EQ(TimeExample3.GetSeconds(), 9.0);

	TimeExample33 = TimeExample33.Add(5426);
	EXPECT_EQ(TimeExample33.GetHours(), 4);
	EXPECT_EQ(TimeExample33.GetMinutes(), 5);
	EXPECT_DOUBLE_EQ(TimeExample33.GetSeconds(), 9.0);
}


TEST(OperatorsTest, PlusTest) {
	const CTime TimeExample1(1, 2, 3.0), TimeExample2(1, 2, 3.0);
	CTime TimeExample3{ TimeExample1 + TimeExample2 };
	EXPECT_EQ(TimeExample3.GetHours(), 2);
	EXPECT_EQ(TimeExample3.GetMinutes(), 4);
	EXPECT_EQ(TimeExample3.GetSeconds(), 6);

	CTime TimeExample4(2, 2, 3.0), TimeExample5(1, 12, 58.0);
	CTime TimeExample6{ TimeExample4 + TimeExample5 };
	EXPECT_EQ(TimeExample6.GetHours(), 3);
	EXPECT_EQ(TimeExample6.GetMinutes(), 15);
	EXPECT_EQ(TimeExample6.GetSeconds(), 1);

	CTime TimeExample7(1, 2, 3.0);
	TimeExample7 = TimeExample7 + 3600.0;
	EXPECT_EQ(TimeExample7.GetHours(), 2);
	EXPECT_EQ(TimeExample7.GetMinutes(), 2);
	EXPECT_EQ(TimeExample7.GetSeconds(), 3);

	CTime TimeExample8(3, 6, 9.0);
	TimeExample8 = TimeExample8 + 7223.0;
	EXPECT_EQ(TimeExample8.GetHours(), 5);
	EXPECT_EQ(TimeExample8.GetMinutes(), 6);
	EXPECT_EQ(TimeExample8.GetSeconds(), 32);
}


TEST(OperatorsTest, MinusTest) {
	CTime TimeExample1(2, 2, 3.0), TimeExample2(1, 12, 58.0);
	double TimeInSec{ TimeExample1 - TimeExample2 };
	EXPECT_EQ(TimeInSec, 2945.0);

	CTime TimeExample3(5, 1, 3.0), TimeExample4(5, 1, 3.0);
	double TimeInSec1{ TimeExample3 - TimeExample4 };
	EXPECT_EQ(TimeInSec1, 0.0);

	CTime TimeExample5(5, 1, 3.0), TimeExample6(5, 2, 3.0);
	double TimeInSec2{ TimeExample5 - TimeExample6 };
	EXPECT_EQ(TimeInSec2, -60.0);
}


TEST(OperatorsTest, DoubleTest) {
	CTime TimeExample1(1, 2, 3.0);
	double TimeExampleInSec1{TimeExample1};
	EXPECT_DOUBLE_EQ(TimeExampleInSec1, 3723.0);

	CTime TimeExample2(3, 2, 1.0);
	double TimeExampleInSec2{ TimeExample2 };
	EXPECT_DOUBLE_EQ(TimeExampleInSec2, 10921.0);
}

TEST(OperatorsTest, MultiplyTestTest) {
	CTime TimeExample1(1, 2, 3.0);
	TimeExample1 = TimeExample1 * 2.0;
	EXPECT_EQ(TimeExample1.GetHours(), 2);
	EXPECT_EQ(TimeExample1.GetMinutes(), 4);
	EXPECT_DOUBLE_EQ(TimeExample1.GetSeconds(), 6.0);

	CTime TimeExample2(3, 6, 9.0);
	TimeExample2 = TimeExample2 * 3.0;
	EXPECT_EQ(TimeExample2.GetHours(), 9);
	EXPECT_EQ(TimeExample2.GetMinutes(), 18);
	EXPECT_DOUBLE_EQ(TimeExample2.GetSeconds(), 27.0);
}

TEST(OperatorsTest, EqualityOperator) {
	CTime TimeExample1(1, 2, 3.0), TimeExample2(1, 2, 3.0);
	EXPECT_TRUE(TimeExample1 == TimeExample2);

	CTime TimeExample3(2, 2, 3.0), TimeExample4(1, 2, 3.0);
	EXPECT_FALSE(TimeExample3 == TimeExample4);
}

TEST(OperatorsTest, GTOperatorTest) {
	CTime TimeExample1(1, 2, 4.0), TimeExample2(1, 2, 3.0);
	EXPECT_TRUE(TimeExample1 > TimeExample2);

	CTime TimeExample3(1, 2, 3.0), TimeExample4(1, 2, 3.0);
	EXPECT_FALSE(TimeExample3 > TimeExample4);
}

TEST(OperatorsTest, LTOperatorTest) {
	CTime TimeExample1(1, 2, 3.0), TimeExample2(1, 2, 4.0);
	EXPECT_TRUE(TimeExample1 < TimeExample2);

	CTime TimeExample3(1, 2, 3.0), TimeExample4(1, 2, 3.0);
	EXPECT_FALSE(TimeExample3 < TimeExample4);
}

TEST(StaticFieldTest, ChekingValue) {
	CTime TimeExample1(1, 2, 4.0), TimeExample2(1, 2, 3.0), TimeExample3, TimeExample(1928.0);
	EXPECT_EQ(TimeExample1.GetAmountOfObjects(), 4);
}