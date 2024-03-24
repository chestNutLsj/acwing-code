// 22调剂题3——总k次方差（hard）
// https://www.luogu.com.cn/problem/U414232
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

LL quic_power(LL m, LL k, LL p) { // m^k mod p
    LL res = 1 % p, t = m;
    while (k) {
        if (k & 1ll) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

int main() {
    n = rd(), k = rd();
    for (int i = 1; i <= n; i++)
        a[i] = rd();

    LL ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            LL power = quic_power(1ll * abs(a[i] - a[j]), 1ll * k, 1ll * MOD);
            ans      = (ans + power) % (1ll * MOD);
        }
    cout << 1ll * ans % MOD << endl;
    return 0;
}