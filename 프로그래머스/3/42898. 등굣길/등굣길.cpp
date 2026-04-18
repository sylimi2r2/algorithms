#include <string>
#include <vector>

using namespace std;

const int MOD = 1'000'000'007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[1][1] = 1;
    
    for (vector<int>& p: puddles) {
        dp[p[1]][p[0]] = -1;
    }
    
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (dp[i][j] != -1) {
                dp[i][j] += ((dp[i][j - 1] != -1 ? dp[i][j - 1] : 0) + (dp[i - 1][j] != -1 ? dp[i - 1][j] : 0)) % MOD;
            }
        }
    }
    
    return dp[n][m];
}