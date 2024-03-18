// 最短Hamilton路径
#include <iostream>

using namespace std;

const int N = 20, M = 1 << N, INF = 0x3f3f3f3f;
int       f[M][N]; // f[i][j] 表示访问过的顶点集合为i，且最后到达顶点j的最短路径长度
int       a[N][N]; // a[i][j] 表示i-->j之间的距离，数据保证a[i][i]==0（稠密图的邻接矩阵表示）
int       n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    // 初始化DP数组为无穷大，除了f[1][0]，表示只访问过起点0的情况，路径长度为0
    fill(f[0], f[0] + M * N, INF);
    f[1][0] = 0;

    // 遍历所有状态，i表示状态，即访问过的顶点集合
    for (int i = 1; i < 1 << n; i += 2)     // 所有方案的0号位都为1，因此递增步长为2可以避免考虑0号位为0的情况
        for (int j = 0; j < n; j++)         // 枚举最后到达的顶点j
            if (i >> j & 1)                 // 如果状态i中包含顶点j
                for (int k = 0; k < n; k++) // 枚举倒数第二个到达的顶点k
                    if (i >> k & 1)         // 如果状态i中包含顶点k
                                            // 更新状态。从状态i中去除顶点j，加上从k到j的距离
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + a[k][j]);

    // 输出从0号顶点出发，访问所有顶点恰好一次，并回到起点0的最短路径长度
    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}