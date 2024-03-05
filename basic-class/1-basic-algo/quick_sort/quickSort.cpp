#include <algorithm> // For std::swap
#include <iostream>

// Utility function to find the median of three values
int medianOfThree(int a, int b, int c) {
  if ((a < b) ^ (a < c))
    return a;
  else if ((b < a) ^ (b < c))
    return b;
  else
    return c;
}

void quickSort(int q[], int l, int r) {
  if (l >= r)
    return; // Base case

  // Middle of three method for pivot selection
  int mid = l + (r - l) / 2;
  int pivot = medianOfThree(q[l], q[mid], q[r]);

  int i = l, j = r;
  while (i <= j) {
    while (q[i] < pivot)
      i++;
    while (q[j] > pivot)
      j--;
    if (i <= j) {
      std::swap(q[i], q[j]);
      i++;
      j--;
    }
  }
  // Recursively sort the two partitions
  if (l < j)
    quickSort(q, l, j);
  if (i < r)
    quickSort(q, i, r);
}

// Example usage
int main() {
  int arr[] = {9, -3, 5, 2, 6, 8, -6, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
