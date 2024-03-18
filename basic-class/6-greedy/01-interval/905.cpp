// 区间选点
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, int> PII;

const int N = 100010;
PII       interval[N]; // 存放区间的数组,pair.first存放闭区间的左端，second存放闭区间的右端

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> interval[i].first >> interval[i].second;
    }

    // 使用lambda表达式按照区间的右端点从小到大排序
    sort(interval, interval + n, [](const PII &a, const PII &b) {
        return a.second < b.second;
    });

    // 贪心策略，从前往后逐个枚举每个区间的右端点，如果当前区间包含该点，就pass并查询下一个区间，
    // 否则包含当前区间的右端点
    int count    = 0;         // 选取的点的数量
    int endPoint = -1e9 - 10; // 上一个选取的点的位置，初始化为一个非常小的数
    for (int i = 0; i < n; i++) {
        // 如果当前区间的左端点大于上一个选取的点的位置，则需要在当前区间选取一个新的点
        if (interval[i].first > endPoint) {
            count++;                       // 增加选点的数量
            endPoint = interval[i].second; // 更新上一个选取的点的位置为当前区间的右端点
        }
    }
    cout << count << endl;

    return 0;
}