#include <cmath>
#include <gtest/gtest.h>
#include "Solution.h" // Replace with the header that declares this lab’s implementation

// Question 1: Student Quiz Records and Statistical Analysis
TEST(Q1_ClassPerformanceTest, QuizStatistics) {
    const int numStudents = 3, numQuizzes = 3;
    int rollNumbers[3] = { 1001, 1002, 1003 };
    int scores[3][3] = {
        { 80, 90, 70 },
        { 60, 85, 95 },
        { 70, 75, 80 }
    };
    EXPECT_NO_THROW(calculateHighLowScores(numStudents, numQuizzes, scores));
    EXPECT_NO_THROW(calculateAverages(numStudents, numQuizzes, scores));
    EXPECT_NO_THROW(calculateHighestLowestAverages(numStudents, numQuizzes, scores));
    EXPECT_NO_THROW(calculateHighestLowestMarks(numStudents, numQuizzes, scores));
}

// Question 2: 3x3 Determinant Calculation
TEST(Q2_DeterminantTest, Matrix3x3) {
    int m1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    EXPECT_EQ(calculateDeterminant(m1), 0);

    int m2[3][3] = { {6, 1, 1}, {4, -2, 5}, {2, 8, 7} };
    EXPECT_EQ(calculateDeterminant(m2), -306);
}


// Question 3: Semester GPA / Lowest CGPA Finder
TEST(Q3_LowestCGPATest, BasicCalculation) {
    const int numStudents = 3;
    const int numSemesters = 4;
    double gpas[numStudents][numSemesters] = {
        { 3.5, 3.8, 3.9, 3.6 }, // 3.70
        { 2.8, 3.0, 2.9, 3.1 }, // 2.95 (Lowest)
        { 3.2, 3.4, 3.5, 3.6 }  // 3.425
    };
    double lowestCGPA = computeCGPAsAndFindLowest<double, numSemesters>(gpas, numStudents);
    EXPECT_NEAR(lowestCGPA, 2.95, 1e-3);
}

// Question 4: Cricket Player Match Statistics
TEST(Q4_CricketStatsTest, PlayerStatistics) {
    const int numPlayers = 12, numMatches = 10;
    int runs[numPlayers][numMatches] = {0};
    for (int i = 0; i < numPlayers; ++i) {
        for (int j = 0; j < numMatches; ++j) {
            runs[i][j] = (i + 1) * 4;
        }
    }
    int totalRuns[numPlayers];
    int avgRuns[numPlayers];
    computeStatistics<int, numMatches>(runs, numPlayers, totalRuns, avgRuns);
    EXPECT_EQ(totalRuns[11], 480);
    EXPECT_EQ(avgRuns[11], 48);

    int indices[numPlayers];
    for (int i = 0; i < numPlayers; ++i) indices[i] = i;
    sortPlayersByTotalRuns<int>(totalRuns, indices, numPlayers);
    EXPECT_EQ(indices[0], 11);
}

// ============================================================================
// Main Runner
// ============================================================================
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
