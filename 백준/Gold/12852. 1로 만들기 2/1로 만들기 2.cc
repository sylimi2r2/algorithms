#include <iostream>
using namespace std;

int N;
int dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[0] = -1;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    cin >> N;
    for(int i=4; i<=N; i++) {
        if(i%6==0) {
            dp[i] = min(dp[i/2], min(dp[i/3], dp[i-1])) + 1;
        }
        else if(i%2==0) {
            dp[i] = min(dp[i/2], dp[i-1]) + 1;
        }
        else if(i%3==0) {
            dp[i] = min(dp[i/3], dp[i-1]) + 1;
        }
        else
            dp[i] = dp[i-1] + 1;
    }

    cout << dp[N] << '\n';

    while(N) {
        cout << N << ' ';

        if(dp[N] == dp[N-1]+1)
            N -= 1;
        else if(N%2 == 0 && dp[N] == dp[N/2]+1)
            N /= 2;
        else if(N%3 == 0 && dp[N] == dp[N/3]+1)
            N /= 3;
    }
}