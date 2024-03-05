// 单调栈（STL实现）
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* int main() {
    int n;
    cin >> n;
    stack<int> stk; // 使用STL中的stack

    while (n--) {
        int x;
        cin >> x;                                         // 使用cin来代替scanf
        while (!stk.empty() && stk.top() >= x) stk.pop(); // 如果栈顶元素大于当前待入栈元素，则出栈
        if (stk.empty())
            cout << "-1 "; // 如果栈空，则没有比该元素小的值。
        else
            cout << stk.top() << " "; // 栈顶元素就是左侧第一个比它小的元素。
        stk.push(x);
    }
    return 0;
} */

int main() {
    int n;
    cin >> n;
    vector<int> stk; // 使用vector来模拟栈

    while (n--) {
        int x;
        cin >> x; // 直接使用cin读取输入，代替scanf
        while (!stk.empty() && stk.back() >= x)
            stk.pop_back(); // 如果栈顶元素大于当前待入栈元素，则出栈
        if (stk.empty())
            cout << "-1 "; // 如果栈空，则没有比该元素小的值。
        else
            cout << stk.back() << " "; // 栈顶元素就是左侧第一个比它小的元素。
        stk.push_back(x);              // 入栈操作
    }
    return 0;
}
