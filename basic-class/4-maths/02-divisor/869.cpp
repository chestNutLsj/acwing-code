// 试除法求约数
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> res;
        // 因为约数成对出现，所以只需要循环到根号x
        //  不要是用 i *i <= n，因为可能溢出
        for (int i = 1; i <= n / i; i++) {
            if (n % i == 0) {
                res.push_back(i);
                // 如果i * i = x,添加i即可，不用添加 x / i
                if (n / i != i)
                    res.push_back(n / i);
            }
        }
        sort(res.begin(), res.end());
        for (auto x : res) cout << x << " ";
        cout << endl;
    }
}