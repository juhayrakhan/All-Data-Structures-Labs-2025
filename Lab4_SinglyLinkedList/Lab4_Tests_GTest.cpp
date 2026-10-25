#include <gtest/gtest.h>
#include "Solution.h" // Replace with the header that declares this lab’s implementation

//=======================================================
// TASK 1: ArrayList - Core Operations
//=======================================================

TEST(ArrayListTest, DefaultEmptyState) {
    ArrayList list(5);

    EXPECT_TRUE(list.isEmpty());
    EXPECT_FALSE(list.isFull());
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.search(10), -1);
}

TEST(ArrayListTest, InsertAtStartMiddleEnd) {
    ArrayList list(5);

    EXPECT_TRUE(list.insert(0, 10));   // [10]
    EXPECT_TRUE(list.insert(1, 30));   // [10, 30]
    EXPECT_TRUE(list.insert(1, 20));   // [10, 20, 30]

    EXPECT_EQ(list.getSize(), 3);
    EXPECT_EQ(list.search(10), 0);
    EXPECT_EQ(list.search(20), 1);
    EXPECT_EQ(list.search(30), 2);
}

TEST(ArrayListTest, InsertOutOfBoundsFails) {
    ArrayList list(3);
    list.insert(0, 10);

    EXPECT_FALSE(list.insert(-1, 5));
    EXPECT_FALSE(list.insert(5, 5));
    EXPECT_EQ(list.getSize(), 1);
}

TEST(ArrayListTest, InsertOnFullListFails) {
    ArrayList list(2);
    EXPECT_TRUE(list.insert(0, 10));
    EXPECT_TRUE(list.insert(1, 20));

    EXPECT_TRUE(list.isFull());
    EXPECT_FALSE(list.insert(2, 30));
    EXPECT_EQ(list.getSize(), 2);
}

TEST(ArrayListTest, RemoveShiftsElementsLeft) {
    ArrayList list(5);
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);

    EXPECT_TRUE(list.remove(1)); // removes 20 -> [10, 30]

    EXPECT_EQ(list.getSize(), 2);
    EXPECT_EQ(list.search(10), 0);
    EXPECT_EQ(list.search(30), 1);
    EXPECT_EQ(list.search(20), -1);
}

TEST(ArrayListTest, RemoveOutOfBoundsOrEmptyFails) {
    ArrayList list(3);

    EXPECT_FALSE(list.remove(0)); // empty
    list.insert(0, 10);

    EXPECT_FALSE(list.remove(-1));
    EXPECT_FALSE(list.remove(5));
    EXPECT_EQ(list.getSize(), 1);
}

TEST(ArrayListTest, SearchReturnsFirstMatch) {
    ArrayList list(5);
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 10);

    EXPECT_EQ(list.search(10), 0);
    EXPECT_EQ(list.search(20), 1);
    EXPECT_EQ(list.search(99), -1);
}

//---------------------------------------------------
// get() — new Task 1 function
//---------------------------------------------------

TEST(ArrayListTest, GetOnEmptyListReturnsMinusOne) {
    ArrayList list(5);

    EXPECT_EQ(list.get(0), -1);
}

TEST(ArrayListTest, GetReturnsCorrectValueAtIndex) {
    ArrayList list(5);
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.get(2), 30);
}

TEST(ArrayListTest, GetOutOfBoundsReturnsMinusOne) {
    ArrayList list(5);
    list.insert(0, 10);
    list.insert(1, 20);

    EXPECT_EQ(list.get(-1), -1);
    EXPECT_EQ(list.get(2), -1);
    EXPECT_EQ(list.get(99), -1);
}

TEST(ArrayListTest, GetAfterRemoveReflectsShiftedElements) {
    ArrayList list(5);
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);

    list.remove(0); // -> [20, 30]

    EXPECT_EQ(list.get(0), 20);
    EXPECT_EQ(list.get(1), 30);
    EXPECT_EQ(list.get(2), -1);
}

//---------------------------------------------------
// replace() — new Task 1 function
//---------------------------------------------------

TEST(ArrayListTest, ReplaceOnEmptyListFails) {
    ArrayList list(5);

    EXPECT_FALSE(list.replace(0, 99));
}

