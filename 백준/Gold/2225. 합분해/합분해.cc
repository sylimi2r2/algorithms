#include <iostream>

using namespace std;

const int MOD = 1'000'000'000;
int dp[201][201];

int sol(int n, int k) {
    int &ret = dp[n][k];

    if (ret != -1)
        return ret;

    if (n == 0 || k == 1)
        return ret = 1;

    ret = 0;

    for (int i=0; i<=n; ++i) {
        ret = (ret + sol(n - i, k - 1)) % MOD;
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    fill(*dp, *dp + 201 * 201, -1);

    cout << sol(N, K);
}