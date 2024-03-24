// 22调剂 2 —— 考试
// https://www.luogu.com.cn/problem/U414149
#include <iostream>

using namespace std;
using LL = long long;

const int N = 1e4 + 10, MOD = 7654321;
int       t, n[N]; // 代表T组数据，n次考试的输入
LL        f[N][4]; // j有CA、Net、OS、Sig可选，分别下标为0,1,2,3

/*
CA-->Net-->CA-->Net-->CA
      \          \
       \          \-->OS
        \
         \->OS-->Net-->CA
            \     \
             \     \-->OS
              \
               \->Sig-->OS

显然是DP的思路，因此设状态f[i][j]，表示第i次考试的科目为j的考试安排的可能数
，因此j有CA、Net、OS、Sig可选。
   序号:  0   1   2   3

根据规律，可以得出，f[i][0]=f[i-1][1]
                    f[i][1]=f[i-1][0]+f[i-1][2]
                    f[i][2]=f[i-1][3]+f[i-1][1]
                    f[i][3]=f[i-1][2]

题目的答案就是 ans = f[n][0]+f[n][1]+f[n][2]+f[n][3];
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    int max_n = 0;
    for (int i = 0; i < t; i++) {
        cin >> n[i], max_n = max(max_n, n[i]);
    }
    fill(f[0], f[0] + N * 4, 0ll);
    f[1][0] = 1ll;

    for (int i = 2; i <= max_n; i++) {
        f[i][0] = f[i - 1][1] % MOD;
        f[i][1] = (f[i - 1][0] + f[i - 1][2]) % MOD;
        f[i][2] = (f[i - 1][3] + f[i - 1][1]) % MOD;
        f[i][3] = f[i - 1][2] % MOD;
    }

    for (int i = 0; i < t; i++) {
        cout << (1ll * (f[n[i]][0] + f[n[i]][1] + f[n[i]][2] + f[n[i]][3])) % MOD << endl;
    }

    return 0;
}