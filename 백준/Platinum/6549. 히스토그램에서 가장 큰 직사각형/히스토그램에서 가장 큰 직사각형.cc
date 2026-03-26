#include <iostream>
#include <vector>
using namespace std;

int n;
int input;
vector<int> hist;

long long solve(int left, int right) {
    if (left == right) {
        return hist[left];
    }

    int mid = (left + right) / 2;
    long long ret = max(solve(left, mid), solve(mid + 1, right));

    int lo = mid;
    int hi = mid + 1;
    int height = min(hist[lo], hist[hi]);
    ret = max(ret, (long long)height * 2);
    while (left < lo || hi < right) {
        if (hi < right && (left == lo || hist[lo - 1] < hist[hi + 1])) {
            height = min(height, hist[++hi]);
        }
        else {
            height = min(height, hist[--lo]);
        }
        ret = max(ret, (long long) height * (hi - lo + 1));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        hist.clear();
        for (int i = 0; i < n; ++i) {
            cin >> input;
            hist.emplace_back(input);
        }

        cout << solve(0, hist.size() - 1) << '\n';
    }
}
