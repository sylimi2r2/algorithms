#include <iostream>

using namespace std;

const int MOD = 1'000'000'009;
int dp[100001][3];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    for (int i=4; i<=100000; ++i) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % MOD;
        dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % MOD;
    }

    while (T--) {
        int n;
        cin >> n;

        cout << ((dp[n][0] + dp[n][1]) % MOD + dp[n][2]) % MOD << '\n';
    }
}