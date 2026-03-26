#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> edges[1001];
bool visited[1001] = {0, };
void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(int &next : edges[current]) {
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    while(M--) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int cnt = 0;
    for(int i=1; i<=N; i++) {
        if(!visited[i]) {
            cnt++;
            bfs(i);
        }
    }

    cout << cnt;
}
