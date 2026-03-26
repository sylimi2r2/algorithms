#include <string>
#include <vector>
#include <string.h>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int sol = n;
    int num = info.size();
    int dp[40][120] = {0,};
    memset(dp, -1, sizeof(int)*40*120);
    dp[0][0] = info[0][0];
    dp[0][info[0][1]] = 0;
    for (int i=1; i<num; ++i) {
        for (int j=0; j<m; ++j) {
            if (dp[i-1][j] != -1) {
                dp[i][j+info[i][1]] = dp[i-1][j];
                dp[i][j] = min(dp[i-1][j] + info[i][0], (dp[i][j] != -1 ? dp[i][j] : n));
                if (dp[i][j] >= n) {
                    dp[i][j] = -1;
                }
            }
        }
    }
    for (int i=0; i<m; ++i) {
        if (dp[num-1][i] != -1) {
            sol = min(sol, dp[num-1][i]);
        }
    }
    return (sol < n ? sol : -1);
}