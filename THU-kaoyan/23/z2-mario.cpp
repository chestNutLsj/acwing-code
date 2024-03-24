// 来自mario佬的双链表+map解法
#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>

int rd() {
    int  k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? k : -k;
}

void wr(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar((x % 10) ^ '0');
}

namespace delist {
    const int                     N         = 514114;
    const int                     left_tail = N - 2, right_tail = N - 1;
    int                           pre[N], nxt[N], val[N], list_sz, task_num, queue_limit;
    std::set<std::pair<int, int>> s; // <priority,number>

    void init(int lim) {
        nxt[left_tail] = right_tail, pre[right_tail] = left_tail, queue_limit = lim;
    }

    // insert at pos's right, assume mission doesn't exist
    // mission number=task_num (1<=task_num<=n),importance=a (1<=a<=n)
    void insert(int pos, int num, int a) {
        val[num] = a, pre[num] = pos, nxt[num] = nxt[pos];
        pre[nxt[pos]] = num, nxt[pos] = num;
        s.insert(std::make_pair(-a, num)), ++list_sz;
    }

    // remove mission by num,assume mission exists.
    void remove(int num) {
        pre[nxt[num]] = pre[num], nxt[pre[num]] = nxt[num];
        s.erase(s.find(std::make_pair(-val[num], num)));
    }
} // namespace delist
