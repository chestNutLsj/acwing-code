// 模拟栈
#include <iostream>

using namespace std;

const int N = 100010;

int stack[N], sp = 0;

void push(int x) { stack[++sp] = x; }

void pop() { sp--; }

int top() { return stack[sp]; }

bool isEmpty() {
    if (sp > 0)
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
            push(x);
        } else if (opt == "pop") {
            pop();
        } else if (opt == "query") {
            cout << top() << endl;
        } else if (opt == "empty")
            isEmpty() ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}