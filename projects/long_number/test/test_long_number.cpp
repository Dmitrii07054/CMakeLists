#include <gtest/gtest.h>
#include "long_number.hpp"

using namespace dim;

TEST(LongNumberTest, DefaultConstructor) {

    LongNumber num;
    
    std::stringstream ss;
    ss << num;

    EXPECT_EQ(ss.str(), "0");
}

TEST(LongNumberTest, StringConstructorPositive) {
    LongNumber num("12345");
    std::stringstream ss;
    ss << num;
    EXPECT_EQ(ss.str(), "12345");
}

TEST(LongNumberTest, StringConstructorNegative) {
    LongNumber num("-6789");
    std::stringstream ss;
    ss << num;
    EXPECT_EQ(ss.str(), "-6789");
}

TEST(LongNumberTest, StringConstructorZero) {
    LongNumber num("0");
    std::stringstream ss;
    ss << num;
    EXPECT_EQ(ss.str(), "0");
}

TEST(LongNumberTest, CopyConstructor) {
    LongNumber original("12345");
    LongNumber copy(original);
    
    std::stringstream ss1, ss2;
    ss1 << original;
    ss2 << copy;
    
    EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(LongNumberTest, EqualityOperator) {
    LongNumber num1("12345");
    LongNumber num2("12345");
    LongNumber num3("12346");
    
    EXPECT_TRUE(num1 == num2);
    EXPECT_FALSE(num1 == num3);
}

TEST(LongNumberTest, InequalityOperator) {
    LongNumber num1("12345");
    LongNumber num2("12345");
    LongNumber num3("12346");
    
    EXPECT_FALSE(num1 != num2);
    EXPECT_TRUE(num1 != num3);
}

TEST(LongNumberTest, GreaterOperator) {
    LongNumber num1("12345");
    LongNumber num2("1234");
    LongNumber num3("12346");
    LongNumber num4("-12345");
    
    EXPECT_TRUE(num1 > num2);
    EXPECT_FALSE(num1 > num3);
    EXPECT_TRUE(num1 > num4);
}

TEST(LongNumberTest, LessOperator) {
    LongNumber num1("12345");
    LongNumber num2("12346");
    LongNumber num3("-12345");
    
    EXPECT_TRUE(num1 < num2);
    EXPECT_FALSE(num2 < num1);
    EXPECT_TRUE(num3 < num1);
}

TEST(LongNumberTest, IsNegative) {
    LongNumber pos("12345");
    LongNumber neg("-12345");
    LongNumber zero("0");
    
    EXPECT_FALSE(pos.is_negative());
    EXPECT_TRUE(neg.is_negative());
    EXPECT_FALSE(zero.is_negative());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}



