#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, K, X, Y, W;
int time[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    while(T--) {
        vector<int> edge[1001];
        int depth[1001] = {0,};
        long long previous[1001] = {0,};

        cin >> N >> K;

        for (int i = 1; i <= N; ++i) {
            cin >> time[i];
        }

        for (int i = 0; i < K; ++i) {
            cin >> X >> Y;
            edge[X].emplace_back(Y);
            depth[Y]++;
        }

        cin >> W;

        queue<int> q;

        for (int i = 1; i <= N; ++i) {
            if (depth[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next: edge[cur]) {
                depth[next]--;
                previous[next] = max(previous[next], previous[cur] + time[cur]);

                if (depth[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << previous[W] + time[W] << '\n';
    }
}
