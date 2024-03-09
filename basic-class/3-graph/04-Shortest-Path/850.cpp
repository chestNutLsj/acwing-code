// Heap-optimized Dijkstra
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> PII; // first存储距离，second存储节点编号

const int N = 200010, INF = 0x3f3f3f3f;
int       n, m;
int       h[N], e[N], w[N], ne[N], idx; // 邻接表存储各点的头、边、边权、下一节点、索引
int       dist[N];                      // 存储节点1到其余所有节点的距离
bool      st[N];

priority_queue<PII, vector<PII>, greater<PII>> heap;

void add(int a, int b, int c) {
    e[idx]  = b;
    w[idx]  = c;
    ne[idx] = h[a];
    h[a]    = idx++;
}

void init() {
    fill(dist, dist + N, INF);
    fill(st, st + N, 0);
    fill(h, h + N, -1);
    dist[1] = 0;
}

int dijkstra() { // 计算节点1到其余所有节点的距离
    heap.push({0, 1});
    while (heap.size()) {
        auto t = heap.top(); // 距离源点最近的点
        heap.pop();
        int vertex = t.second;
        if (st[vertex]) continue; // 如果距离已经确定，则跳过该点
        st[vertex] = true;

        for (int i = h[vertex]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[vertex] + w[i]) {
                dist[j] = dist[vertex] + w[i];
                heap.push({dist[j], j}); // 距离变小，则入堆
            }
        }
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
        add(x, y, z);
    }
    cout << dijkstra();
    return 0;
}