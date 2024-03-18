// 最大不相交区间的数量
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010, INF = 1e9 + 10;
struct Range {
    int  l, r;                             // 区间左右端点
    bool operator<(const Range &W) const { // 重载运算符
        return r < W.r;
    }
} range[N]; // 存放区间的结构体数组

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> range[i].l >> range[i].r;
    }

    // 使用重载后的运算符，按照区间的右端点从小到大排序
    sort(range, range + n);

    // 贪心策略，从前往后逐个枚举每个区间的右端点，如果当前区间的左端点小于等于上一个区间的右端点，就pass并查询下一个区间，
    // 否则包含当前区间的右端点
    int count    = 1;          // 选取的不想交区间的数量
    int endPoint = range[0].r; // 上一个选取的点的位置，初始化为第一个区间的右端点
    for (int i = 1; i < n; i++) {
        // 如果当前区间的左端点小于等于上一个区间的右端点，跳过，否则计数+1
        if (range[i].l > endPoint) {
            count++;               // 更新不相交区间的计数
            endPoint = range[i].r; // 更新上一个选取的点的位置为当前区间的右端点
        }
    }
    cout << count << endl;

    return 0;
}