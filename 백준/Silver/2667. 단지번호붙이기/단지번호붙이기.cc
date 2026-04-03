#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string board[25];
bool visited[25][25];
pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    for (int i=0; i<N; ++i) {
        cin >> board[i];
    }

    vector<int> cnts;
    queue<pair<int, int>> q;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (board[i][j] == '0' || visited[i][j]) continue;

            int cnt = 0;
            visited[i][j] = true;
            q.push({i, j});
            
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                ++cnt;

                for (auto [dx, dy]: dir) {
                   int nx = x + dx;
                   int ny = y + dy;

                    if (nx < 0 || nx >= N || ny < 0 || ny >=N) continue;
                    if (board[nx][ny] == '0' || visited[nx][ny]) continue;

                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }

            cnts.push_back(cnt);
        }
    }

    sort(cnts.begin(), cnts.end());

    cout << cnts.size() << '\n';
    for (int cnt: cnts) {
        cout << cnt << '\n';
    }
}