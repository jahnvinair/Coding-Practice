#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // Check if the element is present at the middle
        if (arr[mid] == x)
            return mid;

        // If the element is smaller than mid, it must be in the left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Otherwise, it must be in the right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // Element is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in array" << endl;

    return 0;
}
