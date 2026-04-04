#include <iostream>
#include <deque>

using namespace std;

struct State {
    int x, t;
};

bool visited[150001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    deque<State> dq;
    visited[N] = true;
    dq.push_back({N, 0});

    while (!dq.empty()) {
        auto [x, t] = dq.front();
        dq.pop_front();

        if (x == K) {
            cout << t;
            break;
        }

        int nx = 2 * x;
        if (nx > 0 && nx <= 150000 && !visited[nx]) {
            visited[nx] = true;
            dq.push_front({nx, t});
        }

        nx = x - 1;
        if (nx >= 0 && nx <= 150000 && !visited[nx]) {
            visited[nx] = true;
            dq.push_back({nx, t + 1});
        }

        nx = x + 1;
        if (nx <= K && !visited[nx]) {
            visited[nx] = true;
            dq.push_back({nx, t + 1});
        }
    }
}