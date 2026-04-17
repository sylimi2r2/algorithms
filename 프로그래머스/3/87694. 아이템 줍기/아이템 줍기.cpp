#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<int>> board(101, vector<int>(101, 0));
    pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    for (int i=0; i<rectangle.size(); ++i) {
        for (int j=0; j<4; ++j) {
            rectangle[i][j] *= 2;
        }
    }
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    for (vector<int> r: rectangle) {
        int lx = r[0];
        int ly = r[1];
        int rx = r[2];
        int ry = r[3];
        
        for (int j=ly; j<=ry; ++j) {
            board[lx][j] = 1;
            board[rx][j] = 1;
        }
        for (int i=lx; i<=rx; ++i) {
            board[i][ly] = 1;
            board[i][ry] = 1;
        }
    }
    
    for (vector<int> r: rectangle) {
        int lx = r[0];
        int ly = r[1];
        int rx = r[2];
        int ry = r[3];
        
        for (int i=lx+1; i<rx; ++i) {
            for (int j=ly+1; j<ry; ++j) {
                board[i][j] = 0;
            }
        }
    }
    
    vector<vector<int>> dist(101, vector<int>(101, -1));
    queue<pair<int, int>> q;
    q.push({characterX, characterY});
    dist[characterX][characterY] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (x == itemX && y == itemY) {
            return dist[x][y] / 2;
        }
        
        for (auto [dx, dy]: directions) {
            int nx = x + dx;
            int ny = y + dy;
            
            if (nx < 0 || nx > 100 || ny < 0 || ny > 100) continue;
            if (board[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    
    return -1;
}