#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    
    vector<vector<int>> info(n, vector<int>(m, -1));
    vector<int> sizes;
    
    int idx = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (land[i][j] == 0 || info[i][j] != -1) continue;
            
            queue<pair<int, int>> q;
            q.push({i, j});
            info[i][j] = idx;
            sizes.push_back(0);
            
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                ++sizes[idx];
                
                for (auto [dx, dy]: directions) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (land[nx][ny] == 0 || info[nx][ny] != -1) continue;
                    
                    q.push({nx, ny});
                    info[nx][ny] = idx;
                }
            }
            
            ++idx;
        }
    }
    
    int s = sizes.size();
    for (int j=0; j<m; ++j) {
        int tmp = 0;
        vector<bool> found(s, false);
        for (int i=0; i<n; ++i) {
            if (info[i][j] != -1) {
                found[info[i][j]] = true;
            }
        }
        
        for (int i=0; i<s; ++i) {
            if (found[i]) {
                tmp += sizes[i];
            }
        }
        
        answer = max(answer, tmp);
    }
    
    return answer;
}