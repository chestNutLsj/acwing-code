// 混合背包
#include <iostream>
using namespace std;

const int N = 1010;
int       f[N]; // 优化为一维数组，减少空间复杂度

int main() {
    int num, vol;
    cin >> num >> vol;
    for (int i = 1; i <= num; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        if (s == -1) { // 01 背包
            for (int j = vol; j >= v; j--)
                f[j] = max(f[j], f[j - v] + w);
        } else if (s == 0) { // 完全背包
            for (int j = v; j <= vol; j++)
                f[j] = max(f[j], f[j - v] + w);
        } else {                          // 多重背包，使用二进制优化
            if (s * v > vol) s = vol / v; // 如果物品总体积超过背包容量，则视为完全背包处理
            for (int k = 1; k <= s; k *= 2) {
                int mv = k * v, mw = k * w;
                for (int j = vol; j >= mv; --j) {
                    f[j] = max(f[j], f[j - mv] + mw);
                }
                s -= k;
            }
            if (s > 0) { // 处理剩余部分，确保所有数量的物品都被考虑到
                int mv = s * v, mw = s * w;
                for (int j = vol; j >= mv; --j) {
                    f[j] = max(f[j], f[j - mv] + mw);
                }
            }
        }
    }
    cout << f[vol] << endl;
    return 0;
}
