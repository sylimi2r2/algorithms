#include <iostream>

using namespace std;

int dp[31] = {1, 0, 3};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    if (N % 2 == 1) {
        cout << 0;
        return 0;
    }

    for (int i=4; i<=N; i+=2) {
        dp[i] = 4 * dp[i - 2] - dp[i - 4];
    }

    cout << dp[N];

}