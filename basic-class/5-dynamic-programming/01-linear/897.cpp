// 最长公共子序列
#include <iostream>
using namespace std;

const int N = 1010;
int       f[N][N]; // f[i][j]记录所有在第一个序列的前i个字母中出现，且在第二个序列的前j个字母中出现的子序列
char      A[N], B[N];

/*

  (a)  c  (b  c)
  (a   b)  e  d  (c)

*/

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= m; i++) cin >> B[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (A[i] == B[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    /*

    f[i][j] 状态计算理解：（√ 表示选，× 表示不选）
    - 00：a[i] × b[j] ×
    - 01：a[i] × b[j] √
    - 10：a[i] √ b[j] ×
    - 11：a[i] √ b[j] √

    1. 单独考虑 11：if (a[i] == b[j]) f[i - 1][j - 1] + 1
    2. 考虑组合 00 && 01：a[i] × b[j] √/×（可选可不选） f[i - 1][j]
    3. 考虑组合 00 && 10：a[i] √/×（可选可不选）b[j] × f[i][j - 1]

    */

    cout << f[n][m] << endl;
}
