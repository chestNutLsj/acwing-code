// 22调剂题3——总k次方差（hard）
// https://www.luogu.com.cn/problem/U414204
#include <iostream>

using namespace std;
using ULL = unsigned long long;

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
int       a[N]; // 存放数组

ULL quic_power(int m, int k, int p) { // m^k mod p
    ULL res = 1 % p, t = m;
    while (k) {
        if (k & 1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

int main() {
    n = rd(), k = rd();
    for (int i = 1; i <= n; i++)
        a[i] = rd();

    ULL ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int power = quic_power(abs(a[i] - a[j]), k, MOD);
            ans       = (ans + power) % MOD;
        }
    cout << ans % MOD << endl;
    return 0;
}