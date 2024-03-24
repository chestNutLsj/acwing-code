// 23真题1 —— 公司
// https://www.luogu.com.cn/problem/U412534
#include <algorithm>
#include <iostream>

using namespace std;
using LL  = long long;
using PLL = pair<LL, LL>;

const int    N = 1e5 + 10, M = 2 * N;
const double esp = 1e-6;
int          n, m;      // 公司的人数、泄露的工资情况数
LL           salary[N]; // 员工自己的工资
PLL          know[N];   // 员工了解到的其它人的工资情况，first表示知道的人数，second表示知道的总工资

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> salary[i]; // 员工编号从1开始
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;               // x号雇员知道了y号雇员的工资
        know[x].first++;             // x号雇员知道的人数
        know[x].second += salary[y]; // x号雇员知道的工资的总数
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (know[i].first)                                                              // 如果雇员知道其他人的工资情况不为0条
            if ((((double) know[i].second / (double) know[i].first) - salary[i]) > esp) // 并且知道的平均工资高于自身工资
                ans++;                                                                  // 萌生离职的想法
    }
    cout << ans;

    return 0;
}