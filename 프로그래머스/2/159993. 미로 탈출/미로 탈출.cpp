#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[100][100] = {0,};
pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solution(vector<string> maps) {
    queue<vector<int>> q;
    int x = maps.size(), y = maps[0].size();
    bool flag = false;
    for (int i=0; i<x; ++i) {
        for (int j=0; j<y; ++j) {
            if (maps[i][j] == 'S') {
                visited[i][j] = true;
                q.push({i, j, 0, 0});
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        for (pair<int, int> d: directions) {
            int nextX = cur[0] + d.first;
            int nextY = cur[1] + d.second;
            if (nextX >= 0 && nextX < x && nextY >= 0 && nextY < y && maps[nextX][nextY] != 'X' && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                if (maps[nextX][nextY] == 'E' && cur[3] == 1)
                    return cur[2] + 1;
                if (maps[nextX][nextY] == 'L') {
                    while (!q.empty())
                        q.pop();
                    q.push({nextX, nextY, cur[2] + 1, 1});
                    for (int i=0; i<x; ++i) {
                        for (int j=0; j<y; ++j) {
                            visited[i][j] = false;
                        }
                    }
                    visited[nextX][nextY] = true;
                    break;
                }
                else {
                    q.push({nextX, nextY, cur[2] + 1, cur[3]});
                }
            }
        }
    }
    
    return -1;
}