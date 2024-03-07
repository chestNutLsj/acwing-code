// 连通块中点的数量
#include <iostream>

using namespace std;

const int N = 100010;
int       fa[N];
int       Size[N];

inline void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i]   = i;
        Size[i] = 1;
    }
}

int find(int x) {
    if (fa[x] == x)
        return x;
    else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

inline void merge(int a, int b) {
    // fa[find(a)] = find(b);
    // Size[find(b)] += Size[find(a)];
    /* 上面的两行代码是有错误的：
    1. 父节点错误更新：当你调用fa[find(a)] =find(b);之后，find(a)已经不再是a的直接父节点了，
    因为它已经被更新为b的父节点。因此，后续的Size[find(a)]+= Size[find(b)];实际上是错误的，
    因为此时find(a)可能不再代表原来的a所在集合的根节点。

    2. 集合大小错误累加：正确的做法应该是在确定了两个集合的根节点之后，
    将被合并的集合大小加到目标集合上，并且只在两个集合的根节点不同的情况下执行合并操作。
    */
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        fa[rootA] = rootB;          // 将rootA的父节点设置为rootB
        Size[rootB] += Size[rootA]; // 更新rootB的连通块大小
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    string opt;
    while (m--) {
        cin >> opt;
        if (opt == "C") {
            int a, b;
            cin >> a >> b;
            if (a != b) { merge(a, b); }

        } else if (opt == "Q1") {
            int a, b;
            cin >> a >> b;
            if (find(a) == find(b) || a == b)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } else {
            int a;
            cin >> a;
            cout << Size[find(a)] << endl;
        }
    }
    return 0;
}