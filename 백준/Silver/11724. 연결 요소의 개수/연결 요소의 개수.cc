#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
int N, M;
vector<int> graph[1001];
bool visited[1001];

void dfs(int cur) {
    for (int next: graph[cur]) {
        if (!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i=0; i<M; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1; i<=N; ++i) {
        if (!visited[i]) {
            ++ans;
            visited[i] = true;
            dfs(i);
        }
    }

    cout << ans;

}