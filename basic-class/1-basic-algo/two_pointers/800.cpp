// 数组元素的目标和
// 利用两个数组的升序性质，通过双指针的方式来减少时间复杂度。具体做法是从数组 A
// 的头部和数组 B
// 的尾部开始进行查找，逐步向中间移动指针，直到找到满足条件的元素对。
#include <iostream>

using namespace std;

const int N = 100010;

int A[N], B[N];

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
        if (A[i] + B[j] == x) {
            cout << i << " " << j;
            return 0;
        } else if (A[i] + B[j] < x)
            i++;
        else
            j--;
    }

    return 0;
}