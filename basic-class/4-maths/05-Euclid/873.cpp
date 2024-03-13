// Extend GCD
#include <iostream>

using namespace std;

const int N = 100010;
int       n;

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
    cin >> n;
    int x = 5, y = 4;
    while (n--) {
        int a, b;
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << " " << y << endl;
    }
    return 0;
}