#include <iostream>

using namespace std;

int dp[100001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i=1; i<=N; ++i) {
        dp[i] = i;
        for (int j=1; j*j<=i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[N];
}