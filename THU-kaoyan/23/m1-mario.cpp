// Mario佬的答案
#include <iostream>

using namespace std;
using LL = long long;

const int N        = 1000000;
const LL  mod      = 10000000000ll;
const LL  overflow = 10000000000000000ll;

LL f[N + 10];

LL add(LL a, LL b) { return (a + b >= mod) ? (a + b - mod) : (a + b); }

LL sub(LL a, LL b) { return (a >= b) ? (a - b) : (a + mod - b); }

LL mul(LL a, LL b) { return a * b % mod; }

int main() {
    f[1] = 3, f[2] = 9, f[3] = 24;
    for (int i = 4; i <= 37; i++)
        f[i] = 3ll * f[i - 1] - 2ll * f[i - 3];
    f[37] %= mod;
    for (int i = 38; i <= N; i++)
        f[i] = sub(mul(3, f[i - 1]), mul(2, f[i - 3]));

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n <= 36)
            cout << f[n] << endl;
        else
            cout << "......" << f[n] << endl;
    }
}