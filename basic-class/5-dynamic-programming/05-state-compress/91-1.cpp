#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 25, INF = 0x3f3f3f3f;
int       a[N][N];
bool      visited[N]; // 标记数组，记录每个顶点是否被访问过
int       n;
int       res = INF; // 记录最短路径的长度

// DFS函数，参数：当前顶点u，当前路径长度len，已访问顶点数count
void dfs(int u, int len, int count) {
    if (count == n) {            // 如果已访问所有顶点
        if (u == n - 1) {        // 并且当前顶点是终点
            res = min(res, len); // 更新最短路径长度
        }
        return;
    }

    for (int v = 0; v < n; v++) {             // 遍历所有顶点
        if (!visited[v]) {                    // 如果顶点v未被访问
            visited[v] = true;                // 标记顶点v为已访问
            dfs(v, len + a[u][v], count + 1); // 递归访问顶点v
            visited[v] = false;               // 回溯，恢复顶点v的未访问状态
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    memset(visited, false, sizeof(visited)); // 初始化visited数组
    visited[0] = true;                       // 从0号点出发
    dfs(0, 0, 1);                            // 从0号点开始DFS搜索，当前路径长度为0，已访问顶点数为1

    cout << res << endl; // 输出最短路径的长度

    return 0;
}
