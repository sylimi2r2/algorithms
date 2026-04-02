#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> dp(N);
    vector<int> forward;
    vector<int> reverse;
    for (int i=0; i<N; ++i) {
        cin >> A[i];

        auto it = lower_bound(forward.begin(), forward.end(), A[i]);
        if (it == forward.end()) {
            forward.push_back(A[i]);
            dp[i] = forward.size();
        }
        else {
            *it = A[i];
            dp[i] = it - forward.begin() + 1;
        }
    }

    for (int i=N-1; i>=0; --i) {
        auto it = lower_bound(reverse.begin(), reverse.end(), A[i]);
        if (it == reverse.end()) {
            reverse.push_back(A[i]);
            dp[i] += reverse.size();
        }
        else {
            *it = A[i];
            dp[i] += it - reverse.begin() + 1;
        }
    }

    cout << *max_element(dp.begin(), dp.end()) - 1;
}