#include "pch.h"
#include "../oop_lab6_prog/CÑhessman.h"

TEST(KnightTest, ValidInputTest) {
	CKnight knight(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_TRUE(knight.CanCapturePosition(POSITION_SYMBOL::c, POSITION_NUMBER::two, "result.txt"));

	knight.SetPosition(POSITION_SYMBOL::d, POSITION_NUMBER::five);
	EXPECT_TRUE(knight.CanCapturePosition(POSITION_SYMBOL::b, POSITION_NUMBER::four, "result.txt"));
	EXPECT_FALSE(knight.CanCapturePosition(POSITION_SYMBOL::b, POSITION_NUMBER::three, "result.txt"));
	EXPECT_FALSE(knight.CanCapturePosition(POSITION_SYMBOL::h, POSITION_NUMBER::seven, "result.txt"));
	EXPECT_FALSE(knight.CanCapturePosition(POSITION_SYMBOL::d, POSITION_NUMBER::five, "result.txt"));
}

TEST(RookTest, ValidInputTest) {
	CRook rook(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_TRUE(rook.CanCapturePosition(POSITION_SYMBOL::a, POSITION_NUMBER::two, "result.txt"));
	

	rook.SetPosition(POSITION_SYMBOL::d, POSITION_NUMBER::five);
	EXPECT_TRUE(rook.CanCapturePosition(POSITION_SYMBOL::b, POSITION_NUMBER::five, "result.txt"));
	EXPECT_FALSE(rook.CanCapturePosition(POSITION_SYMBOL::b, POSITION_NUMBER::three, "result.txt"));
	EXPECT_FALSE(rook.CanCapturePosition(POSITION_SYMBOL::h, POSITION_NUMBER::seven, "result.txt"));
	EXPECT_FALSE(rook.CanCapturePosition(POSITION_SYMBOL::d, POSITION_NUMBER::five, "result.txt"));
}

TEST(QueenTest, ValidInputTest) {
	CQueen queen(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_TRUE(queen.CanCapturePosition(POSITION_SYMBOL::c, POSITION_NUMBER::three, "result.txt"));

	queen.SetPosition(POSITION_SYMBOL::d, POSITION_NUMBER::five);
	EXPECT_TRUE(queen.CanCapturePosition(POSITION_SYMBOL::b, POSITION_NUMBER::five, "result.txt"));
	EXPECT_FALSE(queen.CanCapturePosition(POSITION_SYMBOL::b, POSITION_NUMBER::four, "result.txt"));
	EXPECT_FALSE(queen.CanCapturePosition(POSITION_SYMBOL::h, POSITION_NUMBER::seven, "result.txt"));
	EXPECT_FALSE(queen.CanCapturePosition(POSITION_SYMBOL::d, POSITION_NUMBER::five, "result.txt"));
}

TEST(TestPrintName, ValidWorkTest) {
	CQueen queen(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_EQ(queen.PrintName(), "CQueen");

	CRook rook(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_EQ(rook.PrintName(), "CRook");

	CKnight knight(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_EQ(knight.PrintName(), "CKnight");
}