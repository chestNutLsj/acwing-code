// 满足条件的01序列
#include <iostream>
using namespace std;
// 给定 n个 0和 n个 1 满足任意前缀序列中 0的个数都不少于 1的个数
// 例如 111 000 1.000111 2.001101 3.001011 4.010011 5.010101
// 实际上可以通过画表格的方式求解 1代表向上走 0代表向右走 从(0, 0)到(6, 6)共有C12 6种走法
// 其中要满足题意那么所有路线都必须在(1, 0)到(5, 6)这条直线以下
// 也就是所有路线数量 - 经过(1, 0)到(5, 6)这条直线路线数量
// 将第一次经过(1, 0)到(5, 6)这条直线的点以后的路线做这条直线的轴对称 其终点变为(5, 7) 即所有不满足条件的路线都会到(5, 7)
// 那么就将原题转换为求(0, 0)到(5, 7)的路线个数 C12 5 满足题意的点为 C12 6 - C12 5
// 由以上可以推出2n条路线满足题意的路线有C2n n - C2n n-1条化简成C2n n / n + 1 这个数也称为卡特兰数
typedef long long LL;

const int N = 100010, mod = 1e9 + 7;
// 利用快速幂计算模mod后a的逆元(因为mod为质数 可以利用费马小定理计算逆元)
int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = ( LL ) res * a % mod;
        a = ( LL ) a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(void) {
    int n;
    cin >> n;

    int a = 2 * n, b = n;
    int x = 1, y = 1;
    // 计算(a - b)! 和 b!
    for (int i = 0; i < b; i++) {
        x = ( LL ) x * (a - i) % mod;
        y = ( LL ) y * (i + 1) % mod;
    }
    // 最终结果为Ca b / n + 1  =>  (a - b)! * b!^-1 * (n + 1)^-1
    int res = ( LL ) x * qmi(y, mod - 2, mod) % mod * qmi(n + 1, mod - 2, mod) % mod;

    cout << res;
}