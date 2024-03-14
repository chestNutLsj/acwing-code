// full-knapsack
#include <iostream>

using namespace std;

const int N = 1010;
int       f[N][N];    // f[i][j] 表示前i件物品在总体积是j的情况下，最大的总价值
int       v[N], w[N]; // 记录每个物品的体积和价值

int main() {
    int num, vol;
    cin >> num >> vol;
    for (int i = 1; i <= num; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= num; i++)
        for (int j = 0; j <= vol; j++)
            if (v[i] <= j) // 第 i 种能放进去
                f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);
            else // 如果第 i 件物品不能放进去
                f[i][j] = f[i - 1][j];

    cout << f[num][vol] << endl;

    return 0;
}