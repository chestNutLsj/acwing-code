#include <iostream>

using namespace std;

typedef long long LL; // 数据范围比较大,所以用LL来存储

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    LL  a1, m1;
    cin >> n >> a1 >> m1;
    LL x = 0;
    for (int i = 1; i < n; i++) {
        LL a2, m2;
        cin >> a2 >> m2;
        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d) {
            x = -1;
            break;
        }
        k1 *= (m2 - m1) / d;
        // 因为此时k1是k1*a1+k2*a2=d的解,所以要乘上(m2-m1)/d的倍数大小
        LL t = abs(a2 / d);
        k1   = (k1 % t + t) % t;
        // 数据比较极端,所以只求k的最小正整数解
        m1 = k1 * a1 + m1;
        // m1在被赋值之后的值为当前"x"的值，此时赋值是为了方便下一轮的继续使用
        a1 = abs(a1 * a2 / d);
        // 循环结束时a1的值为当前所有的a1,a2,……an中的最小公倍数
    }
    if (x != -1)
        x = (m1 % a1 + a1) % a1;
    // 当循环结束时，此时的值应该与最小公倍数取模,以求得最小正整数解
    printf("%lld\n", x);
    return 0;
}