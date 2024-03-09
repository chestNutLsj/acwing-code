#include <iostream>
using namespace std;
const int N = 10;
int       st[N], used[N];
int       n;

bool valid(int u) { // 判断函数，因为使用了used记录，所以一定不会在同一列，只需要判断对角线
    for (int i = 1; i < u; i++) {
        if ((abs((u - i)) == abs(st[u] - st[i])))
            return false;
    }
    return true;
    /*
    这里用到了数学知识 |u-i| == |st[u] - st[i]|，大家画个图一看就明白了

    比如st为{1,3,2,4}，列为1,2,3,4
    Q . . .
    . . Q .
    . Q . .
    . . . Q
    第3列 减 第2列 为 3 - 2 = 1
    |st[3] - st[1]| = |2 - 3| = 1
    所以在同一对角线
    */
}

// dfs模板
void dfs(int u) {
    // 结束条件，按st里的数字决定是Q还是.
    if (u > n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j == st[i])
                    cout << 'Q';
                else {
                    cout << '.';
                }
            }
            puts("");
        }
        puts(""); // 答案之间有一个空行
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) {
            st[u] = i;
            if (!valid(u)) {
                st[u] = 0;
                continue; // 如果当前数字不行，则跳过该数字，且不用改变used
            }
            used[i] = 1;
            dfs(u + 1); // 恢复现场
            used[i] = 0;
            st[u]   = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}
