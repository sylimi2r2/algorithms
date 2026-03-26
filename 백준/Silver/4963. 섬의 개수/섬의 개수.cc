#include <iostream>
#include <queue>
using namespace std;

int w, h;
int map[50][50];
pair<int, int> directions[8] = {{0, 1}, {0, -1},
                                {1, 0}, {-1, 0},
                                {1, 1}, {1, -1},
                                {-1, -1}, {-1, 1}};

void bfs() {
    int cnt = 0;
    bool visited[50][50] = {0, };

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(map[i][j]==1 && !visited[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                cnt++;

                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for(pair<int, int> d : directions) {
                        pair<int, int> next = {cur.first+d.first, cur.second+d.second};

                        if(next.first>=0 && next.first<h && next.second>=0 && next.second<w) {
                            if(map[next.first][next.second]==1 && !visited[next.first][next.second]) {
                                q.push(next);
                                visited[next.first][next.second] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true) {
        cin >> w >> h;
        if(w==0 && h==0)
            break;

        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                cin >> map[i][j];

        bfs();
    }
}