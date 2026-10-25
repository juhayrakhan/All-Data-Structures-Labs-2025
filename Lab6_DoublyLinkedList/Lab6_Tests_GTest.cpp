#include <gtest/gtest.h>
#include "Solution.h" // Replace with the header that declares this lab’s implementation

// ============================================================================
// Question 1: Design a Doubly Linked List Class
// ============================================================================
TEST(Q1_DoublyLinkedListTest, InsertSearchUpdateDeletePrint) {
    DoublyLinkedList list;
    EXPECT_TRUE(list.isEmpty());

    list.insert(10);            // list: 10
    list.insert(20);            // list: 10 <-> 20
    list.insertToHead(5);       // list: 5 <-> 10 <-> 20
    list.insertAtIndex(1, 7);   // list: 5 <-> 7 <-> 10 <-> 20

    EXPECT_FALSE(list.isEmpty());
    EXPECT_TRUE(list.search(10));
    EXPECT_FALSE(list.search(99));

    EXPECT_TRUE(list.update(20, 99));   // list: 5 <-> 7 <-> 10 <-> 99
    EXPECT_TRUE(list.deleteData(7));    // list: 5 <-> 10 <-> 99
    EXPECT_FALSE(list.deleteData(123)); // not present -> false

    // walk the raw nodes forward and backward to check both links
    DoublyNode* head = list.getHead();
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->getData(), 5);
    EXPECT_EQ(head->getNext()->getData(), 10);
    EXPECT_EQ(head->getNext()->getNext()->getData(), 99);
    EXPECT_EQ(head->getNext()->getNext()->getPrev()->getData(), 10);
    EXPECT_EQ(head->getNext()->getNext()->getNext(), nullptr);
}

// ============================================================================
// Question 3: Josephus Problem with a Circular Doubly Linked List
// ============================================================================
TEST(Q3_JosephusTest, SequentialElimination) {
    EXPECT_EQ(josephus(5, 0), 5);   // M = 0 -> eliminate in order, last one wins
}

TEST(Q3_JosephusTest, ClassicMEqualsOne) {
    EXPECT_EQ(josephus(5, 1), 3);   // elimination order 2,4,1,5 -> winner 3
}

TEST(Q3_JosephusTest, SinglePersonWinsImmediately) {
    EXPECT_EQ(josephus(1, 3), 1);
}

// ============================================================================
// Main Runner
// ============================================================================
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
