// 数组模拟静态双链表
#include <iostream>
#include <string>

using namespace std;

const int N = 100010;
int       e[N], l[N], r[N], idx;

void init() {
    r[0] = 1, l[1] = 0;
    idx = 2; //! idx 此时已经用掉两个点了
}

void insertAsRight(int k, int ele) {
    e[idx] = ele;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx;
    idx++;
} //! 当然在 k 的左边插入一个数可以直接调用这个函数，
  //! 等价于在 l[k] 的右边插入一个数 insertAsRight(l[k],x)

void removeAt(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main() {
    int m;
    cin >> m;
    init();
    string opt;
    int    k, x;
    for (int i = 0; i < m; i++) {
        cin >> opt;
        if (opt == "L") {
            cin >> x;
            insertAsRight(0, x);
            //! 最左边插入就是在指向 0
            //! 的数的左边插入就可以了也就是可以直接在0的右边插入
        } else if (opt == "R") {
            cin >> x;
            insertAsRight(l[1], x);
            //! 0 和 1 只是代表头和尾所以最右边插入只要在指向 1
            //! 的那个点的右边插入就可以了
        } else if (opt == "D") {
            cin >> k;
            removeAt(k + 1);
        } else if (opt == "IL") {
            cin >> k >> x;
            insertAsRight(l[k + 1], x);
        } else {
            cin >> k >> x;
            insertAsRight(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';

    return 0;
}