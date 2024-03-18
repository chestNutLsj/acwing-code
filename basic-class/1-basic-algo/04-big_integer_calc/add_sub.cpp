#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
}

vector<int> sub(vector<int> &A, vector<int> &B) {
}

// Determine whether A>=B or not
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i]) return A[i] > B[i];
    return true;
}

int main() {
    string a, b;
    vector<int> A, B;

    cin >> a >> b; // a="123456"
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(
            a[i]
            - '0'); // A=[6,5,4,3,2,1]，之所以要减'0'，是为了将字符转换为int
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    // add
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--) { printf("%d", C[i]); }

    // subtract
    if (cmp(A, B)) {
        auto D = sub(A, B);
        for (int i = D.size() - 1; i >= 0; i--) { printf("%d", D[i]); }
    } else {
        auto D = sub(B, A);
        printf("-");
        for (int i = D.size() - 1; i >= 0; i--) { printf("%d", D[i]); }
    }
}