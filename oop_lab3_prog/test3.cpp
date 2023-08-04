#include "pch.h"

#include "../oop_lab3_prog/lab3.h"


TEST(ConvertTimeToSeconds, ExtremeValues) {
	CTime TimeExample1(-1, 4, 13);
	EXPECT_EQ(TimeExample1.ConvertTimeToSeconds(), -1);

	CTime TimeExample2(1, -4, 13);
	EXPECT_EQ(TimeExample2.ConvertTimeToSeconds(), -1);

	CTime TimeExample3(1, -4, -13);
	EXPECT_EQ(TimeExample3.ConvertTimeToSeconds(), -1);

	CTime TimeExample4(1, 4, NAN);
	EXPECT_TRUE(std::isnan(TimeExample4.ConvertTimeToSeconds()));

	CTime TimeExample5(1, 4, INFINITY);
	EXPECT_TRUE(std::isinf(TimeExample5.ConvertTimeToSeconds()));
}

TEST(ConvertTimeToSeconds, ValidInput) {
	CTime TimeExample1(1, 4, 19);
	EXPECT_DOUBLE_EQ(TimeExample1.ConvertTimeToSeconds(), 3859.0);

	CTime TimeExample2(2, 10, 3);
	EXPECT_DOUBLE_EQ(TimeExample2.ConvertTimeToSeconds(), 7803.0);

	CTime TimeExample3(0, 2, 10);
	EXPECT_DOUBLE_EQ(TimeExample3.ConvertTimeToSeconds(), 130.0);
}


TEST(MultiplyTheTimeBy, ExtremeValues) {
	CTime TimeExample(0, 0, 0);
	EXPECT_TRUE(std::isinf(TimeExample.MultiplyTheTimeBy(INFINITY)));
	EXPECT_TRUE(std::isnan(TimeExample.MultiplyTheTimeBy(NAN)));
}

TEST(MultiplyTheTimeBy, ValidInput) {

	CTime TimeExample(0, 0, 0);
	TimeExample.MultiplyTheTimeBy(2);
	EXPECT_EQ(TimeExample.GetHours(), 0);
	EXPECT_EQ(TimeExample.GetMinutes(), 0);
	EXPECT_DOUBLE_EQ(TimeExample.GetSeconds(), 0);

	CTime TimeExample1(1, 32, 56.0);
	TimeExample1.MultiplyTheTimeBy(2);

	EXPECT_EQ(TimeExample1.GetHours(), 3);
	EXPECT_EQ(TimeExample1.GetMinutes(), 5);
	EXPECT_DOUBLE_EQ(TimeExample1.GetSeconds(), 52.0);

	CTime TimeExample2(1, 10, 21.0);
	TimeExample2.MultiplyTheTimeBy(3);

	EXPECT_EQ(TimeExample2.GetHours(), 3);
	EXPECT_EQ(TimeExample2.GetMinutes(), 31);
	EXPECT_DOUBLE_EQ(TimeExample2.GetSeconds(), 3.0);

	CTime TimeExample3(2, 10, 10.0);
	TimeExample3.MultiplyTheTimeBy(1.5);

	EXPECT_EQ(TimeExample3.GetHours(), 3);
	EXPECT_EQ(TimeExample3.GetMinutes(), 15);
	EXPECT_DOUBLE_EQ(TimeExample3.GetSeconds(), 15.0);
}


TEST(AddSecToTime, ExtremeValues) {

	CTime TimeExample(0, 0, 0);
	EXPECT_EQ(TimeExample.AddSecToTime(-10), -1);
	EXPECT_TRUE(std::isnan(TimeExample.AddSecToTime(NAN)));
	EXPECT_TRUE(std::isinf(TimeExample.AddSecToTime(INFINITY)));
}

