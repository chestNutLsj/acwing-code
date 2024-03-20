// 区间分组
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> PLL;

vector<PLL> intervals;

bool cmp(const PLL &a, const PLL &b) { return a.first < b.first; }

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals.push_back({l, r});
    }

    // 使用自定义的比较函数，按照区间的右端点从小到大排序
    sort(intervals.begin(), intervals.end(), cmp);
    // for (auto &&i : interval) {
    //     cout << i.first << ',' << i.second << endl;
    // }

    // 贪心策略，按每个区间的右端点从小到大逐个枚举，堆里存已检查分组的最小右端点，
    // 当前要判断的区间的左端点至少要大于已检查分组中的某个右端点，才不用开新组，
    // 若小于 / 等于所有分组的最小右端点（也就是小于 / 等于堆顶），则需要开新组

    priority_queue<int, vector<int>, greater<int>> heap; // 优先队列，存储每个组的最大右端点
    for (const auto &r : intervals) {
        if (!heap.empty() && heap.top() < r.first) {
            // 如果当前区间的左端点大于堆顶元素（也就是目前所有组中最小的右端点），
            // 则可以复用这个组
            heap.pop(); // 移除这个组的旧的右端点
        }
        // 将当前区间的右端点加入优先队列（代表开启新组或加入现有组）
        heap.push(r.second);
    }

    cout << heap.size() << endl;

    return 0;
}