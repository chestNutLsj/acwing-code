// 二分图的最大匹配 （匈牙利算法）
#include <iostream>

using namespace std;

const int N = 510, M = 100010;
int       n1, n2, m;
int       h[N], e[M], ne[M], idx;
int       match[N]; // 存储第二个集合中的每个点当前匹配的第一个集合中的点是哪个
bool      st[N];    // 表示第二个集合中的每个点是否已经被遍历过

void init() {
    fill(h, h + N, -1);
    fill(match, match + N, 0);
    fill(st, st + N, false);
}

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool find(int x) {
    // 遍历自己喜欢的女孩
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) // 如果在这一轮模拟匹配中,这个女孩尚未被预定
        {
            st[j] = true; // 那x就预定这个女孩了
            // 如果女孩j没有男朋友，或者她原来的男朋友能够预定其它喜欢的女孩。配对成功
            if (!match[j] || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    // 自己中意的全部都被预定了。配对失败。
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    init();
    while (m--) {
        int u, v;
        cin >> u >> v;
        add(u, v); // 匈牙利算法中只会用到从第一个集合指向第二个集合的边，所以这里只用存一个方向的边
    }
    int res = 0;
    for (int i = 1; i <= n1; i++) { // 求最大匹配数，依次枚举第一个集合中的每个点能否匹配第二个集合中的点
        fill(st, st + N, false);    // 重置st是因为假设被A考虑过的女生如果也是B的心仪对象，在之后同样也可以被B考虑。
        if (find(i)) res++;
    }
    cout << res;
    return 0;
}