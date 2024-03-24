#include <algorithm>
#include <cstdio>
using namespace std;

int       n, a[100010], s;
long long ans;

int main() {
    scanf("%d%*d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i), s += a[i];
    sort(a + 1, a + n + 1);

    // 排序后动态维护前缀和
    for (int i = 1; i <= n; ++i) ans = (ans + s - (1ll * a[i] * (n - i + 1))) % 998244353, s -= a[i];
    printf("%lld\n", ans << 1);
    return 0;
}