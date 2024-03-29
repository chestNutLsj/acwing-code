#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int              N = 100010;
typedef pair<int, int> PLL;

void merge(vector<PLL> &segs) {
    vector<PLL> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first) {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        } else
            ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}

int main() {
    int         n;
    vector<PLL> intervals;
    cin >> n;
    for (int i = 0; i < n; i++) {
        PLL interval;
        cin >> interval.first >> interval.second;
        intervals.push_back(interval);
    }
    merge(intervals);
    cout << intervals.size();

    return 0;
}