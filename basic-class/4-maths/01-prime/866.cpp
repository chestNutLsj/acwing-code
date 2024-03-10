// 试除法判断素数
#include <iostream>

using namespace std;
typedef long long LL;

const int N      = 110;
LL        arr[N] = {0};

bool isPrime(LL a) {
    if (a < 2) return false;
    for (LL i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        isPrime(arr[i]) ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}