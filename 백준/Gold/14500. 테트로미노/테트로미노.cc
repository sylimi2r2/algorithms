#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int directions[4][2] = {{0, 1},    // right
                                  {1, 0},    // down
                                  {0, -1},   // left
                                  {-1, 0}};  // up

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {

            // one line
            queue<vector<int>> q;
            q.push({i, j, board[i][j], 0, 1});
            while (!q.empty()) {
                vector<int> cur = q.front();
                q.pop();
                int curI = cur[0];
                int curJ = cur[1];
                int curC = cur[2];
                int curD = cur[3];
                int curT = cur[4];
                if (curT == 4) {
                    ans = max(ans, curC);
                    continue;
                }
                for (int d=0; d<4; ++d) {
                    if (d == (curD + 2) % 4)
                        continue;
                    int nextI = curI + directions[d][0];
                    int nextJ = curJ + directions[d][1];
                    if (nextI >= 0 && nextI < N && nextJ >= 0 && nextJ < M) {
                        q.push({nextI, nextJ, curC + board[nextI][nextJ], d, curT + 1});
                    }
                }
            }

            // ㅗ
            for (int d=0; d<4; ++d) {
                int cost = board[i][j];
                bool flag = true;
                for (int k=0; k<3; ++k) {
                    int nextD = (d + k) % 4;
                    int nextI = i + directions[nextD][0];
                    int nextJ = j + directions[nextD][1];
                    if (nextI < 0 || nextI >= N || nextJ < 0 || nextJ >= M) {
                        flag = false;
                        break;
                    }
                    cost += board[nextI][nextJ];
                }
                if (flag)
                    ans = max(ans, cost);
            }
        }
    }

    cout << ans;
}