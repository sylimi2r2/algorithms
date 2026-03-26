#include <iostream>
using namespace std;

#define MOD 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dp[101][10] = {0,};
    int N;
    cin >> N;

    for(int i=1; i<10; i++) {
        dp[1][i] = 1;
    }

    for(int i=2; i<=N; i++) {
        for(int j=0; j<10; j++) {
            if(j == 0)
                dp[i][j] = dp[i-1][1];
            else if(j == 9)
                dp[i][j] = dp[i-1][8];
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
    }

    int sum = 0;
    for(int i=0; i<10; i++) {
        sum = (sum + dp[N][i]) % MOD;
    }

    cout << sum;
}
