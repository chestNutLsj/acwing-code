// 递推法求组合数
#include <iostream>

using namespace std;

const int N = 100010, M = 2010;
int       c[M][M];
const int mod = 1e9 + 7;

void combination_num() {

    // c[a][b] 表示从a个苹果中选b个的方案数
    for (int i = 0; i < M; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}

int main() {
    int n;
    cin >> n;
    combination_num();
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
    return 0;
}