TEST(AddSecToTime, ValidInput) {
	CTime TimeExample1(1, 23, 34);
	TimeExample1.AddSecToTime(300);	
	
	EXPECT_EQ(TimeExample1.GetHours(), 1);
	EXPECT_EQ(TimeExample1.GetMinutes(), 28);
	EXPECT_DOUBLE_EQ(TimeExample1.GetSeconds(), 34);

	CTime TimeExample2(2, 10, 5);
	TimeExample2.AddSecToTime(5587);

	EXPECT_EQ(TimeExample2.GetHours(), 3);
	EXPECT_EQ(TimeExample2.GetMinutes(), 43);
	EXPECT_DOUBLE_EQ(TimeExample2.GetSeconds(), 12);

	CTime TimeExample3(1, 25, 30);
	TimeExample3.AddSecToTime(9403);

	EXPECT_EQ(TimeExample3.GetHours(), 4);
	EXPECT_EQ(TimeExample3.GetMinutes(), 2);
	EXPECT_DOUBLE_EQ(TimeExample3.GetSeconds(), 13);
}


TEST(SubtractionDifferenceInSeconds, ExtremeValues) {
	CTime TimeExample1(1, 2, NAN), TimeExample2(1, 2, 3);
	EXPECT_TRUE(std::isnan(TimeExample1.SubtractionDifferenceInSeconds(TimeExample2)));

	CTime TimeExample3(1, 3, 3), TimeExample4(1, 2, NAN);
	EXPECT_TRUE(std::isnan(TimeExample3.SubtractionDifferenceInSeconds(TimeExample4)));

	CTime TimeExample5(1, 2, 2), TimeExample6(1, 2, INFINITY);
	EXPECT_TRUE(std::isinf(TimeExample5.SubtractionDifferenceInSeconds(TimeExample6)));

	CTime TimeExample7(1, 2, INFINITY), TimeExample8(1, 2, 2);
	EXPECT_TRUE(std::isinf(TimeExample7.SubtractionDifferenceInSeconds(TimeExample8)));
}

TEST(SubtractionDifferenceInSeconds, ValidInput) {
	CTime TimeExample1(1, 2, 3), TimeExample2(1, 2, 3);
	EXPECT_DOUBLE_EQ(TimeExample1.SubtractionDifferenceInSeconds(TimeExample2), 0.0);

	CTime TimeExample3(1, 3, 3), TimeExample4(1, 2, 3);
	EXPECT_DOUBLE_EQ(TimeExample3.SubtractionDifferenceInSeconds(TimeExample4), 60.0);

	CTime TimeExample5(1, 2, 2), TimeExample6(1, 2, 3);
	EXPECT_DOUBLE_EQ(TimeExample5.SubtractionDifferenceInSeconds(TimeExample6), -1.0);
}

TEST(Compare, ValidInput) {
	CTime TimeExample1(1, 3, 3), TimeExample2(1, 2, 3);
	EXPECT_EQ(TimeExample1.Ñompare(TimeExample2), 1);

	CTime TimeExample3(1, 2, 3), TimeExample4(1, 3, 2);
	EXPECT_EQ(TimeExample3.Ñompare(TimeExample4), -1);

	CTime TimeExample5(1, 2, 10), TimeExample6(1, 3, 3);
	EXPECT_EQ(TimeExample5.Ñompare(TimeExample6), -1);

	CTime TimeExample7(1, 2, 3), TimeExample8(1, 2, 3);
	EXPECT_EQ(TimeExample7.Ñompare(TimeExample8), 0);
}


TEST(Add, ValidInput) {
	CTime TimeExample1(1, 2, 3), TimeExample2(1, 2, 3);
	TimeExample1 = TimeExample1.Add(TimeExample2);
	EXPECT_EQ(TimeExample1.GetHours(), 2);
	EXPECT_EQ(TimeExample1.GetMinutes(), 4);
	EXPECT_DOUBLE_EQ(TimeExample1.GetSeconds(), 6);

	CTime TimeExample3(2, 34, 43), TimeExample4(1, 30, 26);
	TimeExample3 = TimeExample3.Add(TimeExample4);
	EXPECT_EQ(TimeExample3.GetHours(), 4);
	EXPECT_EQ(TimeExample3.GetMinutes(), 5);
	EXPECT_DOUBLE_EQ(TimeExample3.GetSeconds(), 9);
}