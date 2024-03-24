// 23真题2 —— 任务调度
// https://www.luogu.com.cn/problem/U412641
#include <algorithm>
#include <iostream>
#include <list>
#include <map>

using namespace std;

int rd() {
    int  k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? k : -k;
}

void wr(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar((x % 10) ^ '0');
}

int n, m;             // 需要执行的操作数、等待队列的最大容量
int opt, a, x;        // 任务的操作类型、重要性、要插入到的位置
int global_tasks = 0; // 记录全局任务数
struct Task {
    int id = -1; // 任务的编号，初始化任务时id都为-2
    int prior;   // 任务的重要程度
};
list<Task>                     wait_queue; // 任务的等待队列
map<int, list<Task>::iterator> task_map;   // 使用map来快速定位任务

int handle1(int prior) {        // 处理操作1 a ，指的是一个优先级为prior的任务到达，将其添加到等待队列尾部
    global_tasks++;             // 不论成功与否，都会导致全局任务id增加
    if (wait_queue.size() >= m) // 队列已满，添加新任务的操作失败
        return -1;

    wait_queue.push_back({global_tasks, prior});     // 否则就在队列末端添加任务
    task_map[global_tasks] = prev(wait_queue.end()); // 在map中存储任务的迭代器
    return global_tasks;
}

int handle2(int prior, int replace) { // 处理操作2 a x ，指将一个优先级为prior的任务插入到编号为replace的任务之前

    global_tasks++;                                                         // 不论成功与否，都会导致全局任务id增加
    if (wait_queue.size() >= m || task_map.find(replace) == task_map.end()) // 队列已满或未找到指定任务，就报错
        return -1;

    // 在编号replace的任务前插入
    auto it = wait_queue.insert(task_map[replace], {global_tasks, prior});

    task_map[global_tasks] = it; // 同样在map中存储任务迭代器
    return global_tasks;         // 返回新插入任务的id
}

int handle3() {
    if (wait_queue.empty()) return -1; // 如果队列为空，则报错

    int res = wait_queue.front().id; // 否则记录队首元素的id
    task_map.erase(res);             // 从map中删除该task
    wait_queue.pop_front();          // 删除队首元素，代表执行完毕任务
    return res;                      // 返回执行完毕的任务的id
}

int handle4() {
    if (wait_queue.empty()) return -1; // 如果队列为空，则报错

    auto max_it = max_element(wait_queue.begin(), wait_queue.end(), [](const Task &a, const Task &b) {
        return a.prior < b.prior;
    });

    int res = max_it->id; // 记录最大优先级任务的id
    task_map.erase(res);
    wait_queue.erase(max_it); // 从队列中删除，代表完成任务

    return res; // 返回完成任务的id
}

int main() {

    n = rd();
    m = rd();

    while (n--) {
        opt = rd();
        if (opt == 1) {
            a       = rd();
            int res = handle1(a);
            if (res == -1)
                puts("ERR");
            else {
                wr(res);
                putchar('\n');
            }
        } else if (opt == 2) {
            a       = rd();
            x       = rd();
            int res = handle2(a, x);
            if (res == -1)
                puts("ERR");
            else {
                wr(res);
                putchar('\n');
            }
        } else if (opt == 3) {
            int res = handle3();
            if (res == -1)
                puts("ERR");
            else {
                wr(res);
                putchar('\n');
            }
        } else {
            int res = handle4();
            if (res == -1)
                puts("ERR");
            else {
                wr(res);
                putchar('\n');
            }
        }
    }

    return 0;
}