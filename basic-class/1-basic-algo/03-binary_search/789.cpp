// 数的范围

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//! Brute Force: Time Limitation Error
//
// const int N = 100010;
//
// int bin_search(int *arr, int target, int lo, int hi) { // [lo,hi)
//     while (lo < hi) {
//         int mi = lo + (hi - lo) / 2;
//         if (arr[mi] < target)
//             lo = mi + 1;
//         else if (arr[mi] > target)
//             hi = mi;
//         else
//             return mi;
//     }
//     return -1;
// }

// int main() {
//     int n, q;
//     scanf("%d %d", &n, &q);
//     int arr[N];
//     for (int i = 0; i < n; i++) { scanf("%d ", &arr[i]); }

//     int query[q];
//     int res[q];
//     for (int i = 0; i < q; i++) {
//         scanf("%d", &query[i]);
//         res[i] = bin_search(arr, query[i], 0, n);
//     }
//     for (int i = 0; i < q; i++) {
//         if (res[i] == -1)
//             printf("-1 -1\n");
//         else {
//             int l = res[i], r = res[i];
//             // printf("l=r=%d ", l);
//             while (l > 0 && arr[l - 1] == query[i]) l--;
//             while (r < n - 1 && arr[r + 1] == query[i]) r++;
//             printf("%d %d\n", l, r);
//         }
//     }
//     return 0;
// }

// Hash
int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    unordered_map<int, int> first_occurrence, last_occurrence;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (first_occurrence.find(arr[i]) == first_occurrence.end()) {
            first_occurrence[arr[i]] = i;
        }
        last_occurrence[arr[i]] = i;
    }

    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;

        if (first_occurrence.find(query) == first_occurrence.end()) {
            cout << "-1 -1\n";
        } else {
            cout << first_occurrence[query] << " " << last_occurrence[query]
                 << "\n";
        }
    }

    return 0;
}