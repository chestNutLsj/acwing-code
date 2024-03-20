// 23真题1 —— 公司
// 记录一个OI佬的代码
#include <cstdio>
#define MAXN 100010
int       a[MAXN], v[MAXN];
long long u[MAXN];
int       main() {
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    while (m--) scanf("%d%d", &x, &y), u[x] += a[y], ++v[x];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (v[i] && u[i] > 1ll * a[i] * v[i]) ++ans;
    printf("%d\n", ans);
}