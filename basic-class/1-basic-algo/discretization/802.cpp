// 稀疏矩阵的区间和
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int   N = 300010; // n次插入和m次查询相关数据量的上界
int         n, m;
int         a[N];    // 存储对应坐标插入的值
int         s[N];    // 存储数组a的前缀和
vector<int> alls(N); // 存储（所有与插入和查询相关的）坐标
vector<pair<int, int>> add, query; // 存储插入和查询的数据

int find(int x) { // 返回输入坐标离散化后的新坐标
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    return r + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    // 排序、去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    // 执行前n次插入操作
    for (auto item : add) {
        int x = find(item.first);
        a[x] += item.second;
    }
    // 计算前缀和
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];
    // 处理m次查询操作
    for (auto &&i : query) {
        int l = find(i.first);
        int r = find(i.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}