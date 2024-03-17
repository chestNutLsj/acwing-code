// 单调队列优化 多重背包III
#include <iostream>
using namespace std;

const int N = 1010, M = 20010;

int n, m;             // n是物品种数，m是背包容量
int v[N], w[N], s[N]; // v[i], w[i], s[i] 分别表示第i件物品的体积、价值和数量
int f[N][M];          // f[i][j] 表示考虑前i种物品，总体积为j时的最大价值
int q[M];             // 单调队列，用于优化DP过程

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; ++i) {
        for (int r = 0; r < v[i]; ++r) { // 对于每种物品，按照余数r进行分组，确保每组中物品体积之和对v[i]取余相同
            int head = 0, tail = -1;     // head是队列头指针，tail是队列尾指针
            for (int j = r; j <= m; j += v[i]) {
                // 如果队列头部的状态已经无法转移到当前状态，则出队
                while (head <= tail && j - q[head] > s[i] * v[i]) head++;
                // 如果当前状态的价值不优于队尾状态的价值，则队尾状态出队
                while (head <= tail && f[i - 1][q[tail]] + (j - q[tail]) / v[i] * w[i] <= f[i - 1][j]) --tail;
                // 当前状态入队
                q[++tail] = j;
                // 计算当前状态的最优价值
                f[i][j] = f[i - 1][q[head]] + (j - q[head]) / v[i] * w[i];
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
