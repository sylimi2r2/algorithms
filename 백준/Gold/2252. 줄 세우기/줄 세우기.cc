#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int A, B;
int depth[32001] = {0,};
vector<int> edge[32001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> A >> B;
        depth[B]++;
        edge[A].emplace_back(B);
    }

    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        if (depth[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for (int next: edge[cur]) {
            depth[next]--;

            if (depth[next] == 0) {
                q.push(next);
            }
        }
    }
}
