#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dp[300], stair[300];
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> stair[i];
    }

    dp[0] = stair[0];
    dp[1] = stair[0]+stair[1];
    dp[2] = max(stair[0]+stair[2], stair[1]+stair[2]);

    for(int i=3; i<n; i++) {
        dp[i] = max(stair[i]+dp[i-2], stair[i]+stair[i-1]+dp[i-3]);
    }

    cout << dp[n-1];
}