TEST(ArrayListTest, ReplaceUpdatesValueAtIndex) {
    ArrayList list(5);
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);

    EXPECT_TRUE(list.replace(1, 99)); // [10, 99, 30]

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 99);
    EXPECT_EQ(list.get(2), 30);
    EXPECT_EQ(list.getSize(), 3);
    EXPECT_EQ(list.search(20), -1);
    EXPECT_EQ(list.search(99), 1);
}

TEST(ArrayListTest, ReplaceOutOfBoundsFails) {
    ArrayList list(5);
    list.insert(0, 10);
    list.insert(1, 20);

    EXPECT_FALSE(list.replace(-1, 5));
    EXPECT_FALSE(list.replace(2, 5));
    EXPECT_FALSE(list.replace(99, 5));

    // Original values must remain unchanged
    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.getSize(), 2);
}

//=======================================================
// TASK 2: reverse() and removeDuplicates()
//=======================================================

TEST(ReverseTest, EmptyListStaysEmpty) {
    ArrayList list(5);
    list.reverse();
    EXPECT_TRUE(list.isEmpty());
}

TEST(ReverseTest, SingleElementUnchanged) {
    ArrayList list(5);
    list.insert(0, 42);

    list.reverse();

    EXPECT_EQ(list.search(42), 0);
    EXPECT_EQ(list.getSize(), 1);
}

TEST(ReverseTest, MultipleElementsReversedInPlace) {
    ArrayList list(5);
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(3, 40);

    list.reverse(); // [40, 30, 20, 10]

    EXPECT_EQ(list.search(40), 0);
    EXPECT_EQ(list.search(30), 1);
    EXPECT_EQ(list.search(20), 2);
    EXPECT_EQ(list.search(10), 3);
    EXPECT_EQ(list.getSize(), 4);
}

TEST(RemoveDuplicatesTest, EmptyListReturnsZero) {
    ArrayList list(5);
    EXPECT_EQ(list.removeDuplicates(), 0);
    EXPECT_TRUE(list.isEmpty());
}

TEST(RemoveDuplicatesTest, NoDuplicatesUnchanged) {
    ArrayList list(5);
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);

    EXPECT_EQ(list.removeDuplicates(), 0);
    EXPECT_EQ(list.getSize(), 3);
    EXPECT_EQ(list.search(10), 0);
    EXPECT_EQ(list.search(20), 1);
    EXPECT_EQ(list.search(30), 2);
}

TEST(RemoveDuplicatesTest, ScatteredDuplicatesKeepFirstOccurrence) {
    ArrayList list(10);
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 10);
    list.insert(3, 30);
    list.insert(4, 20);
    list.insert(5, 10);

    int removed = list.removeDuplicates(); // -> [10, 20, 30]

    EXPECT_EQ(removed, 3);
    EXPECT_EQ(list.getSize(), 3);
    EXPECT_EQ(list.search(10), 0);
    EXPECT_EQ(list.search(20), 1);
    EXPECT_EQ(list.search(30), 2);
}

TEST(RemoveDuplicatesTest, AllElementsIdentical) {
    ArrayList list(5);
    list.insert(0, 7);
    list.insert(1, 7);
    list.insert(2, 7);
    list.insert(3, 7);

    int removed = list.removeDuplicates();

    EXPECT_EQ(removed, 3);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.search(7), 0);
}

//=======================================================
// TASK 3: findMinMax() and rotateLeft()
//=======================================================

TEST(FindMinMaxTest, EmptyListDoesNotModifyValues) {
    ArrayList list(5);
    int minVal = -999;
    int maxVal = 999;

    list.findMinMax(minVal, maxVal);

    EXPECT_EQ(minVal, -999);
    EXPECT_EQ(maxVal, 999);
}

TEST(FindMinMaxTest, SingleElement) {
    ArrayList list(5);
    list.insert(0, 15);

    int minVal = 0, maxVal = 0;
    list.findMinMax(minVal, maxVal);

    EXPECT_EQ(minVal, 15);
    EXPECT_EQ(maxVal, 15);
}

TEST(FindMinMaxTest, MultipleElementsUnsorted) {
    ArrayList list(5);
    list.insert(0, 25);
    list.insert(1, 5);
    list.insert(2, 50);
    list.insert(3, 10);
    list.insert(4, 30);

    int minVal = 0, maxVal = 0;
    list.findMinMax(minVal, maxVal);

    EXPECT_EQ(minVal, 5);
    EXPECT_EQ(maxVal, 50);
}

