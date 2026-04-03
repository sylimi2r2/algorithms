#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int x, y, d;
};

string board[100];
bool visited[100][100];
pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i=0; i<N; ++i) {
        cin >> board[i];
    }

    queue<Node> q;
    visited[0][0] = true;
    q.push({0, 0, 1});

    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();

        if (x == N - 1 && y == M - 1) {
            cout << d;
            break;
        }

        for (auto [dx, dy]: dir) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == '0' || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny, d + 1});
        }
    }
}