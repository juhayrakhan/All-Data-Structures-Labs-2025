#include <gtest/gtest.h>
#include "Solution.h" // Replace with the header that declares this lab’s implementation
#include <string>

//=======================================================
// TASK 0
//=======================================================

TEST(LinkedListTest, DefaultEmptyState) {
    LinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.counter, 0);
    EXPECT_FALSE(list.search(100));
}

TEST(LinkedListTest, InsertAtHead) {
    LinkedList<int> list;
    list.insertAtHead(20);
    list.insertAtHead(10);

    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.counter, 2);
    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(20));
}

TEST(LinkedListTest, InsertAtTail) {
    LinkedList<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);

    EXPECT_EQ(list.counter, 2);
    EXPECT_TRUE(list.search(20));
    EXPECT_FALSE(list.search(999));
}

TEST(LinkedListTest, InsertBeforeAndAfterInvalidTargetsFail) {
    LinkedList<int> list;

    EXPECT_FALSE(list.insertAfter(50, 10));
    EXPECT_FALSE(list.insertBefore(50, 10));

    list.insertAtHead(10);
    EXPECT_FALSE(list.insertAfter(99, 404));
    EXPECT_FALSE(list.insertBefore(99, 404));
    EXPECT_EQ(list.counter, 1);
}

TEST(LinkedListTest, InsertBeforeHeadUpdatesHead) {
    LinkedList<int> list;
    list.insertAtTail(20);

    EXPECT_TRUE(list.insertBefore(10, 20));
    EXPECT_EQ(list.counter, 2);
    EXPECT_TRUE(list.search(10));
}

TEST(LinkedListTest, InsertBeforeAndAfterMiddle) {
    LinkedList<int> list;
    list.insertAtTail(10);
    list.insertAtTail(40);

    EXPECT_TRUE(list.insertAfter(20, 10));
    EXPECT_TRUE(list.insertBefore(30, 40));
    EXPECT_EQ(list.counter, 4);
    EXPECT_TRUE(list.search(20));
    EXPECT_TRUE(list.search(30));
}

TEST(LinkedListTest, SupportsStringTemplateType) {
    LinkedList<std::string> strList;
    strList.insertAtHead("World");
    strList.insertBefore("Hello", "World");

    EXPECT_EQ(strList.counter, 2);
    EXPECT_TRUE(strList.search("Hello"));
    EXPECT_TRUE(strList.search("World"));
    EXPECT_FALSE(strList.search("Missing"));
}

//=======================================================
// Question 1
//=======================================================

TEST(CountFrequencyTest, EmptyListReturnsZero) {
    LinkedList<double> list;
    EXPECT_EQ(list.countFrequency(10.0), 0);
}

TEST(CountFrequencyTest, TargetNotPresentReturnsZero) {
    LinkedList<double> list;
    list.insertAtTail(10.0);
    list.insertAtTail(20.0);
    list.insertAtTail(30.0);

    EXPECT_EQ(list.countFrequency(99.0), 0);
}

TEST(CountFrequencyTest, SingleElementMatches) {
    LinkedList<double> list;
    list.insertAtTail(25.5);

    EXPECT_EQ(list.countFrequency(25.5), 1);
    EXPECT_EQ(list.countFrequency(10.0), 0);
}

TEST(CountFrequencyTest, MultipleMatchesScattered) {
    LinkedList<double> list;
    list.insertAtTail(10.0);
    list.insertAtTail(20.0);
    list.insertAtTail(10.0);
    list.insertAtTail(30.0);
    list.insertAtTail(10.0);

    EXPECT_EQ(list.countFrequency(10.0), 3);
    EXPECT_EQ(list.countFrequency(20.0), 1);
    EXPECT_EQ(list.countFrequency(30.0), 1);
}

TEST(CountFrequencyTest, ConsecutiveMatches) {
    LinkedList<double> list;
    list.insertAtTail(5.0);
    list.insertAtTail(5.0);
    list.insertAtTail(5.0);
    list.insertAtTail(5.0);

    EXPECT_EQ(list.countFrequency(5.0), 4);
}

TEST(CountFrequencyTest, TargetAtBoundaries) {
    LinkedList<double> list;
    list.insertAtTail(7.0);
    list.insertAtTail(14.0);
    list.insertAtTail(21.0);
    list.insertAtTail(7.0);

    EXPECT_EQ(list.countFrequency(7.0), 2);
}

