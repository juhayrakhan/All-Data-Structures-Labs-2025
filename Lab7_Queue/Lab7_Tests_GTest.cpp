#include <gtest/gtest.h>
#include "Solution.h" // Replace with the header that declares this lab’s implementation


using namespace std;

// ============================================================================
// Question 1: Design a Generic Queue Class Using Templates
// ============================================================================
TEST(Q1_GenericQueueTest, EnqueueDequeueBasic) {
    Queue<int> queue_int;
    EXPECT_TRUE(queue_int.is_empty());
    EXPECT_EQ(queue_int.size(), 0);
    
    queue_int.enqueue(10);
    queue_int.enqueue(20);
    queue_int.enqueue(30);
    
    EXPECT_FALSE(queue_int.is_empty());
    EXPECT_EQ(queue_int.size(), 3);
    EXPECT_EQ(queue_int.peek(), 10);
    EXPECT_EQ(queue_int.dequeue(), 10);
    EXPECT_EQ(queue_int.size(), 2);
    EXPECT_EQ(queue_int.dequeue(), 20);
    EXPECT_EQ(queue_int.dequeue(), 30);
    EXPECT_TRUE(queue_int.is_empty());
}

TEST(Q1_GenericQueueTest, EnqueueDequeueDouble) {
    Queue<double> queue_double;
    queue_double.enqueue(3.14);
    queue_double.enqueue(2.71);
    queue_double.enqueue(1.41);
    
    EXPECT_EQ(queue_double.size(), 3);
    EXPECT_DOUBLE_EQ(queue_double.peek(), 3.14);
    EXPECT_DOUBLE_EQ(queue_double.dequeue(), 3.14);
    EXPECT_DOUBLE_EQ(queue_double.dequeue(), 2.71);
    EXPECT_DOUBLE_EQ(queue_double.dequeue(), 1.41);
}

TEST(Q1_GenericQueueTest, EnqueueDequeueString) {
    Queue<char> queue_char;
    queue_char.enqueue('a');
    queue_char.enqueue('b');
    queue_char.enqueue('c');
    
    EXPECT_EQ(queue_char.size(), 3);
    EXPECT_EQ(queue_char.peek(), 'a');
    EXPECT_EQ(queue_char.dequeue(), 'a');
    EXPECT_EQ(queue_char.dequeue(), 'b');
    EXPECT_EQ(queue_char.dequeue(), 'c');
}

TEST(Q1_GenericQueueTest, PeekWithoutRemoving) {
    Queue<int> queue_int;
    queue_int.enqueue(100);
    queue_int.enqueue(200);
    
    EXPECT_EQ(queue_int.peek(), 100);
    EXPECT_EQ(queue_int.size(), 2);  // peek should not remove
    EXPECT_EQ(queue_int.peek(), 100);
    EXPECT_EQ(queue_int.size(), 2);
}

TEST(Q1_GenericQueueTest, ClearQueue) {
    Queue<int> queue_int;
    queue_int.enqueue(10);
    queue_int.enqueue(20);
    queue_int.enqueue(30);
    
    EXPECT_EQ(queue_int.size(), 3);
    queue_int.clear();
    
    EXPECT_TRUE(queue_int.is_empty());
    EXPECT_EQ(queue_int.size(), 0);
}

TEST(Q1_GenericQueueTest, SizeTracking) {
    Queue<int> queue_int;
    EXPECT_EQ(queue_int.size(), 0);
    
    for (int i = 1; i <= 5; ++i) {
        queue_int.enqueue(i * 10);
        EXPECT_EQ(queue_int.size(), i);
    }
    
    for (int i = 5; i >= 1; --i) {
        EXPECT_EQ(queue_int.size(), i);
        queue_int.dequeue();
    }
    EXPECT_EQ(queue_int.size(), 0);
}

