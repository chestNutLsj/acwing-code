#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int   N = 100010;
int         n, m;
int         h[N], e[N], ne[N], idx;
int         d[N];   // 保存各个点的入度
queue<int>  q;      // 队列保存入度为0的点
vector<int> result; // 保存拓扑排序结果

void add(int a, int b) {
    e[idx]  = b;
    ne[idx] = h[a];
    h[a]    = idx++;
}

void init() {
    idx = 0;
    fill(h, h + N, -1);
    fill(d, d + N, 0);
}

void topoSort() {
    for (int i = 1; i <= n; i++)
        if (d[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (int i = h[u]; i != -1; i = ne[i]) {
            int v = e[i];
            d[v]--;
            if (d[v] == 0)
                q.push(v);
        }
    }

    if (result.size() == n) { // 检查是否所有顶点都被访问，确保图为DAG
        for (int i = 0; i < n; ++i) {
            cout << result[i] << ' ';
        }
        cout << endl;
    } else {
        cout << -1 << endl; // 图中存在环，无法进行拓扑排序
    }
}

int main() {
    cin >> n >> m;
    init();
    while (m--) {
        int a, b; // a-->b
        cin >> a >> b;
        d[b]++;
        add(a, b);
    }
    topoSort();
    return 0;
}