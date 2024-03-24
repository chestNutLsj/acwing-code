// 模拟题2 —— 粽子树
// https://www.luogu.com.cn/problem/U412495
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 10, M = 2 * N;
int       h[N], e[M], ne[M], idx; // 树是无向稀疏图，用邻接表存之，
// h[N]: 邻接表的头节点数组，存储每个节点的第一条边的索引
// e[N]和ne[N]: 边数组和下一条边的索引数组，用于表示图中的边。e[i]表示边的终点，ne[i]指向下一条边
int         n;         // 节点数
int         kind[N];   // kind[i] 表示编号i的节点上的粽子的种类，不同的值代表不同的种类，注意种类数在int范围，而节点数在10^6范围，这是个经典的稀疏情形，需要hash或离散化
int         ans[N];    // ans[i]表示编号i的节点到根节点1的简单路径上粽子的种类数
int         cnt[N];    // 记录每种粽子在当前路径上的出现次数
bool        st[N];     // 记录dfs中是否已经扫描过
vector<int> kinds_set; // 用于离散化，存储所有不同粽子种类的列表

void init() {
    fill(h, h + N, -1);
    // fill(ans, ans + N, 0);
    // fill(kind, kind + N, 0);
    // fill(cnt, cnt + N, 0);
    fill(st, st + N, false);
    idx = 0;
}

int find(int x) { // 用二分查找，在粽子种类的去重列表中找到匹配者并返回其离散化后的位置
    int l = 0, r = kinds_set.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (kinds_set[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l + 1;
}

void addEdge(int a, int b) { // 建立a-->b的边
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int fa) { // 从u号点开始dfs，fa避免在递归过程中重新访问父节点，根据树的连通性、kind[i]计算ans[i]
    if (st[u]) return;    // 不过本题是无环图，因此这一步并不必要，不会出现无限递归的情况
    st[u] = true;
    if (cnt[kind[u]])     // 如果当前节点u的粽子种类在此前的路径上出现过
        ans[u] = ans[fa]; // 则当前节点到根的路径上不同粽子种类数量与父亲相同
    else
        ans[u] = ans[fa] + 1; // 否则在父亲的种类数上+1

    cnt[kind[u]]++; // 将当前节点的粽子种类的计数+1，表示这种粽子种类在当前路径上的出现次数增加

    for (int i = h[u]; i != -1; i = ne[i]) { // 递归
        int j = e[i];
        dfs(j, u);
    }
    cnt[kind[u]]--; // 在递归返回之前，将当前节点的粽子种类的计数减少1（cnt[kind[u]]--）
    // 这是因为当离开一个节点时，这个节点的粽子种类不应再影响后续路径的计数。
    // 这样可以确保cnt数组准确地反映了从当前路径上每种粽子的实际出现次数。
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
    for (int i = 1; i <= n; i++) {
        cin >> kind[i];               // 节点编号从1开始
        kinds_set.push_back(kind[i]); // 离散化的准备
    }

    // 离散化
    sort(kinds_set.begin(), kinds_set.end());
    kinds_set.erase(unique(kinds_set.begin(), kinds_set.end()), kinds_set.end());
    for (int i = 1; i <= n; i++) kind[i] = find(kind[i]);

    dfs(n, 0); // 使用n作为根节点开始遍历
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}