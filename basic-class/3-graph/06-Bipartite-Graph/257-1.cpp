// 并查集实现罪犯二分
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 20100, M = 100010;
int       p[N], d[N];
struct Edge {
    int  a, b, c;
    bool operator<(const Edge e) const {
        return c > e.c;
    }
} edge[M];

int find(int x) {
    if (x != p[x]) {
        int t = p[x];
        p[x]  = find(p[x]);
        d[x] += d[t];
    }

    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        edge[i] = {a, b, c};
    }
    sort(edge, edge + m);

    for (int i = 1; i <= n; ++i)
        p[i] = i;

    bool flag = true;
    for (int i = 0; i < m; ++i) {
        int a = edge[i].a, b = edge[i].b, c = edge[i].c;
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            if ((d[a] - d[b] - 1) % 2 != 0) {
                cout << c << endl;
                flag = false;
                break;
            }
        } else {
            p[pa] = pb;
            d[pa] = d[b] - d[a] + 1;
        }
    }
    if (flag)
        cout << 0 << endl;

    return 0;
}
