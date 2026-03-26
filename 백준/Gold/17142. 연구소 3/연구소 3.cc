#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int sol = 2500;
int N, M;
int lab[50][50];
int blank = 0;
vector<pair<int, int>> virus;
bool activated[10] = {0,};
pair<int, int> direction[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs() {
    int time = 0;
    int cnt = 0;
    bool visited[50][50] = {0,};
    queue<pair<int, pair<int, int>>> q;

    for(int i=0; i<10; i++) {
        if(activated[i]) {
            q.emplace(0, virus[i]);
            visited[virus[i].first][virus[i].second] = true;
        }
    }

    while(!q.empty()) {
        int curT = q.front().first;
        int curX = q.front().second.first;
        int curY = q.front().second.second;
        q.pop();

        for(pair<int, int> d : direction) {
            int nextT = curT + 1;
            int nextX = curX + d.first;
            int nextY = curY + d.second;

            if(nextX>=0 && nextX<N && nextY>=0 && nextY<N) {
                if(!visited[nextX][nextY] && lab[nextX][nextY]!=1) {
                    if(lab[nextX][nextY] == 0) {
                        cnt++;
                        time = max(time, nextT);
                    }
                    q.emplace(nextT, make_pair(nextX, nextY));
                    visited[nextX][nextY] = true;
                }
            }
        }
    }

    if(cnt == blank) {
        sol = min(sol, time);
    }
}

void dfs(int size, int index) {
    if(size == M) {
        bfs();
        return;
    }

    for(int i=index; i<virus.size(); i++) {
        activated[i] = true;
        dfs(size+1, i+1);
        activated[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) {
            cin >> lab[i][j];
            if(lab[i][j] == 0)
                blank++;
            else if(lab[i][j] == 2)
                virus.emplace_back(i, j);
        }

    dfs(0, 0);

    if(sol == 2500)
        cout << -1;
    else
        cout << sol;

}
