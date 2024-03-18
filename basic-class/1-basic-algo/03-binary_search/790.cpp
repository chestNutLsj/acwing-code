// 数的三次方根
#include <iomanip>
#include <iostream>

using namespace std;

const double eps = 1e-8;

double cubic_root(double x) {
    double l, r;
    if (x == 0.000000) {
        return 0.000000;
    } else if (x > 0) {
        l = 0.000000, r = x + 1;
        while (r - l > eps) {
            double mid = (l + r) / 2;
            if (mid * mid * mid > x)
                r = mid;
            else
                l = mid;
        }
    } else {
        l = x - 1, r = -0.000000;
        while (r - l > eps) {
            double mid = (l + r) / 2;
            if (mid * mid * mid > x)
                r = mid;
            else
                l = mid;
        }
    }
    return l;
}

int main() {
    double n;
    cin >> n;

    double res = cubic_root(n);
    // printf("%.6f", res);
    cout << fixed << setprecision(6) << res;

    return 0;
}