#include <iostream>

using namespace std;

const int MOD = 10007;
int dp[1001][10] = {{}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i=2; i<=N; ++i) {
        dp[i][0] = 1;
        for (int j=1; j<10; ++j) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    int ans = 0;
    for (int i=0; i<10; ++i) {
        ans = (ans + dp[N][i]) % MOD;
    }

    cout << ans;
}