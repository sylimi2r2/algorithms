#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> cost(N);
    vector<vector<int>> dp(N);
    for(int i=0; i<N; i++) {
        int R, G, B;
        cin >> R >> G >> B;
        cost[i] = {R, G, B};
    }
    dp[0] = {cost[0][0], cost[0][1], cost[0][2]};

    for(int i=1; i<N; i++) {
        dp[i] = {
                min(dp[i-1][1]+cost[i][0], dp[i-1][2]+cost[i][0]),
                min(dp[i-1][0]+cost[i][1], dp[i-1][2]+cost[i][1]),
                min(dp[i-1][0]+cost[i][2], dp[i-1][1]+cost[i][2]),
        };
    }

    cout << min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
}
