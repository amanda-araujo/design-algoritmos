#include <iostream>     // std::cout
#include <algorithm>    // std::count
#include "exercises.h"

std::string hanoiDC(unsigned int n, char src, char dest) {
    // TODO: Implement function
    // Input: # disks, source, destination
    // src, dest, temp

    // Base case
    if (n == 1) return std::string(1,src) + "->" + std::string(1,dest);

    char temp;
    if ((src == 'A' and dest == 'B') or (src == 'B' and dest == 'A')) temp = 'C';
    else if ((src == 'A' and dest == 'C') or (src == 'C' and dest == 'A')) temp = 'B';
    else temp = 'A';

    return hanoiDC(n - 1, src, temp) + "," + hanoiDC(1, src, dest) + "," + hanoiDC(n - 1, temp, dest);
    }
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex2, testHanoi_height4) {
    std::string moves = hanoiDC(4, 'A', 'B');
    EXPECT_EQ(std::count(moves.begin(),moves.end(),','),14); // there are 15 moves
    EXPECT_EQ(moves,"A->C,A->B,C->B,A->C,B->A,B->C,A->C,A->B,C->B,C->A,B->A,C->B,A->C,A->B,C->B");
}