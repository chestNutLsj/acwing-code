// 数组模拟静态单链表
#include <iostream>

using namespace std;

const int N = 100010;
int       head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx  = 0;
}

void insertAsHead(int a) {
    e[idx] = a, ne[idx] = head, head = idx++;
}

void insertAsSucc(int k, int a) {
    e[idx]  = a;
    ne[idx] = ne[k];
    ne[k]   = idx;
    idx++;
}

void removeSucc(int k) { // 删除k位置后面的一个节点
    ne[k] = ne[ne[k]];   // 不要在意浪费，这不是工程
}

void removeHead() {
    head = ne[head];
}

int main() {
    int m;
    cin >> m;
    init();
    char opt;
    int  x1, x2;
    for (int i = 0; i < m; i++) {
        cin >> opt;
        if (opt == 'H') {
            cin >> x1;
            insertAsHead(x1);
        } else if (opt == 'I') {
            cin >> x1 >> x2;
            insertAsSucc(x1 - 1, x2);
        } else {
            cin >> x1;
            if (x1 == 0) {
                removeHead();
            } else {
                removeSucc(x1 - 1);
            }
        }
    }
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;
    return 0;
}