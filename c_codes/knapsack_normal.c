#include <stdio.h>

// Structure to represent an item with value and weight
struct Item {
    int value;
    int weight;
};

// Function to swap two items
void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by value/weight ratio in decreasing order
void sortByRatio(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(struct Item items[], int n, int W) {
    sortByRatio(items, n);  // Sort items by value/weight ratio

    int currentWeight = 0;  // Current weight in the knapsack
    double finalValue = 0.0;  // Total value in the knapsack

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding the whole item doesn't exceed the capacity
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        }
        // If we can only take a fraction of the item
        else {
            int remainingWeight = W - currentWeight;
            finalValue += (double)items[i].value * remainingWeight / items[i].weight;
            break;  // Knapsack is full
        }
    }

    return finalValue;
}

int main() {
    int W = 50;  // Maximum weight of the knapsack

    // Array of items, each with a value and a weight
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);

    // Call the function to solve the problem
    double maxValue = fractionalKnapsack(items, n, W);

    // Print the maximum value we can get
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
