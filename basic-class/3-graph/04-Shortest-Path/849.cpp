// Dijkstra
#include <iostream>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int       g[N][N]; // 存储图
int       dist[N]; // 存储1号点到每个点的最短距离
bool      st[N];   // 存储每个点的最短路是否已经确定
int       n, m;

void init() {
    fill(dist, dist + N, INF);
    fill(g[0], g[0] + N * N, INF);
    fill(st, st + N, 0);
    dist[1] = 0;
}

int dijkstra() {
    for (int i = 0; i < n - 1; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;

        // 用t更新其它点的距离
        for (int j = 1; j <= n; j++)
            if (g[t][j] != INF)
                dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if (dist[n] == INF) return -1;
    return dist[n];
}

int main() {
    cin >> n >> m;
    init();
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z); // 防止重边，选择最小边
    }
    cout << dijkstra();
    return 0;
}