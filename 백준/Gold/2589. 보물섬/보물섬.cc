#include <iostream>
#include <string>
#include <queue>
using namespace std;

int sol = 0;
int N, M;
char map[50][50];
pair<int, int> directions[4] = {{0, 1}, {0, -1},
                                {1, 0}, {-1, 0}};

void bfs() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j]=='L') {
                bool visited[50][50] = {0,};
                queue<pair<int, pair<int, int>>> q;
                q.push({0, {i, j}});
                visited[i][j] = true;
                while(!q.empty()) {
                    int curCost = q.front().first;
                    pair<int, int> cur = q.front().second;
                    q.pop();
                    for(pair<int, int> d : directions) {
                        pair<int, int> next = {cur.first+d.first, cur.second+d.second};
                        if(next.first>=0 && next.first<N && next.second>=0 && next.second<M) {
                            if(map[next.first][next.second]=='L' && !visited[next.first][next.second]) {
                                q.push({curCost+1, next});
                                visited[next.first][next.second] = true;
                                sol = max(sol, curCost+1);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string input;
        cin >> input;
        for(int j=0; j<M; j++) {
            map[i][j] = input[j];
        }
    }

    bfs();

    cout << sol;
}
