// 石子合并
#include <iostream>

using namespace std;

const int N = 310, INF = 1e9;
int       f[N][N]; // f[i][j] 表示所有将第i堆石子到第j堆石子进行合并的最小代价
int       w[N];    // 记录石子的重量
int       s[N];    // 记录石子重量的前缀和

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        s[i] = s[i - 1] + w[i];
    }
    // 初始化DP数组为INF
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = (i == j) ? 0 : INF;

    // 区间DP计算
    for (int len = 2; len <= n; len++) {         // 枚举区间长度
        for (int i = 1; i + len - 1 <= n; i++) { // 枚举起点
            int j = i + len - 1;                 // 计算终点
            for (int k = i; k < j; k++)          // 枚举分割点
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
        }
    }

    cout << f[1][n] << endl;

    return 0;
}