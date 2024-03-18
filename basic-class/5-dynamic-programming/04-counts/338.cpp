// 计数问题
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 10;
/*

001~abc-1, 999

abc
    1. num[i] < x, 0
    2. num[i] == x, 0~efg
    3. num[i] > x, 0~999

*/

int get(vector<int> num, int l, int r) { // 因为我们举的分类中，有需要求出一串数字中某个区间的数字，例如abcdefg有一个分类需要求出efg+1
    int res = 0;
    for (int i = l; i >= r; i--) res = res * 10 + num[i]; // 这里从小到大枚举是因为下面count的时候读入数据是从最低位读到最高位，那么此时在num里，最高位存的就是数字的最低位，那么假如我们要求efg，那就是从2算到0
    return res;
}

int power10(int i) { // 这里有power10是因为有一个分类需要求得十次方的值，例如abc*10^3
    int res = 1;
    while (i--) res *= 10;
    return res;
}

int count(int n, int x) {
    if (!n) return 0;

    vector<int> num; // num存储数中每一位的数字
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size(); // 长度

    int res = 0;
    for (int i = n - 1 - !x; i >= 0; i--) // 这里需要注意，我们的长度需要减一，是因为num是从0开始存储，而长度是元素的个数，因此需要减1才能读到正确的数值，而!x出现的原因是因为我们不能让前导零出现，如果此时需要我们列举的是0出现的次数，那么我们自然不能让他出现在第一位，而是从第二位开始枚举
    {
        if (i < n - 1) // 其实这里可以不用if判断，因为for里面实际上就已经达成了if的判断，但为了方便理解还是加上if来理解，这里i要小于n-1的原因是因为我们不能越界只有7位数就最高从七位数开始读起
        {
            res += get(num, n - 1, i + 1) * power10(i); // 这里就是第一个分类，000~abc-1,那么此时情况个数就会是abc*10^3，这里的3取决于后面efg的长度，假如他是efgh，那么就是4
            // 这里的n-1，i-1，自己将数组列出来然后根据分类标准就可以得出为什么l是n-1，r是i-1
            if (!x) res -= power10(i); // 假如此时我们要列举的是0出现的次数，因为不能出现前导零，这样是不合法也不符合我们的分类情况，例如abcdefg我们列举d，那么他就得从001~abc-1，这样就不会直接到efg，而是会到0efg，因为前面不是前导零，自然就可以列举这个时候0出现的次数，所以要减掉1个power10
        }
        // 剩下的这两个就直接根据分类标准来就好了
        if (num[i] == x)
            res += get(num, i - 1, 0) + 1;
        else if (num[i] > x)
            res += power10(i);
    }
    return res; // 返回res，即出现次数
}

int main() {
    int a, b;
    while (cin >> a >> b, a) // 读入数据，无论a，b谁是0，都是终止输入，因为不会有数字从零开始（a，b>0）
    {
        if (a > b) swap(a, b);                            // 因为我们需要从小到大，因此如果a大于b，那么就得交换，使得a小于b
        for (int i = 0; i <= 9; i++)                      // 列举a和b之间的所有数字中 0∼9的出现次数
            cout << count(b, i) - count(a - 1, i) << ' '; // 这里有点类似前缀和，要求a和b之间，那么就先求0到a i出现的次数，再求0到b i出现的次数，最后再相减就可以得出a和b之间i出现的次数
        cout << endl;
    }
    return 0;
}