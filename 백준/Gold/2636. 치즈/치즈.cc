#include <iostream>
#include <queue>
using namespace std;

int R, C;
int cheese[100][100];
pair<int, int> direction[4] = {{0, 1}, {0, -1},
                               {1, 0}, {-1, 0}};

void bfs() {
    int time = 0;
    int last = 0;

    while(true) {
        int melt = 0;
        bool visited[100][100] = {0, };
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visited[0][0] = true;

        while(!q.empty()) {
            int curR = q.front().first;
            int curC = q.front().second;
            q.pop();

            for(pair<int, int> d : direction) {
                int nextR = curR + d.first;
                int nextC = curC + d.second;
                if(nextR>=0 && nextR<R && nextC>=0 && nextC<C) {
                    if(!visited[nextR][nextC]) {
                        if(cheese[nextR][nextC] == 0) {
                            q.emplace(nextR, nextC);
                        }
                        else {
                            melt++;
                            cheese[nextR][nextC] = 0;
                        }
                        visited[nextR][nextC] = true;
                    }
                }
            }
        }

        if(melt == 0) {
            cout << time << '\n' << last;
            break;
        }
        else {
            time++;
            last = melt;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cin >> cheese[i][j];

    bfs();
}
