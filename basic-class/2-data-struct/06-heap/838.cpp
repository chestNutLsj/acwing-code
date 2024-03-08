// heap sort（小顶堆）
#include <iostream>

using namespace std;

const int N = 100010;
int       h[N];  // h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
int       ph[N]; // ph[k]存储第k个插入的点在堆中的位置
int       hp[N]; // hp[k]存储堆中下标是k的点是第几个插入的
int       hsize; // 堆的规模

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

void up(int u) {                       // 上滤
    while (u / 2 && h[u] < h[u / 2]) { // 从指定节点开始，如果节点值小于父节点的值，则与父节点交换
        heap_swap(u, u / 2);           // 直到到达根节点或父节点的值小于当前节点
        u >>= 1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    hsize = n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = n / 2; i; i--) { // 自底向上建堆：从最后一个非叶子节点开始（即n/2），向上至根节点，依次执行down操作
        down(i);                  // 这个过程确保每个子堆都满足小顶堆的性质。
    }
    while (m--) {
        cout << h[1] << " ";
        h[1] = h[hsize--]; // 用最后一个元素替换根节点：将堆的最后一个元素移动到根节点，同时堆大小减一。
        down(1);
    }
    return 0;
}