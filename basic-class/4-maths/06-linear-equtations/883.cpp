// 高斯消元法解线性方程组
#include <cmath>
#include <iostream>

using namespace std;

const int N = 110;
int       n;
double    a[N][N]; // augmented matrix
double    eps = 1e-4;

int gauss() {
    int col, row;
    for (col = 0, row = 0; col < n; col++) {
        int t = row;
        for (int i = row; i < n; i++) // 找到绝对值最大的行
            if (fabs(a[i][col]) > fabs(a[t][col]))
                t = i;

        if (fabs(a[t][col]) < eps) continue;

        for (int i = col; i <= n; i++) swap(a[t][i], a[row][i]); // 将绝对值最大的行换到最顶端
        for (int i = n; i >= col; i--) a[row][i] /= a[row][col]; // 将当前行的首位变成1
        for (int i = row + 1; i < n; i++)                        // 用当前行将下面所有的列消成0
            if (fabs(a[i][col]) > eps)
                for (int j = n; j >= col; j--)
                    a[i][j] -= a[row][j] * a[i][col];

        row++;
    }

    if (row < n) {
        for (int i = row; i < n; i++)
            if (fabs(a[i][n]) > eps)
                return 2; // 无解
        return 1;         // 有无穷多组解
    }

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            a[i][n] -= a[i][j] * a[j][n];

    return 0; // 有唯一解
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            cin >> a[i][j];

    int res = gauss();
    if (res == 0) {
        for (int i = 0; i < n; i++)
            printf("%.2f\n", a[i][n]);

    } else if (res == 1)
        cout << "Infinite group solutions" << endl;
    else if (res == 2)
        cout << "No solution" << endl;
}