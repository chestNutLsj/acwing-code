// 22真题1 —— 字符串
// https://www.luogu.com.cn/problem/U276782
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const int N = 1e5 + 10;
int       n, m; // 字符串长度为n，子串长度限制为m

LL calc(LL t) {
    if (t < m) return 0ll;
    return 1ll * (t - m + 1) * (t - m + 2) / 2;
}

int main() {
    cin >> n >> m;

    vector<int> vec; // 记录输入字符串中纯1子串的长度，每遇到一个0，就换新的一个元素记录
    string      input;
    cin >> input;
    int len = 0;
    for (auto it = input.begin(); it != input.end(); it++) {
        if (*it == '1')
            len++;
        else {
            vec.push_back(len);
            len = 0;
        }
    }
    vec.push_back(len);

    LL ans = 0ll;
    for (auto &&i : vec) {
        ans += calc(i * 1ll);
    }
    cout << ans;
    return 0;
}