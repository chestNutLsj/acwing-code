// Quick Power
#include <iostream>

using namespace std;
typedef unsigned long long ULL;

const int N = 100010;
int       n, arr[N];

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
    cin >> n;
    while (n--) {
        int a, b, p;
        cin >> a >> b >> p;
        cout << quic_power(a, b, p) << endl;
    }
    return 0;
}