#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> bus(1001);
int c[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({-0, start});
    while(!pq.empty()) {
        int current = pq.top().second;
        int currentCost = -pq.top().first;
        pq.pop();
        if(c[current] < currentCost)
            continue;
        for(pair<int, int> n : bus[current]) {
            int next = n.first;
            int nextCost = currentCost + n.second;
            if(nextCost < c[next]) {
                c[next] = nextCost;
                pq.push({-nextCost, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        c[i] = 100000000;
    }

    for(int i=1; i<=M; i++) {
        int start, dest, cost;
        cin >> start >> dest >> cost;
        bus[start].push_back({dest, cost});
    }

    int start, dest;
    cin >> start >> dest;

    dijkstra(start);

    cout << c[dest];
    return 0;
}
