#include <iostream>

using namespace std;

const int MOD = 1'000'000'000;
int dp[201][201];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    for (int k=0; k<=K; ++k) {
        dp[0][k] = 1;
    }
    for (int n=0; n<=N; ++n) {
        dp[n][1] = 1;
    }

    for (int n=1; n<=N; ++n) {
        for (int k=2; k<=K; ++k) {
            dp[n][k] = (dp[n][k - 1] + dp[n - 1][k]) % MOD;
        }
    }

    cout << dp[N][K];
}