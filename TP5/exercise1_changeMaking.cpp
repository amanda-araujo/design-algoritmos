//
// Created by up202411286 on 09-04-2025.
//

// Change-making problem
// You can assume that the coin denominations are ordered by increasing value in C;
// Implement changeMakingDP using a strategy based on dynamic programming.

bool changeMakingDP(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T,
    unsigned int usedCoins[]) {

    unsigned int minCoins[10][11][1001]; //[coin ci][stock ci][total value]
    unsigned int lastCoin[10][11][1001]; //[coin ci][stock ci][total value]

    // OBS: First position: biggest value coin
    // Limited amount of coins for each stock
    // Assume that the coin denominations are ordered by increasing value in C
    // C: tipos de moeda que existem (e.g. euro != real)
    // Considere que podem haver vários sistemas de moedas
    // Ex: 7, 2 e 0,01; Troco de 10: 7 + 300 * 0,01 (301 moedas) versus 2 * 5 (5 moedas)
    // Aqui não é mais Greedy, mas sim Programação Dinâmica!

    // Base Cases
    for (int i = 0; i < n; i++) { // for each coin
        for (int s = 0; s <= Stock[i]; s++) {
            minCoins[i][s][0] = 0;
            for (int t = 1; t <= T; t++) {
                minCoins[i][s][t] = T + 1; // not a problem; we only consider until T
            }
        }
    }

    // Fisrt Coin
    for (int s = 1; s <= Stock[0]; s++) {
        for (int t = C[0]; t <= T; t++) {
            if (t % C[0] == 0 and t / C[0] <= s) {
                minCoins[0][s][t] = t / C[0];
                lastCoin[0][s][t] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        // NO stock of the coin s = 0 >> solucoes anteriores
        for (int t = 1; t <= T; t++) {
            // if not stock, do that:
            minCoins[i][0][t] = minCoins[i - 1][Stock[i - 1]][t];
            lastCoin[i][0][t] = lastCoin[i - 1][Stock[i - 1]][t];
        }

        // Tem stock e moeda cabe no valor que precisa s > 0
        for (int s = 1; s <= Stock[i]; s++) {
            for (int t = 1; t <= T; t++) {
                if (t >= C[i]) {
                    // Check if adding the new coin is the best option
                    // compare with previous minCoins
                    if (minCoins[i][s - 1][t - C[i]] < minCoins[i - 1][Stock[i - 1]][t]) {
                        minCoins[i][s][t] = 1 + minCoins[i][s - 1][t - C[i]];
                        lastCoin[i][s][t] = i;
                    }
                    else { // t < tipo da moeda; n dá pra usar essa moeda
                        minCoins[i][s][t] = minCoins[i - 1][Stock[i - 1]][t];
                        lastCoin[i][s][t] = lastCoin[i - 1][Stock[i - 1]][t];
                    }
                }
                else {
                    minCoins[i][s][t] = minCoins[i - 1][Stock[i - 1]][t];
                    lastCoin[i][s][t] = lastCoin[i - 1][Stock[i - 1]][t];
                }
            }
        }
    }

    // Solution: Building the solution
    // remaining T; verificando last coins
    for (int i = 0; i < n; i++) {
        usedCoins[i] = false; // nothing was added
    }
    unsigned int remainingT = T; // all amount available

    // * What we have: minCoin | lastCoin >> from last item to the first
    // return: returns a boolean indicating whether or not the problem has a solution
    // If so, it set the usedCoins array with the total number of coins used for each
    // denomination C >>> from lastCoin to the first
         // // * What we have: maxValue table >> from last item to the first
     for (unsigned int i = n - 1; i > 0; i--) { // para cada moeda
         for (unsigned int s = Stock[i]; s > 0; s--) { // para cada moeda do stock
             if (remainingT == 0) break; // AMOUNT full; end
             // else: keep looking for the items inside it
             // opa: campo extra: stock! s
             if (minCoins[i][s][remainingT] != minCoins[i - 1][s][remainingT]) {
                 // changes in the table = item added
                 usedCoins[i] = true;
                 remainingT -= C[i];
             }
             // check the last item: item 0 = zero item
             if (remainingT > 0) usedCoins[0] = true; // some space left
         }
     }

     // // Solution
     // return true; //sol: minCoins[n - 1][][T];
     //  */
    return false;
}

/* The change-making problem is the problem of representing a target amount of money, T, with the
fewest number of coins possible from a given set of coins, C, with n possible denominations
(monetary value). Consider the function changeMaking below, which considers a limited stock of
coins of each denomination Ci, in Stock, respectively.

bool changeMakingBF(unsigned int C[], unsigned int Stock[],
unsigned int n, unsigned int T, unsigned int usedCoins[])

The arguments C and Stock are arrays of size n, and T is the target amount for the change. The
function returns a boolean indicating whether the problem has a solution. If so, it set the
usedCoins array with the total number of coins used for each denomination Ci.

Input example: C = [1, 2, 5, 10], Stock = [3, 5, 2, 1], n =4, T = 8
Expected result: [1, 1, 1, 0]
Input example: C = [1, 2, 5, 10], Stock = [1, 2, 4, 2], n =4, T = 38
Expected result: [1, 1, 3, 2]
 *
 *  // Base Cases
 *     NO value: T = 0
 *     NO coins
 */