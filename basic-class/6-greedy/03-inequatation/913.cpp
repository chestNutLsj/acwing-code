#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> heap;
    while (n--) {
        int x;
        scanf("%d", &x);
        heap.push(x);
    }
    long long res = 0;
    while (heap.size() > 1) {
        int a = heap.top();
        heap.pop();
        res += a * heap.size();
    }
    cout << res << endl;
    return 0;
}