//=======================================================
// Question 2
//=======================================================

TEST(ReverseKGroupTest, InvalidKDoesNothing) {
    LinkedList<double> list;
    list.insertAtTail(10.0);
    list.insertAtTail(20.0);

    list.reverseKGroup(0);
    EXPECT_DOUBLE_EQ(list.search(10.0), 0);
    EXPECT_DOUBLE_EQ(list.search(20.0), 1);

    list.reverseKGroup(-2);
    EXPECT_DOUBLE_EQ(list.search(10.0), 0);
    EXPECT_DOUBLE_EQ(list.search(20.0), 1);
}

TEST(ReverseKGroupTest, KEqualsOneLeavesListUnchanged) {
    LinkedList<double> list;
    list.insertAtTail(10.0);
    list.insertAtTail(20.0);
    list.insertAtTail(30.0);

    list.reverseKGroup(1);

    EXPECT_DOUBLE_EQ(list.search(10.0), 0);
    EXPECT_DOUBLE_EQ(list.search(20.0), 1);
    EXPECT_DOUBLE_EQ(list.search(30.0), 2);
}

TEST(ReverseKGroupTest, ListLengthLessThanKLeavesListUnchanged) {
    LinkedList<double> list;
    list.insertAtTail(10.0);
    list.insertAtTail(20.0);

    list.reverseKGroup(3);

    EXPECT_DOUBLE_EQ(list.search(10.0), 0);
    EXPECT_DOUBLE_EQ(list.search(20.0), 1);
}

TEST(ReverseKGroupTest, ExactMultipleOfKReversesAllGroups) {
    LinkedList<double> list;
    list.insertAtTail(1.0);
    list.insertAtTail(2.0);
    list.insertAtTail(3.0);
    list.insertAtTail(4.0);

    list.reverseKGroup(2);

    EXPECT_DOUBLE_EQ(list.search(2.0), 0);
    EXPECT_DOUBLE_EQ(list.search(1.0), 1);
    EXPECT_DOUBLE_EQ(list.search(4.0), 2);
    EXPECT_DOUBLE_EQ(list.search(3.0), 3);
}

TEST(ReverseKGroupTest, TrailingNodesLessThanKRemainUnchanged) {
    LinkedList<double> list;
    list.insertAtTail(10.0);
    list.insertAtTail(20.0);
    list.insertAtTail(30.0);
    list.insertAtTail(40.0);
    list.insertAtTail(50.0);
    list.insertAtTail(60.0);
    list.insertAtTail(70.0);
    list.insertAtTail(80.0);

    list.reverseKGroup(3);

    EXPECT_DOUBLE_EQ(list.search(30.0), 0);
    EXPECT_DOUBLE_EQ(list.search(20.0), 1);
    EXPECT_DOUBLE_EQ(list.search(10.0), 2);
    EXPECT_DOUBLE_EQ(list.search(60.0), 3);
    EXPECT_DOUBLE_EQ(list.search(50.0), 4);
    EXPECT_DOUBLE_EQ(list.search(40.0), 5);
    EXPECT_DOUBLE_EQ(list.search(70.0), 6);
    EXPECT_DOUBLE_EQ(list.search(80.0), 7);
}

TEST(ReverseKGroupTest, KEqualsEntireListLengthReversesWholeList) {
    LinkedList<double> list;
    list.insertAtTail(10.0);
    list.insertAtTail(20.0);
    list.insertAtTail(30.0);

    list.reverseKGroup(3);

    EXPECT_DOUBLE_EQ(list.search(30.0), 0);
    EXPECT_DOUBLE_EQ(list.search(20.0), 1);
    EXPECT_DOUBLE_EQ(list.search(10.0), 2);
}

//=======================================================
// Question 3
//=======================================================

TEST(AddTwoNumbersTest, SingleDigitsWithoutCarry) {
    LinkedList<double> l1;
    l1.insertAtTail(3.0);

    LinkedList<double> l2;
    l2.insertAtTail(4.0);

    LinkedList<double> result;
    result.insertAtStart(0.0);
    result.deleteFromStart();

    Node<double>* resHead = addTwoNumbers(
        l1.search(3.0) != -1 ? new Node<double>(3.0) : nullptr,
        l2.search(4.0) != -1 ? new Node<double>(4.0) : nullptr
    );

    ASSERT_NE(resHead, nullptr);
    EXPECT_DOUBLE_EQ(resHead->data, 7.0);
    EXPECT_EQ(resHead->next, nullptr);

    delete resHead;
}

