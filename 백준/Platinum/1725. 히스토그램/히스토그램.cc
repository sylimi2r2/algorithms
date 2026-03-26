#include <iostream>
#include <vector>
using namespace std;

int N;
int input;
vector<int> hist;

int solve(int left, int right) {
    if (left == right) {
        return hist[left];
    }

    int mid = (left + right) / 2;
    int ret = max(solve(left, mid), solve(mid + 1, right));

    int lo = mid;
    int hi = mid + 1;
    int height = min(hist[lo], hist[hi]);
    ret = max(ret, height * 2);

    while (left < lo || hi < right) {
        if (hi < right && (left == lo || hist[lo - 1] < hist[hi + 1])) {
            height = min(height, hist[++hi]);
        }
        else {
            height = min(height, hist[--lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        hist.emplace_back(input);
    }

    cout << solve(0, hist.size() - 1);
}
