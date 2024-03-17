// 编辑距离
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e1 + 5, M = 1e3 + 10; // N是字符串的最大长度+5，M是字符串的最大数量+10

int  n, m;      // n是给定字符串的数量，m是查询的数量
char str[M][N]; // 存储给定的字符串
int  f[N][N];   // 动态规划表，f[i][j]表示字符串a的前i个字符到字符串b的前j个字符的最小编辑距离

// 计算两个字符串a和b之间的编辑距离
int edit_distance(char a[], char b[]) {
    int la = strlen(a + 1), lb = strlen(b + 1); // 计算字符串a和b的长度
    // 初始化边界情况
    for (int i = 0; i <= lb; i++) {
        f[0][i] = i; // a为空字符串时，将b转换成a需要的操作数等于b的长度
    }
    for (int i = 0; i <= la; i++) {
        f[i][0] = i; // b为空字符串时，将a转换成b需要的操作数等于a的长度
    }
    // 动态规划计算编辑距离
    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            // 计算删除、插入和替换操作中的最小值
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);          // 分别对应于删除和插入操作
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j])); // 对应于替换操作或者字符匹配时无需操作
        }
    }
    return f[la][lb]; // 返回两个字符串的最小编辑距离
}

int main() {
    cin >> n >> m; // 输入字符串数量和查询数量
    for (int i = 0; i < n; i++) {
        cin >> (str[i] + 1); // 读取每个字符串
    }

    while (m--) {                // 对每个查询进行处理
        int  res = 0;            // 记录满足条件的字符串数量
        char s[N];               // 查询的目标字符串
        int  limit;              // 编辑距离的限制
        cin >> (s + 1) >> limit; // 读取目标字符串和编辑距离限制
        for (int i = 0; i < n; i++) {
            // 对每个给定的字符串计算与目标字符串的编辑距离
            if (edit_distance(str[i], s) <= limit) {
                res++; // 如果编辑距离小于等于限制，则计数器加一
            }
        }
        cout << res << endl; // 输出满足条件的字符串数量
    }

    return 0;
}
