// 二进制优化版 多重背包
#include <iostream>
#include <vector>
using namespace std;

const int N = 20010; // 根据问题规模调整N的大小
int       f[N];

struct Good {
    int v, w;
};

int main() {
    int num, vol;
    cin >> num >> vol;
    vector<Good> goods;
    for (int i = 1; i <= num; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k *= 2) { // 二进制拆分
            s -= k;
            goods.push_back({v * k, w * k});
        }
        if (s > 0) goods.push_back({v * s, w * s}); // 加入剩余的部分
    }

    // 01背包问题
    for (auto &good : goods) {
        for (int j = vol; j >= good.v; j--) {
            f[j] = max(f[j], f[j - good.v] + good.w);
        }
    }

    cout << f[vol] << endl;
    return 0;
}
