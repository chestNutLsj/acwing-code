// 二维前缀和
#include <iostream>
using namespace std;

const int N = 1010;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    int arr[N][N], sum[N][N] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            sum[i][j] =
                arr[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
        }
    }
    int x1, x2, y1, y2;
    for (int i = 0; i < q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2]
                    + sum[x1 - 1][y1 - 1]
             << endl;
    }
    return 0;
}