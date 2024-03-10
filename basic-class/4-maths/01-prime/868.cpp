// 筛法求素数
#include <iostream>

using namespace std;

const int N         = 1000010;
int       primes[N] = {0}, cnt; // primes存储所有的素数，cnt记录素数的数量
bool      st[N]     = {false};  // 存储x是否被筛掉

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (st[i]) continue;
        primes[cnt++] = i;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}

int main() {
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt;
    return 0;
}