TEST(Q1_GenericQueueTest, IsPalindromeRecursive) {
    Queue<char> queue_char;
    
    // Test case 1: palindrome "madam"
    EXPECT_TRUE(queue_char.isPalindrome("madam"));
    
    // Test case 2: not palindrome "queue"
    EXPECT_FALSE(queue_char.isPalindrome("queue"));
    
    // Test case 3: single character
    EXPECT_TRUE(queue_char.isPalindrome("a"));
    
    // Test case 4: empty string
    EXPECT_TRUE(queue_char.isPalindrome(""));
    
    // Test case 5: two same characters
    EXPECT_TRUE(queue_char.isPalindrome("aa"));
    
    // Test case 6: palindrome "racecar"
    EXPECT_TRUE(queue_char.isPalindrome("racecar"));
    
    // Test case 7: not palindrome "hello"
    EXPECT_FALSE(queue_char.isPalindrome("hello"));
}

TEST(Q1_GenericQueueTest, AlternateEnqueueDequeue) {
    Queue<int> queue_int;
    
    queue_int.enqueue(1);
    queue_int.enqueue(2);
    EXPECT_EQ(queue_int.dequeue(), 1);
    
    queue_int.enqueue(3);
    queue_int.enqueue(4);
    EXPECT_EQ(queue_int.dequeue(), 2);
    EXPECT_EQ(queue_int.dequeue(), 3);
    EXPECT_EQ(queue_int.dequeue(), 4);
    EXPECT_TRUE(queue_int.is_empty());
}

// ============================================================================
// Question 3: Round Robin CPU Scheduler (Simple Queue)
//
// These tests call YOUR function. Expected signature:
//     int roundRobin(int tasks[], int n, int quantum, int log[]);
//   - log[i] = remaining time of the task after its i-th turn
//   - returns the total number of turns
// Rule: full quantum is always subtracted (remaining can be negative).
//       remaining <= 0 -> completed, remaining > 0 -> re-queued.
// ============================================================================

// Manual example: [50, 30, 80, 100], quantum = 30
TEST(Q3_RoundRobinSchedulerTest, ManualExample) {
    int tasks[] = { 50, 30, 80, 100 };
    int log[20];
    int steps = roundRobin(tasks, 4, 30, log);

    EXPECT_EQ(steps, 10);
    EXPECT_EQ(log[0], 20);
    EXPECT_EQ(log[1], 0);
    EXPECT_EQ(log[2], 50);
    EXPECT_EQ(log[3], 70);
    EXPECT_EQ(log[4], -10);
    EXPECT_EQ(log[5], 20);
    EXPECT_EQ(log[6], 40);
    EXPECT_EQ(log[7], -10);
    EXPECT_EQ(log[8], 10);
    EXPECT_EQ(log[9], -20);
}

TEST(Q3_RoundRobinSchedulerTest, AllTasksCompleteInFirstQuantum) {
    int tasks[] = { 10, 15, 20 };
    int log[20];
    int steps = roundRobin(tasks, 3, 30, log);

    EXPECT_EQ(steps, 3);
    EXPECT_EQ(log[0], -20);
    EXPECT_EQ(log[1], -15);
    EXPECT_EQ(log[2], -10);
}

TEST(Q3_RoundRobinSchedulerTest, SingleTask) {
    int tasks[] = { 50 };
    int log[20];
    int steps = roundRobin(tasks, 1, 30, log);

    EXPECT_EQ(steps, 2);
    EXPECT_EQ(log[0], 20);
    EXPECT_EQ(log[1], -10);
}

TEST(Q3_RoundRobinSchedulerTest, TaskEqualToQuantum) {
    int tasks[] = { 30 };
    int log[20];
    int steps = roundRobin(tasks, 1, 30, log);

    EXPECT_EQ(steps, 1);    // remaining 0 = finished, not re-queued
    EXPECT_EQ(log[0], 0);
}

TEST(Q3_RoundRobinSchedulerTest, ExactMultipleOfQuantum) {
    int tasks[] = { 60 };
    int log[20];
    int steps = roundRobin(tasks, 1, 30, log);

    EXPECT_EQ(steps, 2);
    EXPECT_EQ(log[0], 30);
    EXPECT_EQ(log[1], 0);
}

TEST(Q3_RoundRobinSchedulerTest, DifferentQuantum) {
    int tasks[] = { 25, 10 };
    int log[20];
    int steps = roundRobin(tasks, 2, 10, log);

    EXPECT_EQ(steps, 4);
    EXPECT_EQ(log[0], 15);
    EXPECT_EQ(log[1], 0);
    EXPECT_EQ(log[2], 5);
    EXPECT_EQ(log[3], -5);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
