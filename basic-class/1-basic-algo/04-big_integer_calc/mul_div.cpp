#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// C=A*b
vector<int> mul(vector<int> &A, int b) {
    vector<int> C;

    int t = 0; // carry bit
    for (int i = 0; i < A.size() || t;
         i++) { // 当vector A没有处理完或进位t还存在时，保持在循环中
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

// C = A / b ...... r
vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> C; // quotient
    r = 0;         // reminder
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) { C.pop_back(); }

    return C;
}

int main() {
    string a;
    int b;
    vector<int> A;

    cin >> a >> b; // a="123456"
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0'); // A=[6,5,4,3,2,1]

    // multiply
    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--) { printf("%d", C[i]); }

    // divide
    int r;
    auto D = div(A, b, r);
    for (int i = D.size() - 1; i >= 0; i--) { printf("%d", D[i]); }
}