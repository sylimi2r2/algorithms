#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int w[10001] = {0,};
    int dp[10001] = {0,};
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> w[i];
    }

    dp[1] = w[1];
    dp[2] = w[1]+w[2];

    for(int i=3; i<=n; i++) {
        dp[i] = w[i] + max(w[i-1]+dp[i-3], dp[i-2]);
        dp[i] = max(dp[i-1], dp[i]);
    }

    cout << dp[n];
}
