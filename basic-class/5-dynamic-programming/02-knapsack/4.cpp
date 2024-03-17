// 多重背包问题I
#include <iostream>

using namespace std;

const int N = 110;
int       f[N][N];          // f[i][j] 表示前i件物品在总体积是j的情况下，最大的总价值
int       v[N], w[N], s[N]; // 记录每个物品的体积、价值、数量

int main() {
    int num, vol;
    cin >> num >> vol;
    for (int i = 1; i <= num; i++)
        cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= num; i++)
        for (int j = 0; j <= vol; j++)
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);

    cout << f[num][vol] << endl;

    return 0;
}