// 合并集合
#include <iostream>

using namespace std;

const int N = 100010;
int       a, b;
int       n, m;
char      opt;
int       fa[N];

inline void init(int n) {
    for (int i = 1; i <= n; ++i) fa[i] = i;
}

int find(int x) {
    if (fa[x] == x) {
        return x;
    } else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}
inline void merge(int a, int b) { fa[find(a)] = find(b); };

int main() {
    cin >> n >> m;
    init(n);
    while (m--) {
        cin >> opt;
        if (opt == 'M') {
            cin >> a >> b;
            merge(a, b);
        } else {
            cin >> a >> b;
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}