#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> network(101);
    vector<bool> visited(101, false);
    int nodes, edges;
    cin >> nodes >> edges;

    while(edges--) {
        int a, b;
        cin >> a >> b;
        network[a].push_back(b);
        network[b].push_back(a);
    }

    int sum = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(int next : network[current]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
                sum++;
            }
        }
    }

    cout << sum;
}
