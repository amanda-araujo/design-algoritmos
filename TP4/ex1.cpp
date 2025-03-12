#include "exercises.h"
#include "cmath"
#include <iostream>

int max(int A[], int start, int end, int &i, int &j) {

    // FORWARD : Divide
    // Base case
    if (start == end) {
        i = j = start;
        return A[start];
    }

    // Recursive
    int start2 = (int)round((start + end)/2.0);
    int end1 = start2 - 1;
    int i1, j1, i2, j2;
    int bestSum1 = max(A, start, end1, i1, j1); // left
    int bestSum2 = max(A, start2, end, i2, j2); // right

    // BACKWARD: Combine
    // Check the other possible solution (middle)
    int curSum = A[end1]; // left
    int bestCrossingSum1 = A[end1];
    int iCrossing = end1;
    for (int k = end1 - 1; k >= start; k--) {
        curSum += A[k];
        if (curSum > bestCrossingSum1) {
            bestCrossingSum1 = curSum;
            iCrossing = k; // new i
        }
    }

    curSum = A[start2]; // right
    int bestCrossingSum2 = A[start2];
    int jCrossing = start2;
    for (int k = start2 + 1; k <= end; k++) {
        curSum += A[k];
        if (curSum > bestCrossingSum2) {
            bestCrossingSum2 = curSum;
            jCrossing = k; // new j
        }
    }

    int bestCrossing = bestCrossingSum1 + bestCrossingSum2; // join left and right

    // Merge: comparing solutions bestSum1, bestSum2 and bestCrossing
    if (bestSum1 > bestSum2 and bestSum1 > bestCrossing) {
        i = i1;
        j = j1;
        return bestSum1;
    }
    else if (bestSum2 > bestSum1 and bestSum2 > bestCrossing) {
        i = i2;
        j = j2;
        return bestSum2;
    }
    else {
        i = iCrossing;
        j = jCrossing;
        return bestCrossing;
    }
}

int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j) {
    // TODO: Implement function
    int start = 0;
    int end = n - 1;
    return max(A, start, end , i, j);
}

// int main () {
//     int A1[] = {1, 2, 3, 4};
//     unsigned int n1 = 4;
//     int i, j;
//     int sum = max(A1, 0, 3, i, j);
//     std::cout << sum << std::endl;
//     return 0;
// }

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex1, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    int i, j;
    EXPECT_EQ(maxSubsequenceDC(A1,n1,i,j), 10);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
    EXPECT_EQ(maxSubsequenceDC(A2,n2,i,j), 4);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    EXPECT_EQ(maxSubsequenceDC(A3,n3,i,j), 8);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    EXPECT_EQ(maxSubsequenceDC(A4,n4,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}