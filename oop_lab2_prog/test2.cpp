#include "pch.h"

#include "../oop_lab2_prog/lab2.h"

TEST(GetNeededCapacity, ExtremeValues) {

	EXPECT_TRUE(std::isnan(GetNeededCapacity(1.0, 1.0, 1.0)));

	EXPECT_TRUE(std::isnan(GetNeededCapacity(1.0, 1.0, 0)));

	EXPECT_TRUE(std::isnan(GetNeededCapacity(2.0, -0.5, 1.0)));

	EXPECT_TRUE(std::isnan(GetNeededCapacity(-3.0, 1.0, 1.0)));

	EXPECT_TRUE(std::isnan(GetNeededCapacity(NAN, 2.0, 0.6)));

	EXPECT_TRUE(std::isnan(GetNeededCapacity(9.0, NAN, 0.2)));

	EXPECT_TRUE(std::isnan(GetNeededCapacity(3.0, 1.0, NAN)));

	EXPECT_TRUE(std::isnan(GetNeededCapacity(NAN, NAN, 0.3)));
	
	EXPECT_TRUE(std::isnan(GetNeededCapacity(3.0, 5.0, DBL_MAX)));

	EXPECT_TRUE(std::isinf(GetNeededCapacity(DBL_MAX, 1.0, 0.3)));

	EXPECT_TRUE(std::isinf(GetNeededCapacity(DBL_MAX, DBL_MAX, 0.1)));

	EXPECT_TRUE(std::isinf(GetNeededCapacity(INFINITY, DBL_MAX, 0.5)));

	EXPECT_TRUE(std::isinf(GetNeededCapacity(10.0, INFINITY, 0.3)));

	EXPECT_TRUE(std::isinf(GetNeededCapacity(INFINITY, INFINITY, 0.9)));
}

TEST(GetNeededCapacity, TestValidInput) {

	EXPECT_NEAR(GetNeededCapacity(30.0, 0.5, 0.5), 30.0, 0.001);

	EXPECT_NEAR(GetNeededCapacity(26.5, 3.0, 0.7), 113.571, 0.001);

	EXPECT_NEAR(GetNeededCapacity(11.2, 5.0, 0.3), 186.666, 0.001);

	EXPECT_NEAR(GetNeededCapacity(5.0, 12.3, 0.9), 68.3333, 0.001);

	EXPECT_NEAR(GetNeededCapacity(46.5, 7.0, 0.1), 3255.0, 0.001);

	EXPECT_NEAR(GetNeededCapacity(33.1, 9.0, 0.8), 372.375, 0.001);
}

/*
Must be in .exe files 

#include <gtest/gtest.h>

int main(int arge, char* argv[])
{
	
	     |--------------------------------------< namespace
	::testing::InitGoogleTest(&arge, argv)

	return RUN_ALL_TEST();
}
*/