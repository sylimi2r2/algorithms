#include <iostream>

using namespace std;

int dp[17];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i=1; i<=N; ++i) {
        int period, price;
        cin >> period >> price;

        dp[i] = max(dp[i], dp[i - 1]);
        int fin = i + period;
        if (fin <= N + 1) {
            dp[fin] = max(dp[fin], dp[i] + price);
        }
    }
    dp[N + 1] = max(dp[N + 1], dp[N]);

    cout << dp[N + 1];
}