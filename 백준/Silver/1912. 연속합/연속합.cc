#include <iostream>

using namespace std;

int dp[100001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int ans = -1001;
    for (int i=1; i<=n; ++i) {
        cin >> dp[i];
        dp[i] += max(0, dp[i - 1]);
        ans = max(ans, dp[i]);
    }

    cout << ans;
}