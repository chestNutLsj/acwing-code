// Heap-optimized Prim
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int       n, m;
int       g[N][N];
bool      st[N]; // 标记每个点是否已在MST中

// 使用pair<int, int>表示优先队列中的元素，first是从MST到该点的最短距离，second是点的编号
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void init() {
    memset(g, 0x3f, sizeof g);
    memset(st, 0, sizeof st);
}

int prim() {
    int res = 0, cnt = 0;
    pq.push({0, 1}); // 从节点1开始
    while (!pq.empty() && cnt < n) {
        auto [d, u] = pq.top();
        pq.pop();
        if (st[u]) continue; // 如果节点u已经在MST中，则跳过
        st[u] = true;        // 标记节点u已经加入MST
        res += d;            // 将这个节点到MST的距离加到结果中
        cnt++;               // MST中的节点数+1
        for (int v = 1; v <= n; v++) {
            if (!st[v] && g[u][v] < INF) {
                pq.push({g[u][v], v}); // 将所有与u相连的、未加入MST的节点加入优先队列
            }
        }
    }
    return cnt == n ? res : INF; // 如果MST中的节点数等于总节点数，返回总权重；否则返回-1表示图不连通
}

int main() {
    cin >> n >> m;
    init();
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w); // 无向图，两个方向的权重都要更新
    }
    int res = prim();
    if (res > INF / 2)
        cout << "impossible";
    else
        cout << res;
    return 0;
}