TEST(FindMinMaxTest, NegativeAndPositiveValues) {
    ArrayList list(5);
    list.insert(0, -15);
    list.insert(1, 0);
    list.insert(2, -50);
    list.insert(3, 12);

    int minVal = 0, maxVal = 0;
    list.findMinMax(minVal, maxVal);

    EXPECT_EQ(minVal, -50);
    EXPECT_EQ(maxVal, 12);
}

TEST(RotateLeftTest, EmptyListReturnsFalse) {
    ArrayList list(5);
    EXPECT_FALSE(list.rotateLeft(3));
}

TEST(RotateLeftTest, RotateZeroPlacesUnchanged) {
    ArrayList list(5);
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);

    EXPECT_TRUE(list.rotateLeft(0));

    EXPECT_EQ(list.search(1), 0);
    EXPECT_EQ(list.search(2), 1);
    EXPECT_EQ(list.search(3), 2);
}

TEST(RotateLeftTest, StandardRotationLessThanLength) {
    ArrayList list(5);
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);
    list.insert(3, 4);
    list.insert(4, 5);

    EXPECT_TRUE(list.rotateLeft(2)); // -> [3, 4, 5, 1, 2]

    EXPECT_EQ(list.search(3), 0);
    EXPECT_EQ(list.search(4), 1);
    EXPECT_EQ(list.search(5), 2);
    EXPECT_EQ(list.search(1), 3);
    EXPECT_EQ(list.search(2), 4);
}

TEST(RotateLeftTest, RotateByExactLengthUnchanged) {
    ArrayList list(5);
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);

    EXPECT_TRUE(list.rotateLeft(3));

    EXPECT_EQ(list.search(10), 0);
    EXPECT_EQ(list.search(20), 1);
    EXPECT_EQ(list.search(30), 2);
}

TEST(RotateLeftTest, KGreaterThanLengthRequiresModulo) {
    ArrayList list(5);
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);

    EXPECT_TRUE(list.rotateLeft(4)); // 4 % 3 = 1 -> [2, 3, 1]

    EXPECT_EQ(list.search(2), 0);
    EXPECT_EQ(list.search(3), 1);
    EXPECT_EQ(list.search(1), 2);
}

//=======================================================
// TASK 4: Singly Linked List (Simple)
//=======================================================

TEST(LinkedListTest, DefaultEmptyState) {
    LinkedList list;

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.countNodes(), 0);
    EXPECT_EQ(list.search(10), -1);
}

TEST(LinkedListTest, InsertAtStart) {
    LinkedList list;

    list.insertAtStart(20);
    list.insertAtStart(10);

    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.countNodes(), 2);
    EXPECT_EQ(list.search(10), 0);
    EXPECT_EQ(list.search(20), 1);
}

TEST(LinkedListTest, InsertAtEnd) {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    EXPECT_EQ(list.countNodes(), 3);
    EXPECT_EQ(list.search(10), 0);
    EXPECT_EQ(list.search(20), 1);
    EXPECT_EQ(list.search(30), 2);
}

TEST(LinkedListTest, InsertAtEndOnEmptyListBecomesHead) {
    LinkedList list;
    list.insertAtEnd(99);

    EXPECT_EQ(list.countNodes(), 1);
    EXPECT_EQ(list.search(99), 0);
}

TEST(LinkedListTest, MixedStartAndEndInsertions) {
    LinkedList list;

    list.insertAtStart(10);
    list.insertAtStart(20);
    list.insertAtEnd(30);

    // Expected order: 20 -> 10 -> 30
    EXPECT_EQ(list.countNodes(), 3);
    EXPECT_EQ(list.search(20), 0);
    EXPECT_EQ(list.search(10), 1);
    EXPECT_EQ(list.search(30), 2);
}

TEST(LinkedListTest, SearchMissingValueReturnsMinusOne) {
    LinkedList list;
    list.insertAtStart(5);
    list.insertAtEnd(15);

    EXPECT_EQ(list.search(100), -1);
}


// Standalone GoogleTest entry point.
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
