#include <iostream>
using namespace std;
void swap(int &a, int &b) {
int temp = a;
a = b;
b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int too_big_index = low - 1;
  int too_small_index = high;
  while (true) {
    do {
    ++too_big_index;
    } while (arr[too_big_index] <= pivot && too_big_index < high);
    do {
    --too_small_index;
    } while (arr[too_small_index] > pivot && too_small_index > low);
    if (too_big_index < too_small_index) {
        swap(arr[too_big_index], arr[too_small_index]);
    }
    else {
      swap(arr[too_big_index], arr[high]);
      return too_big_index;
    }  
  }
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
  cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Unsorted array: " << endl;
  printArray(arr, n);
  quickSort(arr, 0, n - 1);
  cout << "Sorted array: " << endl;
  printArray(arr, n);
  return 0;
}
