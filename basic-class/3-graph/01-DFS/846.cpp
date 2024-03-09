// Tree's center of gravity
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010, M = N * 2;
int       h[N], e[M], ne[M], idx; // 树是稀疏图，故用邻接表存储
bool      st[N];                  // 存放节点是否已经遍历
int       ans;                    // 记录全局的答案
int       n;                      // 记录树的节点总数
int       a, b;                   // 记录树边a-->b

void add(int a, int b) { // 添加一条边a-->b
    e[idx]  = b;
    ne[idx] = h[a];
    h[a]    = idx++;
}

void init() {
    idx = 0;
    memset(h, -1, sizeof(h));
    memset(st, 0, sizeof(st));
    ans = n;
}

int dfs(int u) {          // 返回以u为根的子树的规模
    st[u]   = true;       // 做标记，已经被搜索过了
    int sum = 1, res = 0; // sum记录当前子树的规模，res记录删去该点后其余连通块的最大值
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i]; // 暂存当前链表中节点对应图中点的编号
        if (!st[j]) {
            int s = dfs(j); // 如果没有搜索过，那就深入搜索，根据递归，返回的就是当前节点子树的规模
            res   = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum); // 判断子树规模和父亲所在连通块的规模孰大
    ans = min(ans, res);
    return sum;
}

int main() {

    cin >> n;
    init();
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        add(a, b), add(b, a); // 无向边，所以要加两条
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}