// Euler Table
// 欧拉函数
#include <iostream>

using namespace std;
typedef long long LL;

const LL M = 1e6 + 10;
LL       arr[M], n;
LL       primes[M], cnt; // primes[]存储所有素数
LL       euler[M];       // 存储每个数的欧拉函数
bool     st[M];          // st[x]存储x是否被筛掉

void get_eulers(LL n) {
    euler[1] = 1;
    for (LL i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            euler[i]      = i - 1;
        }
        for (LL j = 0; primes[j] <= n / i; j++) {
            LL t  = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0) {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}

int main() {
    cin >> n;
    get_eulers(n);
    LL sum = 0;
    for (LL i = 1; i <= n; i++) {
        sum += euler[i];
    }
    cout << sum;

    return 0;
}