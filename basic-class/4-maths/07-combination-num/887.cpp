// Lucas定理
#include <iostream>
using namespace std;
typedef long long LL;

LL quick_pow(LL base, LL power, LL p) {
    LL result = 1;
    while (power) {
        if (power & 1) result = result * base % p;
        base = base * base % p;
        power >>= 1;
    }
    return result;
}

LL C(LL n, LL m, LL p) {
    if (n < m) return 0;
    LL x = 1, y = 1;
    for (int i = n, j = 1; j <= m; i--, j++) {
        x = x * i % p;
        y = y * j % p;
    }
    return x * quick_pow(y, p - 2, p) % p;
}

LL lucas(LL n, LL m, LL p) {
    if (n < p && m < p) return C(n, m, p);
    return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        LL n, m, p;
        cin >> n >> m >> p;
        cout << lucas(n, m, p) << endl;
    }
    return 0;
}
