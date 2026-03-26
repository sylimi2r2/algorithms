#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, sol = 0;
int wall=3;
int simulation[8][8];
int lab[8][8];
pair<int, int> directions[4] = {{0, 1}, {0, -1},
                                {1, 0}, {-1, 0}};
vector<pair<int, int>> viruses;

void bfs() {
    int cnt = viruses.size();
    queue<pair<int, int>> q;
    for(pair<int, int> v : viruses) {
        q.push(v);
    }

    while(!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();
        for(pair<int, int> d : directions) {
            int nextX = currentX + d.first;
            int nextY = currentY + d.second;
            if(nextX>=0 && nextX<N && nextY>=0 && nextY<M) {
                if(simulation[nextX][nextY] == 0) {
                    q.push({nextX, nextY});
                    simulation[nextX][nextY] = 2;
                    cnt++;
                }
            }
        }
    }

    sol = max(sol, N*M-cnt-wall);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> lab[i][j];
            simulation[i][j] = lab[i][j];
            if(lab[i][j] == 2)
                viruses.push_back({i, j});
            else if(lab[i][j] == 1)
                wall++;
        }
    }

    int cases = N*M;
    int x1, y1, x2, y2, x3, y3;
    for(int i=0; i<cases; i++) {
        x1 = i/M;
        y1 = i%M;
        if(simulation[x1][y1] == 0) {
            for(int j=i+1; j<cases; j++) {
                x2 = j/M;
                y2 = j%M;
                if(simulation[x2][y2] == 0) {
                    for(int k=j+1; k<cases; k++) {
                        x3 = k/M;
                        y3 = k%M;
                        if(simulation[x3][y3] == 0) {
                            simulation[x1][y1] = 1;
                            simulation[x2][y2] = 1;
                            simulation[x3][y3] = 1;
                            bfs();
                            for(int n=0; n<N; n++) {
                                for(int m=0; m<M; m++) {
                                    simulation[n][m] = lab[n][m];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << sol;
}
