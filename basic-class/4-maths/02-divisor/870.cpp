#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;

const int N = 110;
int       n, arr[N];
const int mod = 7 + 1e9;

// 对x进行质因数分解，并统计每个质因数的次数
unordered_map<LL, int> prime_factors(LL x) {
    unordered_map<LL, int> factors;
    for (LL i = 2; i <= x / i; i++) {
        while (x % i == 0) {
            factors[i]++;
            x /= i;
        }
    }
    if (x > 1) factors[x]++;
    return factors;
}

// 计算约数的数量
LL sum_of_divisors(const unordered_map<LL, int> &factors) {
    LL ans = 1;
    for (auto &[prime, exp] : factors) {
        ans = ans * (exp + 1) % mod;
    }
    return ans;
}

int main() {
    cin >> n;
    unordered_map<LL, int> total_factors;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        auto factors = prime_factors(arr[i]);
        for (auto &[prime, exp] : factors) {
            total_factors[prime] += exp;
        }
    }
    cout << sum_of_divisors(total_factors) % mod;
    return 0;
}
