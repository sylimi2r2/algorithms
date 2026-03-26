#include <iostream>
using namespace std;

#define INF 1000000000

int N;
int cost[1001][3];
int dp[1001][3];
int answer = INF;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for (int i = 0; i < 3; i++) {
        dp[1][0] = INF;
        dp[1][1] = INF;
        dp[1][2] = INF;
        dp[1][i] = cost[1][i];

        for (int j = 2; j <= N; j++) {
            dp[j][0] = cost[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
            dp[j][1] = cost[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
            dp[j][2] = cost[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
        }
        dp[N][i] = INF;

        answer = min(answer, min(dp[N][0], min(dp[N][1], dp[N][2])));
    }

    cout << answer;
}
