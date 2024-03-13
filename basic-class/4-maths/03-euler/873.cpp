// 欧拉函数
#include <iostream>

using namespace std;

const int N = 110;
int       arr[N], n;

int phi(int x) {
    int res = x;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);

    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cout << phi(arr[i]) << endl;
    }

    return 0;
}