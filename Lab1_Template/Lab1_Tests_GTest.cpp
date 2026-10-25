#include <gtest/gtest.h>
#include "Solution.h" // Replace with the header that declares this lab’s implementation
#include <iostream>
// ---------------------------------------------------------------------------
// Q1tests: maxOfThree
// ---------------------------------------------------------------------------

TEST(MaxOfThreeTest, WorksForIntegers) {
    EXPECT_EQ(maxOfThree(3, 7, 5), 7);
    EXPECT_EQ(maxOfThree(-1, -5, -3), -1);
}

TEST(MaxOfThreeTest, WorksForDoubles) {
    EXPECT_DOUBLE_EQ(maxOfThree(2.5, 9.9, 4.4), 9.9);
}

TEST(MaxOfThreeTest, WorksForChars) {
    EXPECT_EQ(maxOfThree('a', 'z', 'm'), 'z');
}

TEST(MaxOfThreeTest, AllValuesEqual) {
    EXPECT_EQ(maxOfThree(4, 4, 4), 4);
}



// ---------------------------------------------------------------------------
// Q2 
// ---------------------------------------------------------------------------

TEST(PowerTest, IntegerBaseAndExponent) {
    EXPECT_EQ(power(2, 10), 1024);
    EXPECT_EQ(power(5, 3), 125);
}

TEST(PowerTest, ExponentZeroReturnsOne) {
    EXPECT_EQ(power(9, 0), 1);
}

TEST(PowerTest, ExponentOneReturnsBase) {
    EXPECT_EQ(power(7, 1), 7);
}

TEST(PowerTest, WorksForDoubleBase) {
    EXPECT_DOUBLE_EQ(power(2.5, 2), 6.25);
}



// ---------------------------------------------------------------------------
// Q3 
// ---------------------------------------------------------------------------

TEST(RectangleTest, AreaIsCorrect) {
    Rectangle<int> r(4, 5);
    EXPECT_EQ(r.area(), 20);
}

TEST(RectangleTest, PerimeterIsCorrect) {
    Rectangle<int> r(4, 5);
    EXPECT_EQ(r.perimeter(), 18);
}

TEST(RectangleTest, ScaleMultipliesBothDimensions) {
    Rectangle<double> r(2.0, 3.0);
    r.scale(2.0);
    EXPECT_DOUBLE_EQ(r.getWidth(), 4.0);
    EXPECT_DOUBLE_EQ(r.getHeight(), 6.0);
    EXPECT_DOUBLE_EQ(r.area(), 24.0);
}

TEST(RectangleTest, IsSquareTrueWhenEqualSides) {
    Rectangle<int> r(5, 5);
    EXPECT_TRUE(r.isSquare());
}

TEST(RectangleTest, IsSquareFalseWhenDifferentSides) {
    Rectangle<int> r(5, 6);
    EXPECT_FALSE(r.isSquare());
}

// ---------------------------------------------------------------------------
// Q4 
// ---------------------------------------------------------------------------

TEST(BankAccountTTest, DepositIncreasesBalanceInt) {
    BankAccountT<int> acc(100);
    acc.deposit(50);
    EXPECT_EQ(acc.getBalance(), 150);
}

TEST(BankAccountTTest, WithdrawSucceedsWithSufficientFunds) {
    BankAccountT<double> acc(200.0);
    bool ok = acc.withdraw(50.0);
    EXPECT_TRUE(ok);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 150.0);
}

TEST(BankAccountTTest, WithdrawFailsWithInsufficientFundsAndBalanceUnchanged) {
    BankAccountT<double> acc(30.0);
    bool ok = acc.withdraw(50.0);
    EXPECT_FALSE(ok);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 30.0);
}

TEST(BankAccountTTest, WorksWithIntegerBalance) {
    BankAccountT<int> acc(10);
    EXPECT_FALSE(acc.withdraw(20));
    EXPECT_EQ(acc.getBalance(), 10);
}



// Standalone GoogleTest entry point.
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
