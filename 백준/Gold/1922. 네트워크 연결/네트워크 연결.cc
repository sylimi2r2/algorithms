#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int sol = 0;
int N, M;
int a, b, c;
vector<pair<int, int>> edge[1001];
bool visited[1001] = {0,};

void prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);

    while(!pq.empty()) {
        int curCom = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if(visited[curCom])
            continue;
        visited[curCom] = true;
        sol += curDist;

        for(pair<int, int> e : edge[curCom]) {
            int nextCom = e.second;

            if(!visited[nextCom])
                pq.emplace(e.first, nextCom);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> a >> b >> c;
        edge[a].emplace_back(c, b);
        edge[b].emplace_back(c, a);
    }

    prim();

    cout << sol;
}
