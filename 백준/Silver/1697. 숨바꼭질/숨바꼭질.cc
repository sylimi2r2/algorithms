#include <iostream>
#include <queue>

using namespace std;

struct State {
    int cur, t;
};

bool visited[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    if (N >= K) {
        cout << N - K;
        return 0;
    }

    queue<State> q;
    q.push({N, 0});

    while (!q.empty()) {
        auto [cur, t] = q.front();
        q.pop();

        if (cur == K) {
            cout << t;
            break;
        }

        int next[3] = {cur + 1, cur - 1, cur * 2};
        for (int n: next) {
            if (n < 0 || n > 100000 || visited[n]) continue;

            visited[n] = true;
            q.push({n, t + 1});
        }
    }
}