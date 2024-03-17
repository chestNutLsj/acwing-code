// 最短编辑距离
#include <iostream>
using namespace std;

const int N = 1010;
int       f[N][N]; // f[i][j]记录从前一个序列的前i个字符转换为第二个序列的前j个字符所需要的最少操作次数
char      A[N], B[N];
int       n, m;

/*
     AA T G    增、改操作共4次
  AGTCTG ACGC
  AGTAAGTAGGC
*/

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> B[i];

    //* 另一些更简洁的输入方法
    // scanf("%d%s", &n, A + 1); // 输入字符串A
    // scanf("%d%s", &m, B + 1); // 输入字符串B
    //
    // cin >> n >> a + 1 >> m >> b + 1; (这个也可以)

    // 初始化操作数的边界情况
    for (int i = 0; i <= m; i++) f[0][i] = i; // 从空字符串变到B的前i个字符需要i次插入操作
    for (int i = 0; i <= n; i++) f[i][0] = i; // 从A的前i个字符串变为空字符串需要i次删除操作
    // for (int i = 1; i <= max(n, m); i ++) f[0][i] = f[i][0] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1); // 分别对应删除A的一个字符或在A中插入B的一个字符
            if (A[i] == B[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]); // 如果当前字符相同，则不需要额外操作
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1); // 否则进行替换
        }

    cout << f[n][m] << endl;

    return 0;
}
