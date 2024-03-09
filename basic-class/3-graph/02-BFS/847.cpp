// 图中点的层次
#include <iostream>
#include <queue>

using namespace std;

const int N = 100010;
int       n, m; // n nodes,m edges
int       a, b; // 有向边a-->b的两个端点
// int        g[N][N] = {0}; //! 邻接矩阵存储图。不可行⚠️因为N*N*1Byte=10^10Byte=10GB，远超系统能够提供给一般程序的内存空间
int        h[N], e[N], ne[N], idx; // 邻接表存储图
queue<int> q;                      // 维护遍历到的节点
int        st[N];                  // 标记节点是否被访问过
int        d[N];                   // 存储从1号点到每个点的最短距离

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void init() {
    idx = 0;
    fill(h, h + N, -1);
    fill(d, d + N, -1); // 初始化距离数组
    fill(st, st + N, 0);
}

void bfs() { // 1号点到其它点的最短距离
    st[1] = true;
    d[1]  = 0;
    q.push(1);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) { // 对于t的每个邻接点，如果没有被访问过，则更新距离并加入队列之中
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                d[j]  = d[t] + 1;
                q.push(j);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) { // 存储图
        cin >> a >> b;
        add(a, b);
    }

    bfs(); // 从1节点开始bfs
    cout << d[n];
    return 0;
}