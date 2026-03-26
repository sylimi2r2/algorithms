#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool visited[100001] = {0,};

void bfs() {
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;

    while(!q.empty()) {
        int cur = q.front().first;
        int curCost = q.front().second;
        q.pop();
        if(cur == K) {
            cout << curCost;
            break;
        }
        int next1 = cur+1;
        int next2 = cur-1;
        int next3 = cur*2;
        if(next1<=100000 && !visited[next1]) {
            q.push({next1, curCost+1});
            visited[next1] = true;
        }
        if(next2>=0 && !visited[next2]) {
            q.push({next2, curCost+1});
            visited[next2] = true;
        }
        if(next3<=100000 && !visited[next3]) {
            q.push({next3, curCost+1});
            visited[next3] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    bfs();
}
