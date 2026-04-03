#include <iostream>
#include <queue>

using namespace std;

struct State {
    int x, y, d;
};

bool visited[300][300];
pair<int, int> dir[8] = {{1, -2},{2, -1},
                         {2, 1},{1, 2},
                         {-1, 2},{-2, 1},
                         {-2, -1},{-1, -2}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int l;
        int sx, sy;
        int tx, ty;
        cin >> l;
        cin >> sx >> sy;
        cin >> tx >> ty;

        for (int i=0; i<l; ++i) {
            for (int j=0; j<l; ++j) {
                visited[i][j] = false;
            }
        }

        queue<State> q;
        visited[sx][sy] = true;
        q.push({sx, sy, 0});

        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();

            if (x == tx && y == ty) {
                cout << d << '\n';
                break;
            }

            for (auto [dx, dy]: dir) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (visited[nx][ny]) continue;

                visited[nx][ny] = true;
                q.push({nx, ny, d + 1});
            }
        }
    }
}