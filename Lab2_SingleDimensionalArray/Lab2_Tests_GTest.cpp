#include <gtest/gtest.h>
#include "Solution.h" // Replace with the header that declares this lab’s implementation
// ques 1 (Find Minimum and Maximum)
TEST(FindMinMax, TypeInt) {
    int nums[] = { 8, 3, 12, 1, 9, 5 };
    int size = sizeof(nums) / sizeof(nums[0]);
    int min = 0, max = 0;

    findMinMax(nums, size, min, max);

    EXPECT_EQ(1, min);
    EXPECT_EQ(12, max);
}

TEST(FindMinMax, TypeDouble) {
    double nums[] = { 4.4, 1.1, 9.9, 2.2 };
    int size = sizeof(nums) / sizeof(nums[0]);
    double min = 0, max = 0;

    findMinMax(nums, size, min, max);

    EXPECT_EQ(1.1, min);
    EXPECT_EQ(9.9, max);
}

// ques 2 (Reverse an Array)
TEST(ReverseArray, TypeInt) {
    int nums[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(nums) / sizeof(nums[0]);
    int expected[] = { 5, 4, 3, 2, 1 };

    reverseArray(nums, size);

    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(nums[i], expected[i]);
    }
}

TEST(ReverseArray, TypeDouble) {
    double nums[] = { 1.1, 2.2, 3.3, 4.4 };
    int size = sizeof(nums) / sizeof(nums[0]);
    double expected[] = { 4.4, 3.3, 2.2, 1.1 };

    reverseArray(nums, size);

    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(nums[i], expected[i]);
    }
}

// ques 3 (Remove Duplicate Elements)
TEST(RemoveDuplicates, TypeInt) {
    int nums[] = { 1, 2, 2, 3, 1, 4, 3 };
    int size = sizeof(nums) / sizeof(nums[0]);
    int expected[] = { 1, 2, 3, 4 };

    int newSize = removeDuplicates(nums, size);

    EXPECT_EQ(4, newSize);

    for (int i = 0; i < newSize; ++i) {
        EXPECT_EQ(nums[i], expected[i]);
    }
}

TEST(RemoveDuplicates, TypeDouble) {
    double nums[] = { 1.1, 2.2, 1.1, 3.3, 2.2 };
    int size = sizeof(nums) / sizeof(nums[0]);
    double expected[] = { 1.1, 2.2, 3.3 };

    int newSize = removeDuplicates(nums, size);

    EXPECT_EQ(3, newSize);

    for (int i = 0; i < newSize; ++i) {
        EXPECT_EQ(nums[i], expected[i]);
    }
}

// ques 4 (Template Array Container)
TEST(ArrayContainer, CalculateSum) {
    int nums[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(nums) / sizeof(nums[0]);

    ArrayContainer<int> container(nums, size);

    ASSERT_EQ(15, container.calculateSum());
}

TEST(ArrayContainer, CalculateAverage) {
    double nums[] = { 1.0, 2.0, 3.0, 4.0 };
    int size = sizeof(nums) / sizeof(nums[0]);

    ArrayContainer<double> container(nums, size);

    ASSERT_EQ(2.5, container.calculateAverage());
}

TEST(ArrayContainer, FindLargest) {
    int nums[] = { 8, 3, 15, 6, 10 };
    int size = sizeof(nums) / sizeof(nums[0]);

    ArrayContainer<int> container(nums, size);

    ASSERT_EQ(15, container.findLargest());
}

// Standalone GoogleTest entry point.
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
