#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int x, y;
int cost = 0;
int curSize = 2, curCap = 0;
int map[20][20];
bool visited[20][20];
pair<int, int> direction[4] = {{-1, 0}, {0, -1},
                               {0, 1}, {1, 0}};

void reset() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            visited[i][j] = false;
        }
    }
}

void eat() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    queue<vector<int>> q;
    bool find = false;
    int tmp = 0;
    q.push({x, y, 0, 0});
    visited[x][y] = true;

    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        int curX = cur[0];
        int curY = cur[1];
        int curCost = cur[2];
        if (!find || curCost < tmp) {
            for (pair<int, int> d: direction) {
                int nextX = curX + d.first;
                int nextY = curY + d.second;
                if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && !visited[nextX][nextY]) {
                    if (map[nextX][nextY] == 0 || map[nextX][nextY] == curSize) {
                        visited[nextX][nextY] = true;
                        q.push({nextX, nextY, curCost + 1});
                    }
                    else if (map[nextX][nextY] < curSize) {
                        find = true;
                        pq.push({nextX, nextY});
                        tmp = curCost + 1;
                        visited[nextX][nextY] = true;
                    }
                }
            }
        }
        if (q.empty() && find) {
            pair<int, int> next = pq.top();
            while (!pq.empty())
                pq.pop();
            find = false;
            cost = tmp;
            map[next.first][next.second] = 0;
            reset();
            visited[next.first][next.second] = true;
            if (++curCap == curSize) {
                ++curSize;
                curCap = 0;
            }
            q.push({next.first, next.second, tmp});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                x = i;
                y = j;
                map[i][j] = 0;
            }
        }
    }
    reset();
    eat();

    cout << cost;
}