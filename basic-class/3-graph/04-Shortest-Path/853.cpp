// 有边数限制的最短路
#include <iostream>
#include <string.h>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f, M = 10010;
int       n, m, k;
int       dist[N]; // 存1号点到其余所有点的距离
int       backup[N];
struct Edge {
    int a, b, w; // a--w-->b a到b的边权为w
} edges[M];

void init() {
    fill(dist, dist + N, INF);
    dist[1] = 0;
}

int bellman_ford() { // 求1号点到n号点的最短路距离，如果无法在有限边内到达，则返回-1；
    init();
    for (int i = 0; i < k; i++) { // 限制在k条边内进行松弛
        memcpy(backup, dist, sizeof(dist));
        for (int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    return dist[n];
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }

    int res = bellman_ford();
    if (res > INF / 2)
        cout << "impossible" << endl;
    else
        cout << res << endl;

    return 0;
}