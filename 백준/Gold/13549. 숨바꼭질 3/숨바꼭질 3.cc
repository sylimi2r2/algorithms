#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visited[100001] = {0,};

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, N});

    while(!pq.empty()) {
        int curNode = pq.top().second;
        int curCost = -pq.top().first;
        pq.pop();
        if(curNode == K) {
            cout << curCost;
            return;
        }
        if(visited[curNode])
            continue;
        else
            visited[curNode] = true;

        int next1 = curNode+1;
        int next2 = curNode-1;
        int next3 = 2*curNode;
        if(next1<=100000 && !visited[next1])
            pq.push({-curCost-1, next1});
        if(next2>=0 && !visited[next2])
            pq.push({-curCost-1, next2});
        if(next3<=100000 && !visited[next3])
            pq.push({-curCost, next3});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    dijkstra();
}
