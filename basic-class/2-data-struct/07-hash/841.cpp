// 字符串哈希
#include <iostream>

using namespace std;
typedef unsigned long long ULL;

const int N = 100003, P = 131; // P是素数，常取131、13331
ULL       h[N], p[N];          // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64
int       n, m;                // n是字符串长度，m是查询次数
string    str;

void init() {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + str[i - 1]; // 在C++中，std::string的索引是从0开始的，但是在init函数中，h和p数组的计算是从1开始的，而且str[i]直接使用i作为索引，这会导致索引偏移错误。应该将str[i]改为str[i - 1]以正确匹配字符串中的字符。
        p[i] = p[i - 1] * P;
    }
}

ULL get_interval_hash(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    cin >> n >> m >> str;
    init();
    while (m--) {
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get_interval_hash(l1, r1) == get_interval_hash(l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}