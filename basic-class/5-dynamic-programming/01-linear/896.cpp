// 最长上升子序列II
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
int       a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> d(n + 1, 0);
    int         len = 0; // 记录当前最长上升子序列的长度
    for (int i = 0; i < n; i++) {
        // 通过二分查找在d中找到第一个大于等于a[i]的元素位置
        int l = 1, r = len, pos = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (d[mid] < a[i]) {
                pos = mid;
                l   = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // 如果这个元素不存在，说明a[i]可以增加到d数组末尾形成更长的子序列
        d[pos + 1] = a[i];
        if (pos + 1 > len) len++; // 更新当前最长上升子序列的长度
    }

    cout << len << endl;
}
