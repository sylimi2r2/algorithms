#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000

int n, d, c;
vector<pair<int, int>> depends[10001];
int costs[10001];

void dijkstra() {
    for(int i=1; i<=n; i++)
        costs[i] = INF;

    priority_queue<pair<int, int>> pq;
    pq.push({0, c});
    costs[c] = 0;
    while(!pq.empty()) {
        int cur = pq.top().second;
        int curCost = -pq.top().first;
        pq.pop();
        if(curCost > costs[cur])
            continue;
        for(pair<int, int> dep : depends[cur]) {
            int next = dep.first;
            int nextCost = curCost + dep.second;
            if(nextCost < costs[next]) {
                pq.push({-nextCost, next});
                costs[next] = nextCost;
            }
        }
    }

    int sum = 0;
    int time = 0;
    for(int i=1; i<=n; i++) {
        if(costs[i] != INF) {
            sum++;
            time = max(time, costs[i]);
        }
    }

    cout << sum << ' ' << time << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> d >> c;
        for(int i=0; i<d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            depends[b].push_back({a, s});
        }
        dijkstra();
        for(int i=1; i<=n; i++)
            depends[i].clear();
    }
}
