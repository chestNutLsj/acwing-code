// 能被整除的数
/*  容斥原理通过集合的角度来进行表示
    例：其中一个集合S_i可以表示为 1~n 中能被p_i 整除的数的个数，那么这个数量就是 n / p_i(p_i的倍数不超过n就是)
    当两个集合相交是表示可以被这两个集合同时整除，这里设置一个临时变量t表示这些表示集合的质数的乘积，n / t的数量就是可以同时整除这多个质数的数量
    其中1~n能被任意一个质数整除即可它的个数可以表示S_1 U S_2 U …… U S_m 就是这些集合维恩图组成的面积
    即可求解
    时间复杂度为m * 2 ^ m
*/
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long LL;

const int N = 20;

int n, m;
int primes[N];

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) scanf("%d", &primes[i]);

    int res = 0;
    for (int i = 1; i < 1 << m; i++) {
        int cnt = 0, t = 1; // 其中cnt表示有多少个集合，t表示可以同时整除这些相乘质数的（质数乘积）

        for (int j = 0; j < m; j++) // 因为只算一次不用进行预处理
        {
            int p = primes[j];

            if (i >> j & 1) {         // p[j]这个集合存在
                if (( LL ) t * p > n) // 这个集合表示的质数乘积超过了n就不可能存在这样的n, 呜呜, 因为p的范围爆了int 所以要用long long 处理这个运算结果
                {
                    t = -1;
                    break;
                }
                cnt++;
                t *= p;
            }
        }

        if (t != -1) // 如果这个集合合法时
        {
            if (cnt & 1)
                res += n / t; // 奇数加
            else
                res -= n / t; // 偶数减
        }
    }

    printf("%d\n", res);
    return 0;
}