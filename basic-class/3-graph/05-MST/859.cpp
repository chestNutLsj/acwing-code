// Kruskal
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010, M = 2 * N, INF = 0x3f3f3f3f;
int       n, m;
int       fa[N]; // 并查集的父节点数组
struct Edge {
    int  a, b, w;
    bool operator<(const Edge &W) const {
        return w < W.w;
    }
} edges[M];

int find(int x) {
    if (fa[x] == x)
        return x;
    else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void init() {
    for (int i = 1; i <= n; i++) fa[i] = i; // 初始化并查集的父节点数组
}

int kruskal() {
    sort(edges, edges + m);
    init();
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            fa[a] = b;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1) return INF; // 说明树不连通
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    int res = kruskal();
    res > INF / 2 ? cout << "impossible" : cout << res;

    return 0;
}