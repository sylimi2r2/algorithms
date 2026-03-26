#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> map(1001);
vector<bool> visited(1001, false);
vector<int> dfs;
vector<int> bfs;

void DFS(int current) {
    visited[current] = true;
    dfs.push_back(current);
    for(int next : map[current]) {
        if(!visited[next])
            DFS(next);
    }
}

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int current = q.front();
        bfs.push_back(current);
        q.pop();
        for(int next : map[current]) {
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

    int N, M, V;
    cin >> N >> M >> V;
    while(M--) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    for(int i=1; i<=N; i++) {
        sort(map[i].begin(), map[i].end());
    }
    
    DFS(V);

    for(int i=1; i<=N; i++) {
        visited[i] = false;
    }
    BFS(V);

    for(int node : dfs) {
        cout << node << ' ';
    }
    cout << '\n';

    for(int node : bfs) {
        cout << node << ' ';
    }
    cout << '\n';
}
