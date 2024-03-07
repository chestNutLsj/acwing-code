// 食物链
#include <iostream>

using namespace std;

const int N = 500010;
int       fa[N];

inline void init(int n) {
    for (int i = 1; i <= n; i++) { fa[i] = i; }
}

int find(int a) {}

inline void merge(int a, int b) {}

int main() {
    int n, k;
    cin >> n >> k;
    init(n);
    int opt;
    while (k--) {
        cin >> opt;
        if (opt == 1) {

        } else {
            /* code */
        }
    }
}