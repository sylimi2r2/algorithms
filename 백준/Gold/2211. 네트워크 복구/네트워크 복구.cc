#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000

int N, M;
int A, B, C;
int dist[1001];
int conn[1001];
vector<pair<int, int>> network[1001];

void dijkstra() {
    for(int i=1; i<=N; i++)
        dist[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        int curD = pq.top().first;
        pq.pop();

        if(dist[cur] < curD)
            continue;

        for(pair<int, int> n : network[cur]) {
            int next = n.first;
            int nextD = curD + n.second;

            if(dist[next] > nextD) {
                dist[next] = nextD;
                conn[next] = cur;
                pq.emplace(nextD, next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    while(M--) {
        cin >> A >> B >> C;
        network[A].emplace_back(B, C);
        network[B].emplace_back(A, C);
    }

    dijkstra();

    cout << N-1 << '\n';
    for(int i=2; i<=N; i++) {
        cout << i << ' ' << conn[i] << '\n';
    }
}
