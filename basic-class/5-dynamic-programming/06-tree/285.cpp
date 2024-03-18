// 没有上司的舞会
#include <iostream>
using namespace std;

const int N = 6010;
int       n;                      // 职员数量
int       f[N][2];                // f[u][0]表示所有从以u为根的子树中进行选择，并且不选u这个点的方案的最大快乐指数之和；f[u][1]则为选择该点的方案；
int       h[N], e[N], ne[N], idx; // 邻接表存储
int       happy[N];               // 员工的快乐指数
bool      has_fa[N];              // 员工是否有上司？

void add(int a, int b) { // a---->b, a是上级，b是下级
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void init() {
    fill(h, h + N, -1);
    fill(has_fa, has_fa + N, false);
    f[1][0] = 0, f[1][1] = happy[1];
    idx = 0;
}

void dfs(int u) { // 从根节点开始dfs
    f[u][1] = happy[u];
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        dfs(j);
        f[u][1] += f[j][0];
        f[u][0] += max(f[j][0], f[j][1]);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> happy[i];
    init();
    while (--n) {
        int l, k; // 记录职员上下级关系，k是l的上级
        cin >> l >> k;
        add(k, l);
        has_fa[l] = true;
    }

    int root = 1;
    while (has_fa[root]) root++;
    dfs(root);
    cout << max(f[root][1], f[root][0]);

    return 0;
}