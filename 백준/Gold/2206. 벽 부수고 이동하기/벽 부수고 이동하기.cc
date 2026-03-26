#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, M;
vector<string> map;
int costs[2][1000][1000];
pair<int, int> directions[4] = {{0, 1},{0, -1},
                                {1, 0},{-1, 0}};

void bfs() {
    for(int c=0; c<2; c++)
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                costs[c][i][j] = 10000000;

    queue<vector<int>> q;
    q.push({0, 0, 1, 1}); // {x, y, cost, chance}
    costs[1][0][0] = 1;
    costs[0][0][0] = 1;

    while(!q.empty()) {
        int curX = q.front()[0];
        int curY = q.front()[1];
        int curCost = q.front()[2];
        int curChance = q.front()[3];
        q.pop();
        if(curCost>costs[curChance][curX][curY])
            continue;
        for(pair<int, int> d : directions) {
            int nextX = curX + d.first;
            int nextY = curY + d.second;
            if(nextX>=0 && nextX<N && nextY>=0 && nextY<M) {
                if(map[nextX][nextY] == '0') {
                    if(curCost+1 < costs[curChance][nextX][nextY]) {
                        q.push({nextX, nextY, curCost+1, curChance});
                        costs[curChance][nextX][nextY] = curCost+1;
                    }
                }
                else if(map[nextX][nextY] == '1' && curChance){
                    if(curCost+1 < costs[0][nextX][nextY]) {
                        q.push({nextX, nextY, curCost+1, 0});
                        costs[0][nextX][nextY] = curCost+1;
                    }
                }
            }
        }
    }

    int sol = min(costs[0][N-1][M-1], costs[1][N-1][M-1]);
    if(sol != 10000000)
        cout << sol;
    else
        cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string input;
        cin >> input;
        map.push_back(input);
    }

    bfs();
}
