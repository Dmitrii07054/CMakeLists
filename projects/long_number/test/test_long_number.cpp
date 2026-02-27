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


TEST(LongNumberTest, Division) {
    std::cout << "\n=== STARTING DIVISION TESTS ===\n";
    
    std::cout << "Test 1: 12345 / 12" << std::endl;
    LongNumber a("12345");
    LongNumber b("12");
    LongNumber result = a / b;
    EXPECT_EQ(result, LongNumber("1028"));
    
    std::cout << "Test 2: 100 / 3" << std::endl;
    LongNumber c("100");
    LongNumber d("3");
    EXPECT_EQ(c / d, LongNumber("33"));
    
    std::cout << "Test 3: 999 / 999" << std::endl;
    LongNumber e("999");
    LongNumber f("999");
    EXPECT_EQ(e / f, LongNumber("1"));
    
    std::cout << "Test 4: 123456789 / 1" << std::endl;
    LongNumber g("123456789");
    LongNumber h("1");
    EXPECT_EQ(g / h, LongNumber("123456789"));
    
    std::cout << "Test 5: 500 / 500" << std::endl;
    LongNumber i("500");
    LongNumber j("500");
    EXPECT_EQ(i / j, LongNumber("1"));
    
    std::cout << "Test 6: 5 / 10" << std::endl;
    LongNumber k("5");
    LongNumber l("10");
    EXPECT_EQ(k / l, LongNumber("0"));
    
    std::cout << "Test 7: -100 / 5" << std::endl;
    LongNumber m("-100");
    LongNumber n("5");
    EXPECT_EQ(m / n, LongNumber("-20"));
    
    std::cout << "Test 8: 100 / -5" << std::endl;
    LongNumber o("100");
    LongNumber p("-5");
    EXPECT_EQ(o / p, LongNumber("-20"));
    
    std::cout << "Test 9: -100 / -5" << std::endl;
    LongNumber q("-100");
    LongNumber r("-5");
    EXPECT_EQ(q / r, LongNumber("20"));
    
    std::cout << "=== FINISHED DIVISION TESTS ===\n";
}

TEST(LongNumberTest, Modulo) {
    LongNumber a("12345");
    LongNumber b("12");
    LongNumber result = a % b;
    EXPECT_EQ(result, LongNumber("9"));
    
    LongNumber c("100");
    LongNumber d("3");
    EXPECT_EQ(c % d, LongNumber("1"));
    
    LongNumber e("999");
    LongNumber f("999");
    EXPECT_EQ(e % f, LongNumber("0"));
    
    LongNumber g("5");
    LongNumber h("10");
    EXPECT_EQ(g % h, LongNumber("5"));
    
    LongNumber i("123456789");
    LongNumber j("1");
    EXPECT_EQ(i % j, LongNumber("0"));
    
    LongNumber k("-100");
    LongNumber l("30");
    LongNumber result2 = k % l;
    EXPECT_EQ(result2, LongNumber("20"));
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}