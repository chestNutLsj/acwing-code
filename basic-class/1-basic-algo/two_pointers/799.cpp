// 最长连续不重复子序列
#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 100010;

int main() {
    int n;
    cin >> n;
    int arr[N];
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_set<int> seen;
    int l = 0, r = 0, cnts = 0, max_length = 0;

    while (r < n) {
        if (seen.find(arr[r]) == seen.end()) {
            seen.insert(arr[r]);
            cnts       = r - l + 1; // Update the length of current subsequence
            max_length = max(max_length, cnts);
            r++;
        } else {
            seen.erase(arr[l]); // Remove element at left pointer
            l++;
        }
    }

    cout << max_length << endl;
}