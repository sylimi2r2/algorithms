#include <iostream>

using namespace std;

int v[10001];
int dp[10001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i=1; i<=n; ++i) {
        cin >> v[i];
    }

    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    for (int i=3; i<=n; ++i) {
        dp[i] = v[i] + max(dp[i - 3] + v[i - 1], dp[i - 2]);
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n];
}