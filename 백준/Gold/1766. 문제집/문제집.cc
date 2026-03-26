#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A, B;
int depth[32001] = {0,};
vector<int> edge[32001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> A >> B;
        edge[A].emplace_back(B);
        depth[B]++;
    }

    priority_queue<int, vector<int>, greater<>> q;

    for (int i = 1; i <= N; ++i) {
        if (depth[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.top();
        q.pop();

        cout << cur << ' ';

        for (int next: edge[cur]) {
            if (--depth[next] == 0) {
                q.push(next);
            }
        }
    }
}
