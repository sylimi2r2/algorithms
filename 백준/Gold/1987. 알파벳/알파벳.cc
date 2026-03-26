#include <iostream>
#include <string>
#include <vector>
using namespace std;

int R, C, sol = 0;
vector<string> map;
pair<int, int> directions[4] = {{0, 1}, {0, -1},
                                {1, 0}, {-1, 0}};
bool visited[26] = {0,};

void dfs(int cost, int x, int y) {
    sol = max(sol, cost);

    for(pair<int, int> d : directions) {
        int nextX = x + d.first;
        int nextY = y + d.second;
        if(nextX>=0 && nextX<R && nextY>=0 && nextY<C) {
            int alphabet = map[nextX][nextY] - 'A';
            if(!visited[alphabet]) {
                visited[alphabet] = true;
                dfs(cost+1, nextX, nextY);
                visited[alphabet] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    for(int i=0; i<R; i++) {
        string input;
        cin >> input;
        map.push_back(input);
    }

    visited[map[0][0]-'A'] = true;
    dfs(1, 0, 0);

    cout << sol;
}
