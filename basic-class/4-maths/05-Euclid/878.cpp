// 线性同余方程
#include <iostream>

using namespace std;

const int N = 100010;

// 求x, y，使得ax + by = gcd(a, b)
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, m, x, y;
        cin >> a >> b >> m;
        int ans = exgcd(a, m, x, y);
        if (b % ans != 0)
            cout << "impossible" << endl;
        else {
            x = ( long long ) x * (b / ans) % m;
            cout << x << endl;
        }
    }
    return 0;
}