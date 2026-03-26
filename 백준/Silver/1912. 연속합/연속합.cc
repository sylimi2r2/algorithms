#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dp[100001] = {0,};
    int n, sol=-1000;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> dp[i];
        dp[i] = max(dp[i], dp[i]+dp[i-1]);
        sol = max(sol, dp[i]);
    }

    cout << sol;
}
