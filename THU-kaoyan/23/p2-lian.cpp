#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

const int N = 1e6 + 10;

int           n, m;
int           e[N], l[N], r[N];
int           idx, count;
map<int, int> mp;

void init() {
    l[-1] = 0, r[0] = -1;
    idx = 1;
}

void add(int k, int x) {
    e[idx]  = x;
    l[idx]  = k;
    r[idx]  = r[k];
    l[r[k]] = idx;
    r[k]    = idx;
    idx++;
    count++;
}

void remove1() {
    if (!count) {
        printf("ERR\n");
        return;
    }
    int id  = r[0];
    int tmp = e[id];
    mp.erase(tmp);
    r[0]    = r[id];
    l[r[0]] = 0;
    count--;
    printf("%d\n", id);
    r[id] = -2;
}

void remove2() {
    if (!count) {
        printf("ERR\n");
        return;
    }
    auto tmp = mp.end();
    tmp--;
    int id = tmp->second;
    mp.erase(tmp->first);
    printf("%d\n", id);
    r[l[id]] = r[id];
    l[r[id]] = l[id];
    r[id]    = -2;
    count--;
}

int main(void) {

    cin >> n >> m;

    init();

    while (n--) {
        int x;
        cin >> x;
        if (x == 1) {
            int imp;
            cin >> imp;
            if (count == m) {
                printf("ERR\n");
                idx++;
            } else {

                mp[imp] = idx;
                printf("%d\n", idx);
                add(l[-1], imp);
            }
        } else if (x == 2) {
            int imp, x1;
            cin >> imp >> x1;
            bool flag = false;
            if (r[x1] == -2 || r[x1] == 0) flag = true;
            if (count == m || flag) {
                printf("ERR\n");
                idx++;
            } else {
                mp[imp] = idx;
                printf("%d\n", idx);
                add(l[x1], imp);
            }
        } else if (x == 3) {
            remove1();
        } else if (x == 4) {
            remove2();
        }
    }

    return 0;
}