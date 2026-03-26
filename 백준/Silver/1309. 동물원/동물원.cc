#include <iostream>
using namespace std;

int dp[100001];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[1] = 3;
    dp[2] = 7;

    cin >> N;
    for(int i=3; i<=N; i++) {
        dp[i] = (2*dp[i-1]+dp[i-2]) % 9901;
    }

    cout << dp[N];
}
