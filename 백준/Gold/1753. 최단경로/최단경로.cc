#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> edges(20001);
int d[20001];
int INF = 200000;

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;
    while(!pq.empty()) {
        int current = pq.top().second;
        int currentD = -pq.top().first;
        pq.pop();
        if(currentD > d[current])
            continue;
        for(pair<int, int> n : edges[current]) {
            int next = n.first;
            int nextD = currentD + n.second;
            if(nextD < d[next]){
                d[next] = nextD;
                pq.push({-nextD, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E, start;
    cin >> V >> E >> start;

    for(int i=1; i<=V; i++) {
        d[i] = INF;
    }

    while(E--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }

    dijkstra(start);

    for(int i=1; i<=V; i++) {
        if(d[i] == INF)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }
}
