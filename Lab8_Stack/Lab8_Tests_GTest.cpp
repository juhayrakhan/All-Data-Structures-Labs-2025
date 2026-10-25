#include <gtest/gtest.h>
#include "Solution.h" // Replace with the header that declares this lab’s implementation
#include <string>
//=======================================================
// TASK 1: Stack Class (Template)
//=======================================================

TEST(StackTest, DefaultEmptyState) {
    Stack<int> s;

    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, PushMakesStackNotEmpty) {
    Stack<int> s;
    s.push(7);

    EXPECT_FALSE(s.isEmpty());
}

TEST(StackTest, PeekReturnsLastPushedElement) {
    Stack<int> s;

    s.push(42);
    EXPECT_EQ(s.peek(), 42);
    s.push(43);
    EXPECT_EQ(s.peek(), 43);
    s.push(44);
    EXPECT_EQ(s.peek(), 44);
}

TEST(StackTest, PeekDoesNotRemoveElement) {
    Stack<int> s;
    s.push(10);
    s.push(20);

    EXPECT_EQ(s.peek(), 20);
    EXPECT_EQ(s.peek(), 20);   // still there
    s.pop();
    EXPECT_EQ(s.peek(), 10);
}

TEST(StackTest, PopRemovesOnlyTheTopElement) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();                   // -> [1, 2]
    EXPECT_EQ(s.peek(), 2);
    s.pop();                   // -> [1]
    EXPECT_EQ(s.peek(), 1);
    EXPECT_FALSE(s.isEmpty());
}

TEST(StackTest, ElementsComeOutInReverseOrder) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    EXPECT_EQ(s.peek(), 5);
    s.pop();
    EXPECT_EQ(s.peek(), 4);
    s.pop();
    EXPECT_EQ(s.peek(), 3);
    s.pop();
    EXPECT_EQ(s.peek(), 2);
    s.pop();
    EXPECT_EQ(s.peek(), 1);
    s.pop();
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, BecomesEmptyAfterPoppingEverything) {
    Stack<int> s;
    s.push(42);
    s.push(43);
    s.push(44);

    s.pop();
    EXPECT_FALSE(s.isEmpty());
    s.pop();
    EXPECT_FALSE(s.isEmpty());
    s.pop();
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, DuplicateValuesAreAllStored) {
    Stack<int> s;
    s.push(5);
    s.push(5);
    s.push(5);

    s.pop();
    s.pop();
    EXPECT_FALSE(s.isEmpty());
    EXPECT_EQ(s.peek(), 5);
    s.pop();
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, MixedPushAndPop) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.pop();                   // [1]
    s.push(3);                 // [1, 3]
    s.push(4);                 // [1, 3, 4]

    EXPECT_EQ(s.peek(), 4);
    s.pop();
    EXPECT_EQ(s.peek(), 3);
    s.pop();
    EXPECT_EQ(s.peek(), 1);
}

TEST(StackTest, NegativeAndZeroValues) {
    Stack<int> s;
    s.push(0);
    s.push(-5);

    EXPECT_EQ(s.peek(), -5);
    s.pop();
    EXPECT_EQ(s.peek(), 0);
}

//---------------------------------------------------
// clear()
//---------------------------------------------------

TEST(StackTest, ClearRemovesAllElements) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.clear();

    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, ClearOnEmptyStackIsSafe) {
    Stack<int> s;

    EXPECT_NO_THROW(s.clear());
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, StackCanBeUsedAgainAfterClear) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.clear();

    s.push(99);

    EXPECT_FALSE(s.isEmpty());
    EXPECT_EQ(s.peek(), 99);
    s.pop();
    EXPECT_TRUE(s.isEmpty());
}

//---------------------------------------------------
// runtime_error on an empty stack
//---------------------------------------------------

TEST(StackTest, PopOnEmptyStackThrows) {
    Stack<int> s;

    EXPECT_THROW(s.pop(), std::runtime_error);
}

