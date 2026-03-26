#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M, sol = 0;
char map[600][600];
bool visited[600][600] = {0,};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    pair<int, int> directions[4] = {{0, 1}, {0, -1},
                                    {1, 0}, {-1, 0}};
    q.push({x, y});
    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        if(visited[current.first][current.second])
            continue;
        if(map[current.first][current.second] == 'P')
            sol++;
        visited[current.first][current.second] = true;
        for(pair<int, int> d : directions) {
            pair<int, int> next = {current.first+d.first, current.second+d.second};
            if(next.first>=0 && next.first<N && next.second>=0 && next.second<M) {
                if(map[next.first][next.second]!='X' && !visited[next.first][next.second]) {
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int X, Y;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<M; j++) {
            map[i][j] = s[j];
            if(map[i][j] == 'I') {
                X = i;
                Y = j;
            }
        }
    }

    bfs(X, Y);

    if(sol) {
        cout << sol;
    }
    else {
        cout << "TT";
    }
}
