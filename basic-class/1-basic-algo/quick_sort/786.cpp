#include <iostream>
using namespace std;

void quick_sort(int q[], int l, int r) {
  if (l >= r)
    return;

  int i = l - 1, j = r + 1, x = q[l + r >> 1];
  while (i < j) {
    do
      i++;
    while (q[i] < x);
    do
      j--;
    while (q[j] > x);
    if (i < j)
      swap(q[i], q[j]);
  }
  quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main() {
  int input_num, selected_num;
  cin >> input_num >> selected_num;
  int arr[input_num];
  for (int i = 0; i < input_num; i++) {
    cin >> arr[i];
  }
  quick_sort(arr, 0, input_num - 1);
  cout << arr[selected_num - 1];

  return 0;
}