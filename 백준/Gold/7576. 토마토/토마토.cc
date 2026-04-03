#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
int storage[1000][1000];
pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    queue<pair<int, int>> q;

    cin >> M >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> storage[i][j];

            if (storage[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy]: dir) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (storage[nx][ny] != 0) continue;

            storage[nx][ny] = storage[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int ans = -1;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (storage[i][j] == 0) {
                cout << -1;
                return 0;
            }
            ans = max(ans, storage[i][j]);
        }
    }

    cout << ans - 1;
}