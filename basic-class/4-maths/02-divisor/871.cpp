#include <cmath>
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

// 快速幂算法，计算 a^b % m
LL quick_pow(LL a, LL b, LL m) {
    LL ans = 1;
    a      = a % m;
    while (b > 0) {
        if (b & 1) ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

// 计算等比数列之和：(p^(a+1) - 1) / (p - 1) % mod
LL sum_of_geometric_series(LL p, int a, LL mod) {
    LL numerator = quick_pow(p, a + 1, mod) - 1;     // 分子 p^(a+1) - 1
    if (numerator < 0) numerator += mod;             // 确保结果为正
    LL denominator = quick_pow(p - 1, mod - 2, mod); // 分母的逆元 (p-1)^(mod-2) % mod
    return numerator * denominator % mod;
}

// 计算约数的和
LL divisor_sum(const unordered_map<LL, int> &factors, LL mod) {
    LL ans = 1;
    for (auto &[prime, exp] : factors) {
        LL sum = sum_of_geometric_series(prime, exp, mod);
        ans    = ans * sum % mod;
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
    cout << divisor_sum(total_factors, mod) % mod;
    return 0;
}
