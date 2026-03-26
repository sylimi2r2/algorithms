#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int sec = 1;
int map[1000][1000];
int section[1000][1000] = {0,};
bool visited[1000][1000] = {0,};
vector<pair<int, int>> zeros;
vector<int> secSize;
pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(int n, int m) {
    int cnt = 1;
    section[n][m] = sec;
    queue<pair<int, int>> q;
    q.emplace(n, m);
    visited[n][m] = true;

    while (!q.empty()) {
        int curN = q.front().first;
        int curM = q.front().second;
        q.pop();

        for (pair<int, int> d: directions) {
            int nextN = curN + d.first;
            int nextM = curM + d.second;

            if (nextN >= 0 && nextN < N && nextM >= 0 && nextM < M && !visited[nextN][nextM] && map[nextN][nextM] == 0) {
                q.emplace(nextN, nextM);
                visited[nextN][nextM] = true;
                section[nextN][nextM] = sec;
                cnt++;
            }
        }
    }

    sec++;
    secSize.emplace_back(cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            map[i][j] = input[j] - '0';
            if (map[i][j] == 0) {
                zeros.emplace_back(i, j);
            }
        }
    }

    for (pair<int, int> z: zeros) {
        if (!visited[z.first][z.second]) {
            bfs(z.first, z.second);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                vector<int> check;
                for (pair<int, int> d: directions) {
                    int nextN = i + d.first;
                    int nextM = j + d.second;
                    if (nextN >= 0 && nextN < N && nextM >= 0 && nextM < M && map[nextN][nextM] == 0) {
                        int curSec = section[nextN][nextM];
                        if (find(check.begin(), check.end(), curSec) == check.end()) {
                            check.emplace_back(curSec);
                            map[i][j] += secSize[curSec - 1];
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] % 10;
        }
        cout << '\n';
    }
}