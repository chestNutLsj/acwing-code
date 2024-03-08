// 食物链
#include <iostream>

using namespace std;

const int N = 50010;
int       fa[N];   // 只要命题里给出了动物之间的关系，就放到一个集合里
int       dist[N]; // 通过与根的距离来确定食物链，
                   // 距离1表示可以吃，距离2表示被吃，距离3表示同类
                   // 所以取模操作非常重要，mod 3=0就是同类，其余类推
                   // 节点find后路径压缩，并维护总距离
int lies = 0;      // 记录假话的数量

inline void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i; // dist[]就不必初始化了，因为设置时就是全0
    }
}

int find(int x) {
    if (fa[x] != x) {           // 只有祖先不是自己时（代表着已经加入了集合），才需要下述操作
        int tmp = find(fa[x]);  // 先暂存最早祖先
        dist[x] += dist[fa[x]]; // 更新当前节点到最早祖先的距离
        fa[x] = tmp;            // 路径压缩
    }
    return fa[x];
}

int main() {
    int n, k;
    cin >> n >> k;
    init(n); // 对n个动物的关系进行初始化
    int opt, x, y;
    while (k--) {
        cin >> opt >> x >> y;
        if (x > n || y > n) { // 假话情况2
            lies++;
        } else if (opt == 2 && x == y) { // 假话情况3
            lies++;
        } else {
            int px = find(x), py = find(y);                // 分别找到x、y的最早祖先，之后就可以判断命题是否已经出现过（出现过才会有逻辑悖论）
            if (opt == 1) {                                // 判断x和y是同类的命题是否正确
                if (px == py && (dist[x] - dist[y]) % 3) { // 如果祖先相同，说明已在同一集合
                    lies++;                                // 同时到祖先的距离都能模3，说明是同类，就不会导致lies增加，
                                                           // 否则就会存在吃与被吃的关系，lies增加
                } else if (px != py) {                     // 祖先不同，说明还没在同一集合（即这个二者之间的关系还未知，自然不会出错）
                    fa[px]   = py;                         // 先合并，将py作为合并后集合的根
                    dist[px] = dist[y] - dist[x];          // 再维护距离，示意图如下
                    /* px -------------------- py
                       |        dist[px]=?     |
                       |                       |
                       |                       |
                       |dist[x]                |dist[y]
                       |                       |
                       |                       |
                       x                       y

                       x,y,px,py都是同类，说明(dist[x]+?-dist[y])%3 = 0 ，因此?=dist[px]=dist[y]-dist[x]
                     */
                }
            } else {                                         // 判断x吃y的命题是否符合逻辑
                if (px == py && (dist[x] - dist[y] - 1) % 3) // 如果命题已经出现过
                    lies++;                                  // 但是距离之差再减1取模后仍为1，说明x被y吃，因此出现悖论，lies++
                else if (px != py) {
                    fa[px]   = py;
                    dist[px] = dist[y] + 1 - dist[x];
                }
            }
        }
    }
    cout << lies;
    return 0;
}