#include<vector>
#include <queue>
using namespace std;

pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool visited[100][100] = {0,};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    queue<vector<int>> q;
    q.push({0, 0, 1});
    visited[0][0] = true;
    while (!q.empty()) {
        vector<int> cur = q.front();
        int cx = cur[0];
        int cy = cur[1];
        int cc = cur[2];
        q.pop();
        if (cx == n-1 && cy == m-1) {
            return cc;
        }
        for (pair<int, int> d: directions) {
            int nx = cx + d.first;
            int ny = cy + d.second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || maps[nx][ny] == 0) {
                continue;
            }
            q.push({nx, ny, cc + 1});
            visited[nx][ny] = true;
        }
    }
    
    return -1;
}