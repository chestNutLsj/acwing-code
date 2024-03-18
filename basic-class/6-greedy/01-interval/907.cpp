// 区间覆盖
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> PII;

vector<PII> intervals;

int main() {
    int s, t; // 指定要覆盖的区间[s,t]
    cin >> s >> t;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (r >= s && l <= t) // 只有当区间与[s,t]有交集时才需要考虑
            intervals.push_back({l, r});
    }

    if (intervals.empty()) { // 如果没有能够产生交集的区间，自然输出-1结束即可
        cout << -1 << endl;
        return 0;
    }

    sort(intervals.begin(), intervals.end()); // pair的排序是按照first元素进行，本题也需要按左端点排序

    // 从前向后依次枚举每个区间，在所有能够覆盖s的区间中，选择右端点最大的区间，然后将s更新成该最大右端点的值
    int  ans       = 0;     // 记录所需的最少区间数量
    bool can_cover = false; // 记录是否能完全覆盖[s,t]
    for (int i = 0, maxR = -1e9 - 10; s <= t && i < intervals.size();) {
        can_cover = false;
        // 寻找能覆盖当前起点s，并且右端点最远的区间
        for (; i < intervals.size() && intervals[i].first <= s; ++i) {
            if (intervals[i].second > maxR) {
                maxR      = intervals[i].second;
                can_cover = true;
            }
        }

        if (can_cover) { // 如果找到了能覆盖当前起点的区间
            ++ans;       // 区间数量+1
            s = maxR;    // 更新当前的起点为找到的区间的右端点
        } else {
            break; // 如果没有找到能覆盖当前起点的区间，说明无法覆盖整个[s,t]，退出循环
        }
    }

    if (s < t) {            // 检查是否完全覆盖了[s,t]
        cout << -1 << endl; // 不能完全覆盖时输出-1
    } else {
        cout << ans << endl; // 能完全覆盖时输出最少区间数量
    }

    return 0;
}