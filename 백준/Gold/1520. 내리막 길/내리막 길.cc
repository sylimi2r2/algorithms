#include <iostream>
using namespace std;

int M, N;
int map[501][501];
int dp[501][501] = {0,};
pair<int, int> directions[4] = {{0, 1}, {0, -1},
                                {1, 0}, {-1, 0}};

int dfs(int m, int n) {
    if(dp[m][n] != -1)
        return dp[m][n];

    if(m==M && n==N)
        return 1;

    dp[m][n] = 0;
    for(pair<int, int> d : directions) {
        int nextM = m + d.first;
        int nextN = n + d.second;
        if(nextM>=1 && nextM<=M && nextN>=1 && nextN<=N)
            if(map[m][n] > map[nextM][nextN])
                dp[m][n] += dfs(nextM, nextN);
    }

    return dp[m][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N;
    for(int i=1; i<=M; i++)
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }

    dfs(1, 1);

    cout << dp[1][1];
}
