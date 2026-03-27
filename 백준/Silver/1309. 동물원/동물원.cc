#include <iostream>

using namespace std;

const int MOD = 9901;

int dp[100001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    dp[1] = 3;
    dp[2] = 7;
    for (int i=3; i<=N; ++i) {
        dp[i] = (2 * dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << dp[N];
}