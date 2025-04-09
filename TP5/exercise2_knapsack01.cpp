//
// Created by up202411286 on 09-04-2025.
//

// 0-1 knapsack problem
// Implement knapsackDP using a  strategy based on dynamic programming
//
/* Write in mathematical notation the recursive functions maxValue(i, k) and lastItem(i,k) that
return the maximum total value and the index of the last item used in a knapsack with
maximum capacity k (0 ≤ ≤ k ≤ maxWeight) using only the first i items (0 ≤ i ≤ n, where n is
the number of the different items available). Use a symbol or special value if a function is not
defined.
b) Calculate the table of values for maxValue(i, k) and lastItem(i,k) for the input example below*/

int maxValue(int i, int k) {
    int maxTotalValue = 0;


    return maxTotalValue;
}

int lastItem(int i, int k) {
    int index = 0; // index of the last item used in a knapsack


    return index;
}

unsigned int knapsackDP(unsigned int values[], unsigned int weights[],
unsigned int n, unsigned int maxWeight, bool usedItems[]) {
    // k: max weight of the kanpsack

    int maxValue[100][101]; // Tabela

    // Step 1: Initialize DP table (2D matrix) (MaxValue table) - using Base Cases
    // * Base: i = 0 (no itens)
    for (unsigned int k = 0; k <= maxWeight; k++) {
        if (k >= weights[0]) maxValue[0][k] = values[k];
        else maxValue[0][k] = 0;
    }
    // * Base: k = 0 (no capacity)
    for (unsigned int i = 0; i <= n; i++) {

    }

    // Step 2: Compute the DP table using 'maxValue(i, k)' function of a) - Recursion cases
    // Checking all itens
    for (unsigned int i = 0; i <= n; i++) {
        for (unsigned int k = 0; k <= maxWeight; k++) { // colunms
            if (weights[i] > k) maxValue[i][k] = maxValue[i - 1][k]; // no addition; too heavy
            else { // value increase: addition
                int aux = values[i] + maxValue[i - 1][k - weights[i]];
                if (aux > maxValue[i - 1][k]) maxValue[i][k] = aux;
            }
        }

    }

    // Step 3: Building the solution
    // * Initial: no items inside the knapsack
    for (int i = 0; i < n; i++) {
        usedItems[i] = false; // nothing was added
    }
    unsigned int remainingWeight = maxWeight; // all capacity available

    // * What we have: maxValue table >> from last item to the first
    for (unsigned int i = n - 1; i > 0; i--) {
        if (remainingWeight == 0) break; // knapsack full: no more items; end
        // else: keep looking for the items inside it
        if (maxValue[i][remainingWeight] != maxValue[i - 1][remainingWeight]) {
            // changes in the table = item added
            usedItems[i] = true;
            remainingWeight -= weights[i];
        }
        // check the last item: item 0 = zero item
        if (remainingWeight > 0) usedItems[0] = true; // some space left
    }

    // Solution
    return maxValue[n - 1][maxWeight];
}

int main () {
    unsigned int values = [10, 7, 11, 15];
    unsigned int weights = [1, 2, 1, 3];
    unsigned int n = 4;
    unsigned int maxWeight = 5;


    return 0;
}