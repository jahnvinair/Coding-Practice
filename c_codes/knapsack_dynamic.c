#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];  // Create a 2D table to store results of subproblems

    // Build the table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  // Initialize first row and first column with 0
            else if (wt[i - 1] <= w)  // If weight of item is less than or equal to w
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];  // Exclude the item
        }
    }

    // The last entry of dp[][] will contain the result, i.e., the maximum value
    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};  // Values of the items
    int wt[] = {10, 20, 30};     // Weights of the items
    int W = 50;                  // Maximum weight of the knapsack
    int n = sizeof(val) / sizeof(val[0]);  // Number of items

    // Call the knapsack function and store the result
    int maxValue = knapsack(W, wt, val, n);

    // Print the result
    printf("Maximum value in Knapsack = %d\n", maxValue);

    return 0;
}
