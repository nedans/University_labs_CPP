#include "pch.h"
#include "../oop_lab9_prog/CEncryptor.h"
#include "../oop_lab9_prog/function.h"

static bool g_OperatorNewFails = false;

void* operator new[](size_t n) {
    if (g_OperatorNewFails) {
        throw std::bad_alloc();
    }
    return malloc(n);
}

void operator delete[](void* p) noexcept {
    free(p);
}


TEST(ExceptionsTest, TestShiftValue) {
    EXPECT_THROW(CEncryptor<0> obj("Some data"), CExceptionZeroShiftValue);
}

TEST(ExceptionsTest, TestDataValue) {
    EXPECT_THROW(CEncryptor<2> obj("123"), CExceptionNonSymbol);
    EXPECT_THROW(CEncryptor<2> obj("/$%"), CExceptionNonSymbol);
}

TEST(ExceptionsTest, TestLackOfMemory) {
    CEncryptor<2> obj("Some data");

    g_OperatorNewFails = true;

    EXPECT_THROW(obj.SetData("Abra kadabra"), std::exception);

    EXPECT_THROW(obj.SetData("Some data"), std::exception);

    g_OperatorNewFails = false;
}

TEST(ExceptionTest, TestInputOutput) {
    CEncryptor<2> obj("Some data");

    std::cin.setstate(std::ios_base::failbit);
    EXPECT_THROW(std::cin >> obj, CInputException);

    std::cout.setstate(std::ios_base::failbit);
    EXPECT_THROW(std::cout << obj, COutputException);
}

TEST(EncryptDecryptTest, MethodTest) {
    char text[]{ "Some text" };
    CEncryptor<1> object1(text), object2;
    object1.Encrypt();
    char othertext1[]{ "Tpnf ufyu" };

    EXPECT_STREQ(object1.GetData(), othertext1);

    object2 = object1;
    object2.Decrypt();

    EXPECT_STREQ(object2.GetData(), text);


    CEncryptor<10> object3(text), object4;

    object3.Encrypt();
    char othertext2[]{ "]ywo ~o\"~" };

    EXPECT_STREQ(object3.GetData(), othertext2);

    object4 = object3;
    object4.Decrypt();

    EXPECT_STREQ(object4.GetData(), text);


    CEncryptor<52> object5(text), object6;

    object5.Encrypt();
    char othertext3[]{ "'CA9 H9LH" };

    EXPECT_STREQ(object5.GetData(), othertext3);

    object6 = object5;
    object6.Decrypt();

    EXPECT_STREQ(object6.GetData(), text);
}

TEST(EncryptDecryptTest, PrefixIncrementDecrementTest) {
    char text[]{ "Some text" };
    CEncryptor<2> object1(text), object2;
    ++object1;
    char othertext[]{ "Uqog vgzv" };

    EXPECT_STREQ(object1.GetData(), othertext);

    object2 = object1;
    --object2;

    EXPECT_STREQ(object2.GetData(), text);
}

TEST(EncryptDecryptTest, PostfixIncrementDecrementTest) {
    char text[]{ "Some text" };
    CEncryptor<2> object1(text), object2, object5;
    object5 = object1++;
    char othertext[]{ "Uqog vgzv" };

    EXPECT_STREQ(object5.GetData(), text);
    EXPECT_STREQ(object1.GetData(), othertext);

    object2 = object1;
    --object2;

    EXPECT_STREQ(object2.GetData(), text);
}

TEST(OperatorsTest, EqualityOperatorTest) {
    char text[]{ "Some text" };
    CEncryptor<2> object1(text), object2(object1);


    EXPECT_TRUE(object1 == object2);
    object2.SetData("Other text");

    EXPECT_FALSE(object1 == object2);
}

TEST(OperatorsTest, AssignmentOperatorTest) {
    char text[]{ "Some text" };
    CEncryptor<2> object1(text), object2;

    object2 = object1;

    EXPECT_TRUE(object1 == object2);
}

TEST(FunctionTest, FindElementInArrayTest) {
    int array1[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

    EXPECT_EQ(FindElementInArray(array1, 2), 1);
    EXPECT_EQ(FindElementInArray(array1, 13), 10);

    double array2[5]{ 1.1, 2.34, 5.21, 5.43, 54.4 };

    EXPECT_EQ(FindElementInArray(array2, 5.21), 2);
    EXPECT_EQ(FindElementInArray(array2, 13.1), 5);



    CEncryptor<3> obj1("firstdata");
    CEncryptor<3> obj2("seconddata");
    CEncryptor<3> obj3("thirddata");
    CEncryptor<3> arr[3]{ obj1, obj2, obj3 };

    CEncryptor<3> obj4{ arr[0] };
    CEncryptor<3> obj5("fourthdata");
    EXPECT_EQ(FindElementInArray(arr, obj4), 0);
    EXPECT_EQ(FindElementInArray(arr, obj5), 3);
}