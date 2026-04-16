#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<pair<int, int>> normalize(vector<pair<int, int>> shape) {
    int minX = shape[0].first;
    int minY = shape[0].second;

    for (auto [x, y] : shape) {
        minX = min(minX, x);
        minY = min(minY, y);
    }

    for (auto& [x, y] : shape) {
        x -= minX;
        y -= minY;
    }

    sort(shape.begin(), shape.end());
    return shape;
}

vector<vector<pair<int, int>>> rotate(vector<pair<int, int>> block) {
    vector<vector<pair<int, int>>> ret;
    
    block = normalize(block);
    ret.push_back(block);

    for (int i = 0; i < 3; ++i) {
        vector<pair<int, int>> next;
        for (auto [x, y] : block) {
            next.push_back({y, -x});
        }

        block = normalize(next);
        ret.push_back(block);
    }

    return ret;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    int N = game_board.size();
    
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<vector<pair<int, int>>>> blocks;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (table[i][j] == 0 || visited[i][j]) continue;
            
            vector<pair<int, int>> block;
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                block.push_back({x - i, y - j});

                for (auto [dx, dy]: directions) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (table[nx][ny] == 0 || visited[nx][ny]) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            
            blocks.push_back(rotate(block));
        }
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            visited[i][j] = false;
        }
    }
    
    vector<bool> used(blocks.size(), false);
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (game_board[i][j] == 1 || visited[i][j]) continue;
            
            vector<pair<int, int>> blank;
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                blank.push_back({x - i, y - j});

                for (auto [dx, dy]: directions) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (game_board[nx][ny] == 1 || visited[nx][ny]) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            
            blank = normalize(blank);
            
            int s = blank.size();
            for (int b = 0; b < blocks.size(); ++b) {
                if (used[b]) continue;
                if (blocks[b][0].size() != s) continue;
                
                bool found = false;
                
                for (auto r : blocks[b]) {
                    if (blank == r) {
                        answer += s;
                        used[b] = true;
                        found = true;
                        break;
                    }
                }
                
                if (found) break;
            }
        }
    }
    
    return answer;
}