// 最大异或对
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long LL;

const int N = 100010, M = 32 * N;
int       son[M][2], idx;
LL        input[N];

void insert(int x) {
    int p = 0; // Trie root
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;                // 取x的第i位的二进制数
        if (!son[p][u]) son[p][u] = ++idx; // 插入过程中没有发现孩子节点，则设之
        p = son[p][u];                     // 指针指向下一层
    }
}

int search(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1; // 从最高位开始查找
        if (son[p][!u]) {
            // 如果当前层有对应的不相同的数，p指针就指向不同数的地址；
            p   = son[p][!u];
            res = res * 2 + 1;
        } else {
            p   = son[p][u];
            res = res * 2 + 0;
        }
    }
    return res;
}

int main() {
    cin.tie(0);
    int n;
    cin >> n;
    idx = 0;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        insert(input[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, search(input[i])); /// search(a[i])查找的是a[i]值的最大与或值
    }
    cout << res << endl;

    return 0;
}