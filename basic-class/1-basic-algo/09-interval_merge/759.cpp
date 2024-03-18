// 格子染色
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

struct Node { // 用于存储线段的信息
    int k, l, r; // k（线段的横坐标或纵坐标，取决于是水平还是垂直线段）
                 // l（线段起点的另一坐标）
                 // r（线段终点的另一坐标）
    bool operator<(const Node &w) const { // 重载用于排序
        if (k != w.k)
            return k < w.k;
        else if (l != w.l)
            return l < w.l;
        else
            return r < w.r;
    }
};

int          n;
LL           cnt;
vector<Node> cols, rows;

void merge(vector<Node> &segs) {
    sort(segs.begin(), segs.end()); // 对传入的segs(线段集合)进行排序
    vector<Node> res;
    int          st = -2e9, ed = st, k = -2e9;
    for (auto &seg : segs) { // 通过迭代，合并所有相邻且重叠或连续的线段
        // 如果当前线段的k值（纵坐标或横坐标）改变，或者当前线段与上一个线段不重叠，
        // 则将上一个线段加入结果集res，并更新cnt计数器以累加线段长度。
        if (seg.k == k) {
            if (ed < seg.l) {
                if (st != -2e9) res.push_back({k, st, ed}), cnt += ed - st + 1;
                ;
                st = seg.l, ed = seg.r;
            } else
                ed = max(ed, seg.r);
        } else {
            if (st != -2e9) res.push_back({k, st, ed}), cnt += ed - st + 1;
            ;
            k = seg.k, st = seg.l, ed = seg.r;
        }
    }
    if (st != -2e9) res.push_back({k, st, ed}), cnt += ed - st + 1;
    ;
    segs = res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
            cols.push_back({x1, min(y1, y2), max(y1, y2)});
        else
            rows.push_back({y1, min(x1, x2), max(x1, x2)});
    }

    merge(cols), merge(rows);

    for (auto &col : cols)
        for (auto &row : rows)
            if (row.k >= col.l && row.k <= col.r && row.r >= col.k
                && row.l <= col.k)
                cnt--;

    cout << cnt << endl;

    return 0;
}