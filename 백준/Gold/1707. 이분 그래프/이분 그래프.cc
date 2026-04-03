#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int state[20001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    while (K--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> graph(V + 1);

        for (int i=1; i<=V; ++i) {
            state[i] = 0;
        }

        for (int i=0; i<E; ++i) {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool isBipartite = true;
        queue<int> q;

        for (int i=1; i<=V && isBipartite; ++i) {
            if (state[i] != 0)
                continue;

            state[i] = 1;
            q.push(i);

            while (!q.empty() && isBipartite) {
                int cur = q.front();
                q.pop();

                for (int next: graph[cur]) {
                    if (state[next] == 0) {
                        state[next] = -state[cur];
                        q.push(next);
                        continue;
                    }

                    if (state[next] == state[cur]) {
                        isBipartite = false;
                        break;
                    }
                }
            }
        }

        cout << (isBipartite ? "YES" : "NO") << '\n';
    }
}