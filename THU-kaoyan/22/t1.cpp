// 22调剂题1——总k次方差(easy)
// https://www.luogu.com.cn/problem/U414204
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
using LL = long long;

int rd() {
    int  k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? k : -k;
}

void wr(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar((x % 10) ^ '0');
}

const int N = 1e5 + 10, MOD = 998244353;
int       n, k; // n个数，k次方差
LL        a[N]; // 存放数组

int main() {
    n = rd(), k = rd(); // easy版的题目中k恒为1，因此只需要优化差的绝对值的总和即可
    for (int i = 1; i <= n; i++)
        a[i] = rd();

    stable_sort(a + 1, a + n + 1);

    // LL ans = 0;
    // for (int i = 1; i <= n; i++)
    //     for (int j = i + 1; j <= n; j++)
    //         ans = (ans + abs(a[i] - a[j])) % MOD;

    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + a[i] * (1ll * (i - 1)) - a[i] * (1ll * (n - i))) % MOD;
        ans = (ans + MOD) % MOD; // 确保结果为正
    }

    cout << (ans * 2) % MOD << endl; // 输出结果

    return 0;
}