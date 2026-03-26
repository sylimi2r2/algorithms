#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
char map[100][100];
bool visited[100][100] = {0,};
int cnt = 0;
int cnt_RG = 0;

void bfs(bool colorWeak, int x, int y) {
    pair<int, int> direction[4] = {{0, 1}, {0, -1},
                                   {1, 0}, {-1, 0}};
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()) {
        pair<int, int> current = q.front();
        char currentColor = map[current.first][current.second];
        q.pop();
        for(pair<int, int> d : direction) {
            pair<int, int> next = {current.first+d.first, current.second+d.second};
            if(next.first>=0 && next.first<N && next.second>=0 && next.second<N) {
                char nextColor = map[next.first][next.second];
                if(!visited[next.first][next.second]) {
                    if(currentColor==nextColor) {
                        q.push(next);
                        visited[next.first][next.second] = true;
                    }
                    else if(colorWeak && currentColor!='B' && nextColor!='B') {
                        q.push(next);
                        visited[next.first][next.second] = true;
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

    cin >> N;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<N; j++)
            map[i][j] = s[j];
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                cnt++;
                bfs(false, i, j);
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            visited[i][j] = false;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                cnt_RG++;
                bfs(true, i, j);
            }
        }
    }

    cout << cnt << ' ' << cnt_RG;
}
