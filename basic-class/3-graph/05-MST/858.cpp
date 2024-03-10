// Prim
#include <iostream>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int       n, m;
int       g[N][N];
int       dist[N]; // 存储当前节点到MST的距离
bool      st[N];   // 标记每个点是否已在MST中

void init() {
    fill(g[0], g[0] + N * N, INF);
    fill(dist, dist + N, INF);
    fill(st, st + N, false);
    dist[1] = 0;
}

int prim() { // 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
    int res = 0;
    for (int i = 0; i < n; i++) { // 找到集合外距离最近的点
        int t = -1;
        for (int j = 1; j <= n; j++) // 用t更新其它各点到集合的距离
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        if (i && dist[t] == INF) return INF; // 距离是正无穷
        if (i) res += dist[t];
        st[t] = true; // 将点加入到集合中去
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main() {
    cin >> n >> m;
    init();
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }
    int res = prim();
    res > INF / 2 ? cout << "impossible" : cout << res;
    return 0;
}