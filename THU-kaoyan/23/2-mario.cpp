// mario佬的答案
// unordered_map版本
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1000010;

int rd() {
    int  k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? k : -k;
}

void wr(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar((x % 10) ^ '0');
}

struct edge {
    int to, nxt;
} e[N << 1];

int                     head[N], ecnt;
unordered_map<int, int> mp;
int                     a[N], cnt[N], ans[N], type_cnt, res;

void add_edge(int u, int v) {
    e[++ecnt].to = v, e[ecnt].nxt = head[u], head[u] = ecnt;
}

void dfs(int u, int fa) {
    if (!cnt[a[u]]) ++res;
    ++cnt[a[u]];
    ans[u] = res;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v ^ fa) dfs(v, u);
    }
    --cnt[a[u]];
    if (!cnt[a[u]]) --res;
}

int main() {
    int n;
    n = rd();
    for (int i = 1; i < n; i++) {
        int u = rd(), v = rd();
        add_edge(u, v), add_edge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        a[i] = rd();
        if (!mp.count(a[i])) mp[a[i]] = ++type_cnt;
        a[i] = mp[a[i]];
    }
    dfs(n, 0);
    for (int i = 1; i <= n; ++i, putchar(i > n ? '\n' : ' ')) wr(ans[i]);
}