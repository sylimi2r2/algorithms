#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> graph[1001];

int bfs(int n1, int n2) {
    bool visited[1001] = {0, };
    queue<pair<int, int>> q;
    q.emplace(n1, 0);
    visited[n1] = true;

    while(!q.empty()) {
        int cur = q.front().first;
        int curD = q.front().second;
        q.pop();

        for(pair<int, int> n : graph[cur]) {
            int next = n.first;
            int nextD = curD + n.second;

            if(next == n2) {
                return nextD;
            }

            if(!visited[next]) {
                q.emplace(next, nextD);
                visited[next] = true;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        int n1, n2, edge;
        cin >> n1 >> n2 >> edge;
        graph[n1].emplace_back(n2, edge);
        graph[n2].emplace_back(n1, edge);
    }

    for (int i = 0; i < M; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        cout << bfs(n1, n2) << '\n';
    }
}
