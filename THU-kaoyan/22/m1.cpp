// 22模拟题1 —— k叉树
// https://www.luogu.com.cn/problem/U414310
#include <iostream>
#include <queue>

using namespace std;

const int  N = 1e5 + 10, M = N * 2;
int        m, k;                       // m条边和k个儿子的限制条件
int        h[N], e[M], ne[M], idx = 0; // 最多m+1个节点，并最多组成一棵树，无向稀疏图
queue<int> que;                        // 用来BFS中做辅助队列
bool       st[N];                      // 用来BFS中判断是否遍历过
int        degree[N];                  // 记录每个节点的度数(出度+入度)

void addEdge(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool isTree(int u) { // 从节点u开始BFS，判断是否是树
    st[u] = true;
    que.push(u);

    int visited = 1; // 记录已遍历节点数，如果是树，其是极大无环图，因此将会等于节点总数
    while (que.size()) {
        int t = que.front();
        que.pop();

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                que.push(j);
                visited++;
            }
        }
    }
    if (visited == m + 1)
        return true;
    else
        return false;
}

int main() {
    fill(h, h + N, -1);
    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b), addEdge(b, a);
        degree[a]++, degree[b]++;
    }

    if (!isTree(0)) {
        cout << "It's not a tree!" << endl;
        return 0;
    }

    for (int i = 0; i <= m; i++) { // 只要找到一个节点的度数比k+1大，就不会存在节点能够满足所有儿子数小于k
        if (degree[i] > k + 1) {
            cout << "No such a node!" << endl;
            return 0;
        }
    }

    for (int i = 0; i <= m; i++) { // 一旦找到第一个满足节点度数小于等于k的，就可以作为根，只有度数k+1的节点不能作为根
        if (degree[i] <= k) {
            cout << i << endl;
            return 0;
        }
    }
}