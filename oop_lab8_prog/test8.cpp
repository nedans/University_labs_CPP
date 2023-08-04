#include "pch.h"
#include "../oop_lab8_prog/CEncryptor.h"
#include "../oop_lab8_prog/CExceptions.h"

static bool g_OperatorNewFails = false;

void* operator new[] (size_t n) {
	if (g_OperatorNewFails){ 
        throw std::bad_alloc();
    }
	return malloc(n);
}

void operator delete[](void* p) noexcept {
    free(p);
}


TEST(ExceptionsTest, TestShiftValue) {
    CEncryptor obj;

    EXPECT_THROW(obj.SetShiftValue(0), CExceptionZeroShiftValue);
}

TEST(ExceptionsTest, TestDataValue) {
    CEncryptor obj;

    EXPECT_THROW(obj.SetData("123"), CExceptionNonSymbol);
    EXPECT_THROW(obj.SetData("/$%"), CExceptionNonSymbol);
}

TEST(ExceptionsTest, TestLackOfMemory) {
    CEncryptor obj;

    g_OperatorNewFails = true;

    EXPECT_THROW(obj.SetData("Abra kadabra"), std::exception);

    g_OperatorNewFails = false;

    EXPECT_NO_THROW(obj.SetShiftValue(1));

    g_OperatorNewFails = true;

    EXPECT_THROW( obj.SetData("Some data"), std::exception);

    g_OperatorNewFails = false;
}

TEST(ExceptionTest, TestInputOutput) {
    CEncryptor obj("Some data", 2);

    std::cin.setstate(std::ios_base::failbit);
    EXPECT_THROW(std::cin >> obj, CInputException);
    
    std::cout.setstate(std::ios_base::failbit);
    EXPECT_THROW(std::cout << obj, COutputException);
}

