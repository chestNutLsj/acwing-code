#include <iostream>
using namespace std;
const int N = 1010;
int       f[N];       // f[i] 表示总体积是i的情况下，最大的总价值
int       v[N], w[N]; // 记录每个物品的体积和价值
int       main() {
    int num, vol;
    cin >> num >> vol;
    for (int i = 1; i <= num; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= num; i++)
        for (int j = vol; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[vol] << endl;
    return 0;
}