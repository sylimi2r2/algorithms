#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int sol = 0;
int V, E;
int A, B, C;
vector<pair<int, int>> edge[10001];
bool visited[10001] = {0,};

void prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);

    while(!pq.empty()) {
        int curNode = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if(visited[curNode])
            continue;
        visited[curNode] = true;
        sol += dist;

        for(pair<int, int> e : edge[curNode]) {
            int nextNode = e.second;

            if(!visited[nextNode]) {
                pq.emplace(e.first, nextNode);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E;
    for(int i=0; i<E; i++) {
        cin >> A >> B >> C;
        edge[A].emplace_back(C, B);
        edge[B].emplace_back(C, A);
    }

    prim();

    cout << sol;
}
