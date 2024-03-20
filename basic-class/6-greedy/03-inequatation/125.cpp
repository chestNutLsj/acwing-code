// 耍杂技的🐮
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> PLL;

const int N = 50010;

int n;
PLL cow[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int s, w;
        scanf("%d%d", &w, &s);
        cow[i] = {w + s, w};
    }

    sort(cow, cow + n);

    int res = -2e9, sum = 0;
    for (int i = 0; i < n; i++) {
        int s = cow[i].first - cow[i].second, w = cow[i].second;
        res = max(res, sum - s);
        sum += w;
    }

    printf("%d\n", res);

    return 0;
}