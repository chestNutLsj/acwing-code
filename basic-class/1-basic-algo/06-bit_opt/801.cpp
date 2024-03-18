#include <iostream>

using namespace std;

const int N = 100010;

int countOnes(int x) {
    int ones = 0;
    while (0 < x) {
        ones++;
        x &= x - 1;
    }
    return ones;
}

int main() {
    int n;
    cin >> n;
    int arr[N];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cout << countOnes(arr[i]) << " ";
    return 0;
}