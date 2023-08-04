#include "pch.h"
#include "../oop_lab5_prog/CEncryptor.h"
#include "../oop_lab5_prog/SmartPointerCEncryptor.h"

TEST(EncryptDecryptTest, MethodTest) {
	char text[]{"Some text"};
	CEncryptor object1(text, 2), object2;
	object1.Encrypt();
	char othertext[]{"Uqog vgzv"};

	EXPECT_STREQ(object1.GetData(), othertext);
	
	object2 = object1;
	object2.Decrypt();
	
	EXPECT_STREQ(object2.GetData(), text);

	SmartPointerCEncryptor object3(text, 2), object4;
	object3.Encrypt();
	
	EXPECT_STREQ(object3.GetData(), othertext);
	
	object4 = object3;
	object4.Decrypt();
	
	EXPECT_STREQ(object4.GetData(), text);
}

TEST(EncryptDecryptTest, PrefixIncrementDecrementTest) {
	char text[]{ "Some text" };
	CEncryptor object1(text, 2), object2;
	++object1;
	char othertext[]{ "Uqog vgzv" };

	EXPECT_STREQ(object1.GetData(), othertext);

	object2 = object1;
	--object2;

	EXPECT_STREQ(object2.GetData(), text);

	SmartPointerCEncryptor object3(text, 2), object4;
	++object3;

	EXPECT_STREQ(object3.GetData(), othertext);

	object4 = object3;
	--object4;

	EXPECT_STREQ(object4.GetData(), text);
}

TEST(EncryptDecryptTest, PostfixIncrementDecrementTest) {
	char text[]{ "Some text" };
	CEncryptor object1(text, 2), object2, object5;
	object5 = object1++;
	char othertext[]{ "Uqog vgzv" };

	EXPECT_STREQ(object5.GetData(), text);
	EXPECT_STREQ(object1.GetData(), othertext);

	object2 = object1;
	--object2;

	EXPECT_STREQ(object2.GetData(), text);

	SmartPointerCEncryptor object3(text, 2), object4;
	++object3;

	EXPECT_STREQ(object3.GetData(), othertext);

	object4 = object3;
	--object4;

	EXPECT_STREQ(object4.GetData(), text);
}

TEST(OperatorsTest, EqualityOperatorTest) {
	char text[]{ "Some text" };
	CEncryptor object1(text, 2), object2(object1);


	EXPECT_TRUE(object1 == object2);

	SmartPointerCEncryptor object3(text, 2), object4(object3);

	EXPECT_TRUE(object3 == object4);
	++object2;
	++object4;

	EXPECT_FALSE(object1 == object2);
	EXPECT_FALSE(object3 == object4);
}

TEST(OperatorsTest, AssignmentOperatorTest) {
	char text[]{ "Some text" };
	CEncryptor object1(text, 2), object2;
	
	object2 = object1;

	EXPECT_TRUE(object1 == object2);

	SmartPointerCEncryptor object3(text, 2), object4;

	object4 = object3;

	EXPECT_TRUE(object3 == object4);
}