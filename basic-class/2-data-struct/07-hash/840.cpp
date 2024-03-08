// 模拟散列表
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 100003;

// 独立链法
int h[N], e[N], ne[N], idx;

void insert(int x) {
    int k   = (x % N + N) % N;
    e[idx]  = x;
    ne[idx] = h[k];
    h[k]    = idx++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x) return true;
    return false;
}

int main() {
    fill(h, h + N, -1);
    int  n, k;
    char opt;
    cin >> n;

    while (n--) {
        cin >> opt >> k;
        if (opt == 'I') {
            insert(k);
        } else {
            if (find(k)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}