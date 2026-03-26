#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[15][15];
    for(int i=0; i<15; i++) {
        dp[0][i] = i;
        dp[i][1] = 1;
    }
    for(int i=1; i<15; i++) {
        for(int j=2; j<15; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    int T, k, n;
    cin >> T;

    for(int i=0; i<T; i++) {
        cin >> k >> n;
        cout << dp[k][n] << "\n";
    }
}
