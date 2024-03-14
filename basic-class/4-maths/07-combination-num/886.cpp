// 预处理逆元法求组合数
#include <iostream>
using namespace std;
typedef long long LL;

const int N   = 100010; // 根据问题需求调整N的大小
const int mod = 1e9 + 7;

LL fact[N], infact[N];

LL quick_pow(LL base, LL power) {
    LL result = 1;
    while (power) {
        if (power & 1) result = result * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return result;
}

// 预处理阶乘的余数和阶乘逆元的余数
void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i]   = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * quick_pow(i, mod - 2) % mod;
    }
}

LL combination_num(LL n, LL m) {
    if (m > n) return 0;
    return fact[n] * infact[m] % mod * infact[n - m] % mod;
}

int main() {
    init(); // 预处理阶乘及其逆元
    int t;
    cin >> t;
    while (t--) {
        LL n, m;
        cin >> n >> m;
        cout << combination_num(n, m) << endl;
    }
    return 0;
}
