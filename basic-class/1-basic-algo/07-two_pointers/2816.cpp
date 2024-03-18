// 判断子序列
#include <iostream>

using namespace std;

const int N = 100010;

int A[N], B[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    int i = 0, j = 0, matchs = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            i++;
            j++;
            matchs++;
        } else {
            j++;
        }
    }
    if (matchs == n) {
        cout << "Yes";
    } else
        cout << "No";

    return 0;
}