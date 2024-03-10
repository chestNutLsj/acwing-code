// 染色法
#include <iostream>

using namespace std;

const int N = 100010 * 2;
int       n, m;
int       h[N], e[N], ne[N], idx;
int       color[N]; // -1表示未染色，0表示染白色，1表示染黑色

void init() {
    fill(h, h + N, -1);
    fill(color, color + N, -1);
    idx = 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c) { // u表示当前节点，c表示当前节点的颜色
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (color[j] == -1) {
            if (!dfs(j, !c))
                return false;
        } else if (color[j] == c)
            return false;
    }
    return true;
}

bool check() {
    for (int i = 1; i <= n; i++)
        if (color[i] == -1)
            if (!dfs(i, 0)) return false;
    return true;
}

int main() {
    cin >> n >> m;
    init();
    while (m--) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    check() ? cout << "Yes" : cout << "No";

    return 0;
}