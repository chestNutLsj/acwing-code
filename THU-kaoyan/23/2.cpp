// 模拟题2 —— 粽子树
// https://www.luogu.com.cn/problem/U412495
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1000010, M = 2 * N;
int       h[N], e[M], ne[M], idx; // 树是稀疏图，用邻接表存之，h[i]: 表示第 i 个节点的第一条边的 idx ，ne[i] : 表示与第 idx 条边同起点的下一条边的 idx，e[i] : 表示第 idx 条边的终点
int       n;                      // 节点数
int       a[N];                   // a[i] 表示编号i的节点上的粽子的种类，不同的值代表不同的种类
int       ans[N];                 // ans[i]表示编号i的节点到根节点1的简单路径上粽子的种类数
bool      st[N];                  // dfs中用作标记，表示该点已经被搜索过
// int       cnt[N];                 // 记录每种粽子的出现次数

void init() {
    fill(h, h + N, -1);
    fill(ans, ans + N, 0);
    // fill(a, a + N, 0);
    // fill(st, st + N, false);
    idx = 0;
}

void addEdge(int a, int b) { // 建立a-->b的边
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int fa, unordered_map<int, int> &cnt) { // 从u号点开始dfs，根据树的连通性、a[i]计算ans[i]
    st[u] = true;
    cnt[a[u]]++;
    ans[u] = cnt.size();

    for (int i = h[u]; i != -1; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;
        dfs(v, u, cnt);
    }
    cnt[a[u]]--;
    if (cnt[a[u]] == 0) cnt.erase(a[u]);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    init();
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v), addEdge(v, u); // 树是无向图
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    unordered_map<int, int> cnt;
    dfs(n, 0, cnt);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}