TEST(AddTwoNumbersTest, SingleDigitsWithCarryOver) {
    Node<double>* l1 = new Node<double>(7.0);
    Node<double>* l2 = new Node<double>(8.0);

    Node<double>* res = addTwoNumbers(l1, l2);

    ASSERT_NE(res, nullptr);
    EXPECT_DOUBLE_EQ(res->data, 5.0);
    ASSERT_NE(res->next, nullptr);
    EXPECT_DOUBLE_EQ(res->next->data, 1.0);
    EXPECT_EQ(res->next->next, nullptr);

    delete l1;
    delete l2;
    delete res->next;
    delete res;
}

TEST(AddTwoNumbersTest, SameLengthListsExample) {
    Node<double>* l1 = new Node<double>(2.0);
    l1->next = new Node<double>(4.0);
    l1->next->next = new Node<double>(3.0);

    Node<double>* l2 = new Node<double>(5.0);
    l2->next = new Node<double>(6.0);
    l2->next->next = new Node<double>(4.0);

    Node<double>* res = addTwoNumbers(l1, l2);

    ASSERT_NE(res, nullptr);
    EXPECT_DOUBLE_EQ(res->data, 7.0);
    ASSERT_NE(res->next, nullptr);
    EXPECT_DOUBLE_EQ(res->next->data, 0.0);
    ASSERT_NE(res->next->next, nullptr);
    EXPECT_DOUBLE_EQ(res->next->next->data, 8.0);
    EXPECT_EQ(res->next->next->next, nullptr);

    delete l1->next->next; delete l1->next; delete l1;
    delete l2->next->next; delete l2->next; delete l2;
    delete res->next->next; delete res->next; delete res;
}

TEST(AddTwoNumbersTest, UnequalLengths) {
    Node<double>* l1 = new Node<double>(9.0);
    l1->next = new Node<double>(9.0);

    Node<double>* l2 = new Node<double>(1.0);

    Node<double>* res = addTwoNumbers(l1, l2);

    ASSERT_NE(res, nullptr);
    EXPECT_DOUBLE_EQ(res->data, 0.0);
    ASSERT_NE(res->next, nullptr);
    EXPECT_DOUBLE_EQ(res->next->data, 0.0);
    ASSERT_NE(res->next->next, nullptr);
    EXPECT_DOUBLE_EQ(res->next->next->data, 1.0);
    EXPECT_EQ(res->next->next->next, nullptr);

    delete l1->next; delete l1;
    delete l2;
    delete res->next->next; delete res->next; delete res;
}

TEST(AddTwoNumbersTest, AdditionWithZeroList) {
    Node<double>* l1 = new Node<double>(0.0);

    Node<double>* l2 = new Node<double>(5.0);
    l2->next = new Node<double>(6.0);

    Node<double>* res = addTwoNumbers(l1, l2);

    ASSERT_NE(res, nullptr);
    EXPECT_DOUBLE_EQ(res->data, 5.0);
    ASSERT_NE(res->next, nullptr);
    EXPECT_DOUBLE_EQ(res->next->data, 6.0);
    EXPECT_EQ(res->next->next, nullptr);

    delete l1;
    delete l2->next; delete l2;
    delete res->next; delete res;
}

TEST(AddTwoNumbersTest, CascadingCarriesToEnd) {
    Node<double>* l1 = new Node<double>(9.0);
    l1->next = new Node<double>(9.0);
    l1->next->next = new Node<double>(9.0);

    Node<double>* l2 = new Node<double>(1.0);

    Node<double>* res = addTwoNumbers(l1, l2);

    ASSERT_NE(res, nullptr);
    EXPECT_DOUBLE_EQ(res->data, 0.0);
    ASSERT_NE(res->next, nullptr);
    EXPECT_DOUBLE_EQ(res->next->data, 0.0);
    ASSERT_NE(res->next->next, nullptr);
    EXPECT_DOUBLE_EQ(res->next->next->data, 0.0);
    ASSERT_NE(res->next->next->next, nullptr);
    EXPECT_DOUBLE_EQ(res->next->next->next->data, 1.0);
    EXPECT_EQ(res->next->next->next->next, nullptr);

    delete l1->next->next; delete l1->next; delete l1;
    delete l2;
    delete res->next->next->next; delete res->next->next; delete res->next; delete res;
}

// Standalone GoogleTest entry point.
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
