// 单调栈
#include <iostream>
using namespace std;
const int N = 100010;
int       stk[N], tt;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        scanf("%d", &x);
        while (tt && stk[tt] >= x) tt--; // 如果栈顶元素大于当前待入栈元素，则出栈
        if (!tt)
            printf("-1 "); // 如果栈空，则没有比该元素小的值。
        else
            printf("%d ", stk[tt]); // 栈顶元素就是左侧第一个比它小的元素。
        stk[++tt] = x;
    }
    return 0;
}