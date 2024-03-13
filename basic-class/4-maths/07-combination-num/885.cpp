#include <iostream>
using namespace std;
typedef long long LL;

const int N   = 100010;
const int mod = 1e9 + 7;

LL quick_pow(LL base, LL power) {
    LL result = 1;
    while (power) {
        if (power & 1) result = result * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return result;
}

LL factorial(LL x) {
    LL result = 1;
    for (int i = 2; i <= x; i++) {
        result = result * i % mod;
    }
    return result;
}

LL combination_num(LL n, LL m) {
    if (m > n) return 0;
    LL a = factorial(n);
    LL b = factorial(m) * factorial(n - m) % mod;
    // 使用费马小定理求模逆元
    return a * quick_pow(b, mod - 2) % mod;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        LL n, m;
        cin >> n >> m;
        cout << combination_num(n, m) << endl;
    }
    return 0;
}