TEST(StackTest, PeekOnEmptyStackThrows) {
    Stack<int> s;

    EXPECT_THROW(s.peek(), std::runtime_error);
}

TEST(StackTest, ThrowsAgainAfterEmptiedByPop) {
    Stack<int> s;
    s.push(1);
    s.pop();

    EXPECT_THROW(s.pop(), std::runtime_error);
    EXPECT_THROW(s.peek(), std::runtime_error);
}

TEST(StackTest, ThrowsAfterClear) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.clear();

    EXPECT_THROW(s.pop(), std::runtime_error);
    EXPECT_THROW(s.peek(), std::runtime_error);
}

//---------------------------------------------------
// Template: other data types
//---------------------------------------------------

TEST(StackTest, WorksWithChar) {
    Stack<char> s;
    s.push('a');
    s.push('b');

    EXPECT_EQ(s.peek(), 'b');
    s.pop();
    EXPECT_EQ(s.peek(), 'a');
}

TEST(StackTest, WorksWithDouble) {
    Stack<double> s;
    s.push(1.5);
    s.push(2.25);

    EXPECT_DOUBLE_EQ(s.peek(), 2.25);
    s.pop();
    EXPECT_DOUBLE_EQ(s.peek(), 1.5);
}

TEST(StackTest, WorksWithString) {
    Stack<std::string> s;
    s.push("first");
    s.push("second");
    s.push("third");

    EXPECT_EQ(s.peek(), "third");
    s.pop();
    EXPECT_EQ(s.peek(), "second");
    s.pop();
    EXPECT_EQ(s.peek(), "first");
}

TEST(StackTest, TwoStacksAreIndependent) {
    Stack<int> a;
    Stack<int> b;
    a.push(1);
    a.push(2);
    b.push(100);

    EXPECT_EQ(a.peek(), 2);
    EXPECT_EQ(b.peek(), 100);

    a.pop();
    EXPECT_EQ(a.peek(), 1);
    EXPECT_EQ(b.peek(), 100);

    b.clear();
    EXPECT_TRUE(b.isEmpty());
    EXPECT_FALSE(a.isEmpty());
}

//---------------------------------------------------
// print()
//---------------------------------------------------

TEST(StackTest, PrintDoesNotChangeTheStack) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.print();                 // should show: 3 2 1

    EXPECT_EQ(s.peek(), 3);
    s.pop();
    EXPECT_EQ(s.peek(), 2);
}

TEST(StackTest, PrintShowsTopToBottomOnOneLine) {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    testing::internal::CaptureStdout();
    s.print();                 // expected: 30 20 10
    std::string out = testing::internal::GetCapturedStdout();

    size_t p30 = out.find("30");
    size_t p20 = out.find("20");
    size_t p10 = out.find("10");
    int lines = 0;
    for (size_t i = 0; i < out.length(); i++)
        if (out[i] == '\n') lines++;

    EXPECT_NE(p30, std::string::npos);
    EXPECT_NE(p20, std::string::npos);
    EXPECT_NE(p10, std::string::npos);
    EXPECT_LT(p30, p20);
    EXPECT_LT(p20, p10);
    EXPECT_LE(lines, 1);
}

TEST(StackTest, ManyElements) {
    Stack<int> s;
    for (int i = 0; i < 10000; i++) s.push(i);

    for (int i = 9999; i >= 0; i--) {
        EXPECT_EQ(s.peek(), i);
        s.pop();
    }
    EXPECT_TRUE(s.isEmpty());
}

//=======================================================
// TASK 3: 0/1 Knapsack (Backtracking with a Stack)
//=======================================================

TEST(KnapsackTest, ExampleFromTaskSheet) {
    int weights[] = { 10, 20, 30 };
    int values[] = { 60, 100, 120 };

    EXPECT_EQ(knapsackBacktracking(weights, values, 3, 50), 220);
}

TEST(KnapsackTest, SecondExample) {
    int weights[] = { 5, 4, 6, 3 };
    int values[] = { 10, 40, 30, 50 };

    EXPECT_EQ(knapsackBacktracking(weights, values, 4, 10), 90);
}

