// 滑雪
#include <iostream>

using namespace std;

const int N = 310;
int       ski_ground[N][N]; // 记录滑雪场（矩阵的数据）
int       n, m;             // 滑雪场的长宽，即矩阵的尺寸
int       f[N][N];          // f[i][j]表示所有从(i,j)点开始划的路径的最大长度
int       dx[4] = {-1, 0, 1, 0},
    dy[4]       = {0, 1, 0, -1}; // 左上右下四个方向移动

int slide_dist(int x, int y) { // 从坐标(x,y)可以往下滑动的最远距离
    int &v = f[x][y];
    if (v != -1) return v; // 如果已经滑过该点，直接返回该点可滑动的最远距离f[x][y]即可

    v = 1;                                // 至少能在本点滑动
    for (int i = 0; i < 4; i++) {         // 试探性地向四个方向移动
        int a = x + dx[i], b = y + dy[i]; // 从(x,y)移动后的坐标(a,b)
        if (a >= 1 && a <= n && b >= 1 && b <= m && ski_ground[x][y] > ski_ground[a][b])
            //(a,b)不能越界，且移动至少一步，且高度应比(x,y)要小
            v = max(v, slide_dist(a, b) + 1); // 递归地查找该点的最长移动距离
    }
    return v;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> ski_ground[i][j];
    fill(f[0], f[0] + N * N, -1);

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res = max(res, slide_dist(i, j));

    cout << res << endl;

    return 0;
}