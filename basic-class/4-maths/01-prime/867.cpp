// 分解质因数
#include <iostream>

using namespace std;

const int N      = 110;
int       arr[N] = {0};

void divide(int x) {
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) x /= i, s++;
            cout << i << ' ' << s << endl;
        }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        divide(arr[i]);
    }
    return 0;
}