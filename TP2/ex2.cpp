// By: Gonçalo Leão
// Updated by DA 24/25 Team
// Amanda Araujo Silva

bool subsetSumBF(unsigned int A[], unsigned int n, unsigned int T, unsigned int subset[], unsigned int &subsetSize) {
    //TODO
    subsetSize = 0;  // This variable is defined for the unit test to work. You should update it in your implementation.

    unsigned int curCand[20]; // Elements of the subset (boolean mask) // fixed size

    // Initialization
    for (int i = 0; i < n; i++) {
        curCand[i] = 0;
    }

    // Testing over all options
    while (true) {
        int sum = 0;

        // Current state sum
        for (int i = 0; i < n; i++) { // sum all elements of current state
            sum += A[i] * curCand[i];
        }
        if (sum == T) { // Subset found
            for (int i = 0; i < n; i++) {
                if (curCand[i]) { // true
                    subset[subsetSize]=A[i]; // inserting element
                    subsetSize++;
                }
            }
            return true, subset; // STOP
        }

        // else: Keep looking for it
        int curIndex = 0;
        while (curCand[curIndex]) { // true
            curIndex++;
            if (curIndex == n) break; // no more elements to sum
        }

        if (curIndex == n) break; // already checked all possibilities of subsets

        for (int i = 0; i < curIndex; i++) { // checking subsets options
            curCand[i] = 0;
        }
        curCand[curIndex] = 1;
    }

    return false, subset;
}

/// TESTS ///
#include <gtest/gtest.h>

unsigned int sum(unsigned int A[], unsigned int n) {
    unsigned int sum = 0;
    for(unsigned int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}

// Checks if A is a subset of B
bool isSubset(unsigned int A[], unsigned int nA, unsigned int B[], unsigned int nB) {
    for(unsigned int i = 0; i < nA; i++) {
        bool foundNum = false;
        for(unsigned int j = 0; j < nB; j++) {
            if(A[i] == B[j]) {
                foundNum = true;
                break;
            }
        }
        if(!foundNum) return false;
    }
    return true;
}

TEST(TP2_Ex2, testSubsetSum) {
    unsigned int A[] = {3, 34, 4, 12, 5, 2};
    unsigned int subset[6];
    unsigned int subsetSize;

    unsigned int T = 9;
    EXPECT_EQ(subsetSumBF(A,6,T,subset,subsetSize), true);
    EXPECT_EQ(sum(subset, subsetSize), T);
    EXPECT_EQ(isSubset(subset, subsetSize, A,6), true);

    T = 20;
    EXPECT_EQ(subsetSumBF(A,6,T,subset,subsetSize), true);
    EXPECT_EQ(sum(subset, subsetSize), T);
    EXPECT_EQ(isSubset(subset, subsetSize, A,6), true);

    T = 30;
    EXPECT_EQ(subsetSumBF(A,6,T,subset,subsetSize), false);
}