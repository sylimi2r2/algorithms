#include <iostream>

using namespace std;

const int MOD = 1'000'000'009;

int dp[1000001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int T;
    cin >> T;

    int i = 4;
    while (T--) {
        int n;
        cin >> n;

        for (; i<=n; ++i) {
            dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
        }

        cout << dp[n] << '\n';
    }
}