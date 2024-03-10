// SPFA求最短路
#include <iostream>
#include <queue>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;
int       h[N], e[N], w[N], ne[N], idx;
int       n, m;
int       dist[N];
bool      st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void init() {
    fill(h, h + N, -1);
    fill(dist, dist + N, INF);
    fill(st, st + N, 0);
    dist[1] = 0, idx = 0;
}

int spfa() {
    queue<int> q; // 队列中存放可以被更新的缩短距离的点
    q.push(1);
    st[1] = true;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

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
    int res = spfa();
    if (res > INF / 2)
        cout << "impossible" << endl;
    else
        cout << res;

    return 0;
}