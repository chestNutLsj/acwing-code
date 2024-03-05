// 模拟单向队列
#include <iostream>

using namespace std;

const int N = 100010;
int       queue[N], head = 0, tail = -1;

void enqueue(int x) { queue[++tail] = x; }

void dequeue() { head++; }

int query() { return queue[head]; }

bool isEmpty() {
    if (head <= tail)
        return false;
    else
        return true;
}

int main() {
    int m;
    cin >> m;
    string opt;
    while (m--) {
        cin >> opt;
        if (opt == "push") {
            int x;
            cin >> x;
            enqueue(x);
        } else if (opt == "pop") {
            dequeue();
        } else if (opt == "query") {
            cout << query() << endl;
        } else if (opt == "empty")
            isEmpty() ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}