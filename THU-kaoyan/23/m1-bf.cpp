/// 这个是暴力做法，只能混到20分
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const LL constraint = 999999999999;

LL nums_specified_length_string(int n) {
    vector<int> nums(n, 1); // 初始化为最小的字符串
    LL          cnt = 0;

    while (true) {
        bool valid = true;
        // 检查是否有连续三个相同字符
        for (int i = 2; i < n; ++i) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                valid = false;
                break;
            }
        }
        if (valid) cnt++; // 符合条件的字符串数量加一

        // 生成下一个四进制数
        int carry = 1;
        for (int i = n - 1; i >= 0; --i) {
            nums[i] += carry;
            if (nums[i] == 4) {
                nums[i] = 1;
                carry   = 1;
            } else {
                carry = 0;
                break;
            }
        }

        if (carry == 1) break; // 已经到达最大四进制数
    }

    return cnt;
}

int main() {
    int t; // 查询次数
    cin >> t;
    while (t--) {
        int n; // 查询的字符串的长度
        cin >> n;
        LL res = nums_specified_length_string(n);
        if (res <= constraint)
            cout << res << endl;
        else {
            cout << "......" << res % 1000000000 << endl;
        }
    }
    return 0;
}
