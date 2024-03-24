#include <algorithm>
#include <cstdio>
using namespace std;

unsigned long long f[1000001][3][2];
void               calc(int n) {
    long long ret = 0;
    for (int j = 0; j < 3; ++j) ret += f[n][j][0] + f[n][j][1];
    if (n >= 37)
        printf("......%010lld\n", ret % 10000000000ll);
    else
        printf("%lld\n", ret);
}
int main() {
    f[1][0][0] = f[1][1][0] = f[1][2][0] = 1;
    for (int i = 2; i <= 1000000; ++i)
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k)
                if (j != k) f[i][j][0] = (f[i][j][0] + f[i - 1][k][0] + f[i - 1][k][1]) % 100000000000000000ll;
            f[i][j][1] = f[i - 1][j][0];
        }
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        calc(n);
    }
}