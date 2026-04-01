#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> prev(n + 1, 0);
    cin >> prev[1];
    for (int i=2; i<=n; ++i) {
        vector<int> cur(i + 1);
        for (int j=1; j<=i; ++j) {
            cin >> cur[j];
        }

        prev[i] = prev[i - 1] + cur[i];
        for (int j=i-1; j>1; --j) {
            prev[j] = max(prev[j-1], prev[j]) + cur[j];
        }
        prev[1] += cur[1];
    }

    cout << *max_element(prev.begin() + 1, prev.begin() + n + 1);
}