TEST(KnapsackTest, SingleItemFits) {
    int weights[] = { 5 };
    int values[] = { 10 };

    EXPECT_EQ(knapsackBacktracking(weights, values, 1, 5), 10);
    EXPECT_EQ(knapsackBacktracking(weights, values, 1, 100), 10);
}

TEST(KnapsackTest, SingleItemIsTooHeavy) {
    int weights[] = { 6 };
    int values[] = { 10 };

    EXPECT_EQ(knapsackBacktracking(weights, values, 1, 5), 0);
}

TEST(KnapsackTest, NoItemFits) {
    int weights[] = { 20, 30, 40 };
    int values[] = { 5, 6, 7 };

    EXPECT_EQ(knapsackBacktracking(weights, values, 3, 10), 0);
}

TEST(KnapsackTest, EveryItemFits) {
    int weights[] = { 1, 2, 3 };
    int values[] = { 10, 20, 30 };

    EXPECT_EQ(knapsackBacktracking(weights, values, 3, 100), 60);
}

TEST(KnapsackTest, ExactCapacityIsAllowed) {
    int weights1[] = { 50 };
    int values1[] = { 500 };
    int weights2[] = { 3, 4 };
    int values2[] = { 5, 6 };

    EXPECT_EQ(knapsackBacktracking(weights1, values1, 1, 50), 500);
    EXPECT_EQ(knapsackBacktracking(weights2, values2, 2, 7), 11);
}

TEST(KnapsackTest, EachItemCanBeUsedOnlyOnce) {
    int weights[] = { 5, 5 };
    int values[] = { 10, 10 };

    EXPECT_EQ(knapsackBacktracking(weights, values, 2, 10), 20);
    EXPECT_EQ(knapsackBacktracking(weights, values, 2, 9), 10);
}

TEST(KnapsackTest, GreedyByValueIsWrong) {
    // taking the most valuable item (value 10, weight 10) gives only 10
    int weights[] = { 10, 5, 5 };
    int values[] = { 10, 7, 7 };

    EXPECT_EQ(knapsackBacktracking(weights, values, 3, 10), 14);
}

TEST(KnapsackTest, GreedyByRatioIsWrong) {
    int weights[] = { 1, 3, 4, 5 };
    int values[] = { 1, 4, 5, 7 };

    EXPECT_EQ(knapsackBacktracking(weights, values, 4, 7), 9);
}

TEST(KnapsackTest, SameWeightDifferentValues) {
    int weights[] = { 2, 2, 2 };
    int values[] = { 3, 4, 5 };

    EXPECT_EQ(knapsackBacktracking(weights, values, 3, 4), 9);
}

TEST(KnapsackTest, CapacityOne) {
    int weights[] = { 1, 2 };
    int values[] = { 5, 6 };

    EXPECT_EQ(knapsackBacktracking(weights, values, 2, 1), 5);
}

TEST(KnapsackTest, OrderOfItemsDoesNotMatter) {
    int weights1[] = { 30, 20, 10 };
    int values1[] = { 120, 100, 60 };
    int weights2[] = { 3, 6, 4, 5 };
    int values2[] = { 50, 30, 40, 10 };

    EXPECT_EQ(knapsackBacktracking(weights1, values1, 3, 50), 220);
    EXPECT_EQ(knapsackBacktracking(weights2, values2, 4, 10), 90);
}

TEST(KnapsackTest, MaximumItemCount) {
    // 20 items (the limit): weight 1..20, value = 2 * weight, capacity 100
    int weights[20];
    int values[20];
    for (int i = 0; i < 20; i++) {
        weights[i] = i + 1;
        values[i] = (i + 1) * 2;
    }

    // value is always 2 x weight and the bag can be filled exactly, so: 200
    EXPECT_EQ(knapsackBacktracking(weights, values, 20, 100), 200);
}


// Standalone GoogleTest entry point.
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
