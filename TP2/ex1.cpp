// By: Gonçalo Leão
// With contributions by Eduardo Almeida
// Updated by DA 24/2
// Amanda Araujo Silva


int maxSubsequenceBF(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    // Array (contiguous): i:start; j: end
    //TODO
    int maxsum = 0; // maximum sum

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {

            // Testing all possible subarrays
            int sum = 0;
            for (int k = a; k < b + 1; k++) {
                sum = sum + A[k]; // sum
            }
            if (sum > maxsum) { // checking maxsum
                maxsum = sum;
                i = a; // Start of contiguous subarray
                j = b; // End of contiguous subarray
            }
        }
    }

    return maxsum;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP2_Ex1, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequenceBF(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}