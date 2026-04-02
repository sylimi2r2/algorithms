#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> graph[1001];
bool visited[1001];

void dfs(int cur) {
    cout << cur << ' ';

    for (int next: graph[cur]) {
        if (!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();

        for (int next: graph[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> V;

    for (int i=0; i<M; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for (int i=1; i<=N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    visited[V] = true;
    dfs(V);
    cout << '\n';

    fill(visited, visited + N + 1, false);
    
    visited[V] = true;
    bfs(V);
}