// Floyd
#include <iostream>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;
int       n, m, k;
int       dist[N][N]; // 记录a-->b的距离

void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
}

void floyd() {

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    cin >> n >> m >> k;
    init();
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        dist[x][y] = min(dist[x][y], z);
    }
    floyd();
    while (k--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] > INF / 2)
            cout << "impossible" << endl;
        else
            cout << dist[a][b] << endl;
    }
    return 0;
}