// 最长上升子序列
#include <iostream>
using namespace std;

const int N = 1010;
int       f[N]; // f[i] 表示所有以第i个数结尾的（严格）上升子序列
int       a[N]; // 记录输入序列
/*

3  1  2  1  8  5  6
   ----        ----  故最长上升子序列的长度为4
*/

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        f[i] = 1; // 只有a[i]一个数
        for (int j = 1; j < i; j++)
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, f[i]);
    cout << res << endl;
}