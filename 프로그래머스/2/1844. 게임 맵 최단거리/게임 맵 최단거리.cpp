#include <vector>
#include <queue>
#include <tuple>

using namespace std;

pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 1});
    visited[0][0] = true;
    
    while (!q.empty()) {
        auto [curX, curY, curD] = q.front();
        q.pop();
        
        if (curX == n - 1 && curY == m - 1) {
            return curD;
        }
        
        for (auto [dx, dy]: directions) {
            int nextX = curX + dx;
            int nextY = curY + dy;
            
            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
            if (maps[nextX][nextY] == 0 || visited[nextX][nextY]) continue;
            
            q.push({nextX, nextY, curD + 1});
            visited[nextX][nextY] = true;
        }
    }
    
    return -1;
}