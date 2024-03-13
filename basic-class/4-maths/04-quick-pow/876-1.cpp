#include <iostream>
using namespace std;
typedef long long LL;

int n;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    cin >> n;
    while (n--) {
        int a, p, x, y;
        // if (a < p) swap(a, p);
        cin >> a >> p;
        int d = exgcd(a, p, x, y);
        if (d == 1)
            cout << (( LL ) x + p) % p << endl; // 保证x是正数
        else
            puts("impossible");
    }
    return 0;
}