// 01-knapsack
#include <iostream>

using namespace std;

const int N = 1010;
int       f[N][N];    // f[i][j] 表示只看前i件物品，总体积是j的情况下，最大的总价值
int       v[N], w[N]; // 记录每个物品的体积和价值

/*

result = max{f[n][0],f[n][1],f[n][2],...,f[n][V]}

计算f[i][j]:

    0. f[0][0]=0 ，最开始时只有一个合法状态;(全局变量会在堆中存储，所有元素都会初始化为0)
    1. 不选第i个物品，f[i][j]=f[i-1][j];
    2. 选第i个物品，  f[i][j]=f[i-1][j-v[i]];
    3. f[i][j]=max{(1.), (2.)}

时间复杂度：O(n*V)

*/

int main() {
    int num, vol;
    cin >> num >> vol;
    for (int i = 1; i <= num; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= num; i++)
        for (int j = 0; j <= vol; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) // 背包体积至少要大于物品体积才可以选择
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }

    int res = 0;
    for (int i = 0; i <= vol; i++) res = max(res, f[num][i]);
    cout << res << endl;

    return 0;
}