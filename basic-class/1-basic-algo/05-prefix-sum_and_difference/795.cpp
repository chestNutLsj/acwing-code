// 一维前缀和
#include <iostream>

using namespace std;

const int N = 100010;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int arr[N] = {0};
    int sum[N] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    int l, r;
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}
