#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> PLL;

const int N = 110;
int       g[N][N]; // 存储地图
int       f[N][N]; // 存储距离
int       n, m;

void bfs(int a, int b) // 广度优先遍历
{
    queue<PLL> q;
    q.push({a, b});

    while (!q.empty()) {
        PLL start = q.front();
        q.pop();

        int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) // 往四个方向走
        {
            // 当前点能走到的点
            int x = start.first + dx[i], y = start.second + dy[i];
            // 如果还没有走过
            if (g[x][y] == 0) {
                // 走到这个点，并计算距离
                g[x][y] = 1;
                f[x][y] = f[start.first][start.second] + 1; // 从当前点走过去，则距离等于当前点的距离+1.
                // 这个点放入队列，用来走到和它相邻的点。
                q.push({x, y});
            }
        }
    }
    cout << f[n][m] << endl;
}

void bfs_print() {
    int        target = f[n][m];
    queue<PLL> q;
    q.push({n, m});
    cout << n << " " << m << endl;
    while (!q.empty()) {
        PLL start = q.front();
        q.pop();

        int dx[4] {0, 1, 0, -1}, dy[4] {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + start.first, y = dy[i] + start.second;
            if (x >= 1 && y >= 1 && x <= n && x <= m && f[x][y] == target - 1) {
                q.push({x, y});
                cout << x << " " << y << endl;
            }
        }
        target--;
        if (target == 1) {
            break;
        }
    }
}

int main() {
    memset(g, 1, sizeof(g));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    bfs(1, 1);
    // bfs_print();

    return 0;
}