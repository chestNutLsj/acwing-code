// SPFA判断负权环
#include <iostream>
#include <queue>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;
int       h[N], e[N], w[N], ne[N], idx;
int       n, m;
int       dist[N];
int       cnt[N]; // 记录1到x的最短路中经过的点数
bool      st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void init() {
    fill(h, h + N, -1);
    fill(dist, dist + N, INF);
    fill(st, st + N, false);
    fill(cnt, cnt + N, 0); // 最开始没有任何路径从源点到其他点
    dist[1] = 0;
    idx     = 0;
}

bool spfa() {
    queue<int> q; // 队列中存放可以被更新的缩短距离的点
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }

    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j]  = cnt[t] + 1;
                if (cnt[j] >= n)
                    return true; // 如果从1号点到x的最短路中包含至少n个点（不包括自己），则说明存在环

                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    init();
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }

    if (spfa())
        cout << "Yes" << endl;
    else
        cout << "No";

    return 0;
}