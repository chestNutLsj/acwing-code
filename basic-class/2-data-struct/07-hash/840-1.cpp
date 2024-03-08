// 模拟哈希表（开放寻址法）
#include <iostream>
using namespace std;

const int N = 300007;
int       h[N];
int       null = 400007;

int find_prime(int x) { // 找到大于x的第一个质数
    int i = x;
    for (;; i++) {
        bool flag = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << endl;
            break;
        }
    }
    return i;
}

int find(int x) { // 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x) // 这里null设置一个不在数据范围内的任意数即可，作为位置为空的标记
    {
        t++;
        if (t == N) t = 0;
    }
    return t;
}

int main() {
    fill(h, h + N, null);
    int n, x;
    cin >> n;
    string opt;
    while (n--) {
        cin >> opt >> x;
        int pos = find(x);
        if (opt == "I") {
            h[pos] = x;
        } else {
            if (h[pos] == x) {
                cout << "Yes" << endl;
            } else
                cout << "No" << endl;
        }
    }

    return 0;
}