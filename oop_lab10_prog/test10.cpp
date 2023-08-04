#include "pch.h"
#include "../oop_lab10_prog/CEncryptor.h"
#include "../oop_lab10_prog/CExceptions.h"
#include "../oop_lab10_prog/function.h"
#include <map>
#include <unordered_set>
#include <queue>



TEST(ExceptionsTest, TestShiftValue) {
    EXPECT_THROW((CEncryptor<0, 1>("Some data")), CExceptionZeroShiftValue);
}

TEST(ExceptionsTest, TestDataValue) {
    EXPECT_THROW((CEncryptor<2, 1>("123")), CExceptionNonSymbol);
    EXPECT_THROW((CEncryptor<2, 1>("/$%")), CExceptionNonSymbol);
}

TEST(ExceptionTest, TestInputOutput) {
    CEncryptor<2, 1> obj("Some data");

    std::cin.setstate(std::ios_base::failbit);
    EXPECT_THROW(std::cin >> obj, CInputException);

    std::cout.setstate(std::ios_base::failbit);
    EXPECT_THROW(std::cout << obj, COutputException);
}

TEST(EncryptDecryptTest, MethodTest) {
    std::string text{ "Some text" };
    CEncryptor<1, 1> object1(text), object2;
    object1.Encrypt();
    std::string othertext1{ "Tpnf ufyu" };

    EXPECT_EQ(object1.GetData(), othertext1);

    object2 = object1;
    object2.Decrypt();

    EXPECT_EQ(object2.GetData(), text);


    CEncryptor<10, 1> object3(text), object4;

    object3.Encrypt();
    char othertext2[]{ "]ywo ~o\"~" };

    EXPECT_EQ(object3.GetData(), othertext2);

    object4 = object3;
    object4.Decrypt();

    EXPECT_EQ(object4.GetData(), text);


    CEncryptor<52, 1> object5(text), object6;

    object5.Encrypt();
    std::string othertext3{ "'CA9 H9LH" };

    EXPECT_EQ(object5.GetData(), othertext3);

    object6 = object5;
    object6.Decrypt();

    EXPECT_EQ(object6.GetData(), text);
}

TEST(EncryptDecryptTest, PrefixIncrementDecrementTest) {
    std::string text{ "Some text" };
    CEncryptor<2, 1> object1(text), object2;
    ++object1;
    std::string othertext{ "Uqog vgzv" };

    EXPECT_EQ(object1.GetData(), othertext);

    object2 = object1;
    --object2;

    EXPECT_EQ(object2.GetData(), text);
}

TEST(EncryptDecryptTest, PostfixIncrementDecrementTest) {
    std::string text{ "Some text" };
    CEncryptor<2, 1> object1(text), object2, object5;
    object5 = object1++;
    std::string othertext{ "Uqog vgzv" };

    EXPECT_EQ(object5.GetData(), text);
    EXPECT_EQ(object1.GetData(), othertext);

    object2 = object1;
    --object2;

    EXPECT_EQ(object2.GetData(), text);
}

TEST(OperatorsTest, EqualityOperatorTest) {
    char text[]{ "Some text" };
    CEncryptor<2, 1> object1(text), object2(object1);


    EXPECT_TRUE(object1 == object2);
    object2.SetData("Other text");

    EXPECT_FALSE(object1 == object2);
}

TEST(OperatorsTest, AssignmentOperatorTest) {
    std::string text{ "Some text" };
    CEncryptor<2, 1> object1(text), object2;

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



    CEncryptor<3, 1> obj1("firstdata");
    CEncryptor<3, 1> obj2("seconddata");
    CEncryptor<3, 1> obj3("thirddata");
    CEncryptor<3, 1> arr[3]{ obj1, obj2, obj3 };

    CEncryptor<3, 1> obj4{ arr[0] };
    CEncryptor<3, 1> obj5("fourthdata");
    EXPECT_EQ(FindElementInArray(arr, obj4), 0);
    EXPECT_EQ(FindElementInArray(arr, obj5), 3);
}

TEST(STLContainer, MapTest) {

    std::map<int, CEncryptor<1, 1>> Map;
    CEncryptor<1, 1> obj1("info"), obj2("secinfo"), obj3("thinfo"), obj4("fouinfo"), obj5("data");
    Map.emplace(1, obj1);
    Map.emplace(2, obj2);
    Map.emplace(3, obj3);
    Map.emplace(4, obj4);

    EXPECT_FALSE(Map.emplace(1, obj5).second);

    EXPECT_EQ(Map.find(1123123), Map.end());

    EXPECT_EQ(Map.find(1)->first, 1);
    EXPECT_EQ((*Map.find(1)).second, obj1);

    EXPECT_TRUE(Map.erase(1));
    EXPECT_FALSE(Map.erase(1000));
}

TEST(STLContainer, UnoderedSetTest) {
    //CEncryptor<1, 1> obj1("info"), obj2("secinfo"), obj3("thinfo"), obj4("fouinfo"), obj5("data"), obj6("Sdata"), obj7("Sev data");
    //std::unordered_multiset<CEncryptor<1, 1>> MySet = { obj1,obj2,obj3,obj4 };
    //EXPECT_EQ(MySet.emplace(obj5)._Ptr->_Myval, obj5);
    //EXPECT_EQ(MySet.emplace(obj1)._Ptr->_Myval, obj1);
    //EXPECT_EQ(MySet.find(obj6), MySet.end());
    //EXPECT_EQ(MySet.find(obj1)._Ptr->_Myval, obj1);
    //EXPECT_TRUE(MySet.erase(obj1));
    //EXPECT_FALSE(MySet.erase(obj7));

    
    std::unordered_multiset<int> UMSet = { 1,2,3,4 };
    EXPECT_EQ(*UMSet.emplace(5), 5);
    EXPECT_EQ(*UMSet.emplace(1), 1);
    EXPECT_EQ(UMSet.find(100), UMSet.end());

    auto it = UMSet.find(1);
    ASSERT_NE(it, UMSet.end());
    EXPECT_EQ(*it, 1);

    EXPECT_TRUE(UMSet.erase(1));
    EXPECT_FALSE(UMSet.erase(7));
}

TEST(STLContainer, QueueTest) {
    std::queue<CEncryptor<1, 1>> Queue;
    CEncryptor<1, 1> obj1("first inf"), obj2("second inf"), obj3("third inf"), obj4("fourth inf"), obj5("fifth inf");
    Queue.emplace(obj1);
    Queue.emplace(obj2);
    Queue.emplace(obj3);
    Queue.emplace(obj4);
    Queue.emplace(obj5);
    EXPECT_EQ(Queue.back(), obj5);
    EXPECT_EQ(Queue.front(), obj1);
    EXPECT_FALSE(Queue.empty());
    Queue.pop();
    EXPECT_EQ(Queue.front(), obj2);
}

TEST(FunctionTest, ShiftElementsRight) {
    CEncryptor<1, 1> obj1("first inf");
    CEncryptor<1, 2>obj2("second inf");

    obj1.ShiftElementsRight();
    obj2.ShiftElementsRight();
    EXPECT_EQ(obj1.GetData(), "ffirst in");
    EXPECT_EQ(obj2.GetData(), "nfsecond i");
}