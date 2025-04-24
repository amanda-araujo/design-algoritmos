//
// Created by Amanda on 23/04/2025.
//
#include <iostream>
using namespace std;

// Implement knapsackBT using a strategy based on backtracking >> Busca em Profundidade
unsigned int knapsackRec(unsigned int values[], unsigned int weights[],
unsigned int n, unsigned int maxWeight, unsigned int curIndex, unsigned int curValue, bool curItens[], unsigned int& maxValue, bool usedItems[]) {
  // maxValue: reference

  // All itens have been tested in actual branch?
  if (curIndex == n) {
    // Did we find a better solution?
    if(curValue > maxValue) {
      maxValue = curValue; // update value in the knapsack
      for (int i = 0; i < n; i++) usedItens[i] = curItens[i];// udate itens in the knapsack
    }
  }

  // Recursive cases
  else {
    // Try to include actual item
    if (maxWeight >= weigths[curIndex]) {
      curItens[curIndex] = true; // Fits the new object

      // what about updating curIndex++?
      knapsackRec(values, weights, n, maxWeight - weights[curIndex], curValue + values[curIndex]);

    }
  }

}

unsigned int knapsackBT(unsigned int values[], unsigned int weights[],
unsigned int n, unsigned int maxWeight, bool usedItems[]) {

  unsigned int maxValue = 0;
  bool curItens[10000]; //1 or 0
  for (unsigned int i = 0; i < n; i++) {
    curItens[i] = false; // Nothing in the knapsack

    // Find possible solutions using BackTracking
    knapsackBT(values, weigths, n, maxWeight, 0, 0, curItens, maxValue, usedItens);
    }
    return maxValue;
}



int main () {
  return 0;
}

