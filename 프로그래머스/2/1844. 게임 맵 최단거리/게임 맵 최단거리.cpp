#include <vector>
#include <queue>

using namespace std;

pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, 0));
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    
    while (!q.empty()) {
        auto [curX, curY] = q.front();
        q.pop();
        
        if (curX == n - 1 && curY == m - 1) {
            return dist[curX][curY];
        }
        
        for (auto [dx, dy]: directions) {
            int nextX = curX + dx;
            int nextY = curY + dy;
            
            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
            if (maps[nextX][nextY] == 0 || dist[nextX][nextY] != 0) continue;
            
            q.push({nextX, nextY});
            dist[nextX][nextY] = dist[curX][curY] + 1;
        }
    }
    
    return -1;
}