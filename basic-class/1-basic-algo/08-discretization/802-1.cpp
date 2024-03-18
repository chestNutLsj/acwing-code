// 使用unordered_map进行优化，性能提升了4.3%左右
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 存储插入和查询操作的数据，不再需要alls数组
vector<pair<int, int>> add, query;

// 使用unordered_map来离散化坐标并直接映射值
unordered_map<int, int> idxMap;    // 存储坐标的新旧映射
unordered_map<int, int> prefixSum; // 存储离散化坐标的前缀和

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    // 读取插入操作
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
    }

    // 读取查询操作
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
    }

    // 离散化，使用vector来存储所有坐标，然后排序去重
    vector<int> alls;
    for (auto &item : add) { alls.push_back(item.first); }
    for (auto &item : query) {
        alls.push_back(item.first);
        alls.push_back(item.second);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 建立坐标与新索引的映射
    int idx = 0;
    for (int x : alls) { idxMap[x] = ++idx; }

    // 执行插入操作，直接使用映射更新值
    for (auto &item : add) {
        int x = idxMap[item.first]; // 获取映射后的坐标
        prefixSum[x] += item.second;
    }

    // 计算前缀和
    for (int i = 1; i <= idx; i++) { prefixSum[i] += prefixSum[i - 1]; }

    // 处理查询操作
    for (auto &item : query) {
        int l = idxMap[item.first]
                - 1; // 获取映射后的左坐标，并向前移动一个单位以适应前缀和的计算
        int r = idxMap[item.second]; // 获取映射后的右坐标
        cout << prefixSum[r] - prefixSum[l] << endl;
    }

    return 0;
}
