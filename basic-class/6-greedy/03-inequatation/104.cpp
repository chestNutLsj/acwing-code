// 货仓选址
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    sort(q, q + n);

    int res = 0;
    for (int i = 0; i < n; i++) res += abs(q[i] - q[n / 2]);

    printf("%d\n", res);

    return 0;
}