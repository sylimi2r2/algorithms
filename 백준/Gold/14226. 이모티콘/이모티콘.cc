#include <iostream>
#include <queue>

using namespace std;

struct State {
    int x, clip, t;
};

const int MAX = 2000;
bool visited[MAX + 1][MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int S;
    cin >> S;

    int limit = 2 * S;
    queue<State> q;
    visited[1][0] = true;
    q.push({1, 0, 0});

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.x == S) {
            cout << cur.t;
            break;
        }

        State next[3] = {{cur.x, cur.x, cur.t + 1},
                         {cur.x + cur.clip, cur.clip, cur.t + 1},
                         {cur.x - 1, cur.clip, cur.t + 1}};
        for (State n: next) {
            if (n.x < 0 || n.x > limit) continue;
            if (visited[n.x][n.clip]) continue;

            visited[n.x][n.clip] = true;
            q.push(n);
        }
    }
}