#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dp[11] = {1, 1, 2};
    int T, n;
    cin >> T;

    for(int i=3; i<=10; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    while(T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}
