#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int map[25][25] = {0,};
bool visited[25][25] = {0,};
pair<int, int> ways[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N;

int BFS(int x, int y) {
    int sum = 0;
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;
    sum++;
    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        for(pair<int, int> way : ways) {
            int nextX = current.first + way.first;
            int nextY = current.second + way.second;
            if(nextX>=0 && nextX<N && nextY>=0 && nextY<N) {
                if(map[nextX][nextY] && !visited[nextX][nextY]) {
                    q.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                    sum++;
                }
            }
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> solution;
    cin >> N;
    for(int i=0; i<N; i++) {
        string str;
        cin >> str;
        for(int j=0; j<N; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j] && !visited[i][j]) {
                int sol = BFS(i, j);
                solution.push_back(sol);
            }
        }
    }

    sort(solution.begin(), solution.end());
    cout << solution.size() << '\n';
    for(int sol : solution) {
        cout << sol << '\n';
    }
}
