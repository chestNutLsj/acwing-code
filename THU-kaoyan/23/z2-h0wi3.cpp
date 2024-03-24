#include <bits/stdc++.h>
using namespace std;

int       ID = 0;
const int N  = 5e5 + 5;

struct Task {
    int a;
    int id;

    Task(int aa) {
        ID++;
        id = ID;
        a  = aa;
    }
};

map<int, list<Task>::iterator> id2it;
map<int, list<Task>::iterator> a2it;
priority_queue<int>            pq;
list<Task>                     l;

int n, m;

void print() {
    cout << "DBG:";
    for (auto i = l.begin(); i != l.end(); i++) {
        cout << "(" << i->id << ',' << i->a << ") ";
    }
    cout << endl;
}

void insert(int a) {
    Task t(a);
    if (l.size() == m)
        cout << "ERR" << endl;
    else {
        l.push_back(t);
        id2it[t.id] = std::prev(l.end());
        a2it[t.a]   = std::prev(l.end());
        pq.push(t.a);
        cout << t.id << endl;
    }
}

void insert_before(int a, int x) {
    Task t(a);
    if (l.size() == m || id2it.find(x) == id2it.end())
        cout << "ERR" << endl;
    else {
        auto it     = l.insert(id2it[x], t);
        id2it[t.id] = it;
        a2it[t.a]   = it;
        pq.push(t.a);
        cout << t.id << endl;
    }
}

void pop_front() {
    if (l.empty())
        cout << "ERR" << endl;
    else {
        auto &t = l.front();
        cout << t.id << endl;
        id2it.erase(t.id);
        a2it.erase(t.a);
        l.pop_front();
    }
}

void pop_top() {
    if (l.empty()) {
        cout << "ERR" << endl;
    } else {
        while (not pq.empty()) {
            auto a = pq.top();
            if (a2it.find(a) == a2it.end())
                pq.pop();
            else {
                auto it = a2it[a];
                cout << it->id << endl;
                id2it.erase(it->id);
                a2it.erase(it->a);
                l.erase(it);
                pq.pop();
                break;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    while (n--) {
        int op, a, x;
        cin >> op;
        if (op == 1) {
            cin >> a;
            insert(a);
        } else if (op == 2) {
            cin >> a >> x;
            insert_before(a, x);
        } else if (op == 3) {
            pop_front();
        } else if (op == 4) {
            pop_top();
        }
        // print();
    }
}