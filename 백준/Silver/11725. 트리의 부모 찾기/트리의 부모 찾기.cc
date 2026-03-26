#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> edges(N+1);
    vector<int> sol(N+1);
    vector<bool> visited(N+1, false);
    for(int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(int next : edges[current]) {
            if(!visited[next]) {
                sol[next] = current;
                visited[next] = true;
                q.push(next);
            }
        }
    }

    for(int i=2; i<=N; i++) {
        cout << sol[i] << '\n';
    }
}
