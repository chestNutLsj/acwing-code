// 整数划分
#include <iostream>

using namespace std;

const int N = 1010, mod = 1e9 + 7;
int       f[N][N]; // f[i][j] 表示只从1~i中选取，且总和等于j的方案数

int main() {
    int n;
    cin >> n;

    // 初始化：没有整数组成总和为0的方案数为1
    for (int i = 0; i <= n; i++) {
        f[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 如果当前整数i可以放入总和为j的方案中
            if (j >= i) {
                // 方案可以是不使用i的方案数f[i-1][j]，加上使用i时的方案数f[i][j-i]
                f[i][j] = (f[i - 1][j] + f[i][j - i]) % mod;
            } else {
                // 如果i太大，不能放入总和为j的方案，方案数与上一个整数i-1时相同
                f[i][j] = f[i - 1][j];
            }
        }
    }

    cout << f[n][n];
    return 0;
}