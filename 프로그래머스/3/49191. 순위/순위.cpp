#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> win(n + 1, vector<bool>(n + 1, false));
    
    for (const vector<int>& r: results) {
        win[r[0]][r[1]] = true;
    }
    
    for (int k=1; k<=n; ++k) {
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                if (win[i][k] && win[k][j]) {
                    win[i][j] = true;
                }
            }
        }
    }
    
    for (int i=1; i<=n; ++i) {
        int cnt = 0;
        for (int j=1; j<=n; ++j) {
            if (win[i][j] || win[j][i]) {
                ++cnt;
            }
        }
        
        if (cnt == n - 1) {
            ++answer;
        }
    }
    
    return answer;
}