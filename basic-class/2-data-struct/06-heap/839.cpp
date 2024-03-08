// 模拟堆
#include <iostream>

using namespace std;

const int N = 100010;
int       h[N];      // h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
int       ph[N];     // ph[k]存储第k个插入的点在堆中的位置
int       hp[N];     // hp[k]存储堆中下标是k的点是第几个插入的
int       hsize = 0; // 堆的规模

void heap_swap(int a, int b) { // 交换两个点，及其映射关系
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) { // 下滤
    int t = u;
    if (u * 2 <= hsize && h[u * 2] < h[t]) t = u * 2; // 从指定节点开始，比较节点与其子节点的值，
    if (u * 2 + 1 <= hsize && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) { // 将其与两个子节点中较小的一个交换，直到节点值小于其子节点或已经是叶子节点
        heap_swap(u, t);
        down(t);
    }
}

void up(int u) { // 上滤
    while (u / 2 && h[u] < h[u / 2]) {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main() {
    int n, m = 0;
    cin >> n;
    while (n--) {
        string opt;
        int    k, x;
        cin >> opt;
        if (opt == "I") { // 插入x
            cin >> x;
            h[++hsize] = x;
            m++;
            ph[m]     = hsize; // 更新ph数组
            hp[hsize] = m;     // 更新hp数组
            up(hsize);
        } else if (opt == "PM") {
            cout << h[1] << endl;
        } else if (opt == "DM") {
            heap_swap(1, hsize);
            hsize--;
            down(1);
        } else if (opt == "D") {
            cin >> k;
            int tmp = ph[k];
            heap_swap(tmp, hsize);
            hsize--;
            down(tmp);
            up(tmp);

        } else {
            cin >> k >> x;
            int tmp = ph[k];
            h[tmp]  = x;
            down(tmp);
            up(tmp);
        }
    }
    return 0;
}