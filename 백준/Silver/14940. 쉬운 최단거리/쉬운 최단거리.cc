#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[1000][1000];
bool visited[1000][1000] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    int x, y;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int input;
            cin >> input;
            if(input == 2) {
                x = i;
                y = j;
                input = 0;
            }
            map[i][j] = input;
        }
    }

    priority_queue<vector<int>> pq;
    vector<vector<int>> route = {{0, 1}, {0, -1}, {1,0}, {-1,0}};
    pq.push({0, x, y});
    while(!pq.empty()) {
        vector<int> current = pq.top();
        int currentD = -current[0];
        int currentX = current[1];
        int currentY = current[2];
        pq.pop();
        if(visited[currentX][currentY]) continue;
        else visited[currentX][currentY] = true;
        for(int i=0; i<4; i++) {
            int nextD;
            int nextX = currentX + route[i][0];
            int nextY = currentY + route[i][1];
            if(!visited[nextX][nextY] && nextX>=0 && nextX<n && nextY>=0 && nextY<m) {
                if(map[nextX][nextY]) {
                    nextD = currentD + 1;
                    pq.push({-nextD, nextX, nextY});
                    map[nextX][nextY] = nextD;
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && map[i][j]==1)
                cout << -1 << " ";
            else 
                cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}
