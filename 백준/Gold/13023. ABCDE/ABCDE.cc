#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> relations;
vector<bool> visited;

void dfs(int cnt, int cur) {
    if (cnt == 5) {
        cout << 1;
        exit(0);
    }

    for (int next: relations[cur]) {
        if (!visited[next]) {
            visited[next] = true;
            dfs(cnt + 1, next);
            visited[next] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    relations = vector<vector<int>>(N);
    visited = vector<bool>(N, false);
    for (int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;

        relations[a].push_back(b);
        relations[b].push_back(a);
    }

    for (int i=0; i<N; ++i) {
        visited[i] = true;
        dfs(1, i);
        visited[i] = false;
    }

    cout << 0;
}