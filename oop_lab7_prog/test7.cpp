#include "pch.h"
#include "../oop_lab7_prog/CÑhessman.h"
#include "../oop_lab7_prog/CKnight.h"
#include "../oop_lab7_prog/CRook.h"
#include "../oop_lab7_prog/CQueen.h"

//static bool g_OperatorNewFails = false;
//
//void* operator new (size_t n) {
//	if (g_OperatorNewFails)
//		throw std::bad_alloc();
//
//	return malloc(n);
//}

TEST(KnightTest, ValidInputTest) {

//	g_OperatorNewFails = true;
	CKnight knight(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_TRUE(knight.CanCapturePosition(17));
	EXPECT_TRUE(knight.CanCapturePosition(10));
	
//	g_OperatorNewFails = false;

	EXPECT_FALSE(knight.CanCapturePosition(18));
	EXPECT_FALSE(knight.CanCapturePosition(60));
}

TEST(RookTest, ValidInputTest) {
	CRook rook(COLOUR::Black, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_TRUE(rook.CanCapturePosition(16));
	EXPECT_TRUE(rook.CanCapturePosition(2));

	EXPECT_FALSE(rook.CanCapturePosition(55));
	EXPECT_FALSE(rook.CanCapturePosition(60));
}

TEST(QueenTest, ValidInputTest) {
	CQueen queen(COLOUR::Black, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_TRUE(queen.CanCapturePosition(16));
	EXPECT_TRUE(queen.CanCapturePosition(2));
	EXPECT_TRUE(queen.CanCapturePosition(9));

	EXPECT_FALSE(queen.CanCapturePosition(55));
	EXPECT_FALSE(queen.CanCapturePosition(60));
}

TEST(TestPrintName, ValidWorkTest) {
	CQueen queen(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_EQ(queen.PrintName(), "CQueen");

	CRook rook(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_EQ(rook.PrintName(), "CRook");

	CKnight knight(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	EXPECT_EQ(knight.PrintName(), "CKnight");
}

TEST(DynamicCastTest, ValidWorkTest) {

	CQueen queen(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	CRook rook(COLOUR::Black, POSITION_SYMBOL::c, POSITION_NUMBER::three);
	CKnight knight(COLOUR::White, POSITION_SYMBOL::f, POSITION_NUMBER::five);
	const int n{ 3 };
	CChessman* array[n] { & queen, & rook, & knight };
	
	CKnight* Kpointer = dynamic_cast<CKnight*>(array[2]);
	EXPECT_EQ(Kpointer->PrintName(), "CKnight");

	CRook* Rpointer = dynamic_cast<CRook*>(array[1]);
	EXPECT_EQ(Rpointer->PrintName(), "CRook");

	CQueen* Qpointer = dynamic_cast<CQueen*>(array[0]);
	EXPECT_EQ(Qpointer->PrintName(), "CQueen");
}

TEST(CanAnyoneCaptureTest, ArrayTest) {
	CQueen queen(COLOUR::White, POSITION_SYMBOL::a, POSITION_NUMBER::one);
	CRook rook(COLOUR::Black, POSITION_SYMBOL::c, POSITION_NUMBER::three);
	CKnight knight(COLOUR::White, POSITION_SYMBOL::f, POSITION_NUMBER::five);
	const size_t n{ 3 };
	const CChessman* array[n] = {&queen, &rook, &knight};
	EXPECT_TRUE(CanAnyoneCapturePosition(array, 1, n));
	EXPECT_TRUE(CanAnyoneCapturePosition(array, 10, n));
	EXPECT_TRUE(CanAnyoneCapturePosition(array, 56, n));
}