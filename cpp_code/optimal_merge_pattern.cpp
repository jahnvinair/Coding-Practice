#include <iostream>
#include <climits>

int optimalMergeCost(int files[], int n) {
    int totalCost = 0;

    // Repeat until only one file remains
    for (int i = 1; i < n; i++) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int index1 = -1, index2 = -1;

        // Find the smallest file
        for (int j = 0; j < n; j++) {
            if (files[j] != -1 && files[j] < min1) {
                min2 = min1;
                index2 = index1;
                min1 = files[j];
                index1 = j;
            } else if (files[j] != -1 && files[j] < min2) {
                min2 = files[j];
                index2 = j;
            }
        }

        // Merge the two smallest files
        int mergeCost = min1 + min2;
        totalCost += mergeCost;

        // Mark the first file as merged (used) and store the merged size in the second
        files[index1] = -1;
        files[index2] = mergeCost;
    }

    return totalCost;
}

int main() {
    int files[] = {4, 3, 2, 6}; // example file sizes
    int n = sizeof(files) / sizeof(files[0]);
    int result = optimalMergeCost(files, n);
    std::cout << "Minimum cost for optimal merge pattern: " << result << std::endl;

    return 0;
}
