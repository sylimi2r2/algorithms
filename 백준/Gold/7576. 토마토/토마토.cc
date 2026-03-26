#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> box;
queue<pair<int, int>> q;
int M, N;

void bfs() {
    vector<pair<int, int>> direction = {{0, 1}, {0, -1},
                                        {1, 0}, {-1, 0}};
    int currentX, currentY, nextX, nextY;
    while(!q.empty()) {
            currentX = q.front().first;
            currentY = q.front().second;
            q.pop();
        for(auto d : direction) {
            nextX = currentX + d.first;
            nextY = currentY + d.second;
            if(nextX>=0 && nextX<N && nextY>=0 && nextY<M && box[nextX][nextY]==0) {
                box[nextX][nextY] = box[currentX][currentY] + 1;
                q.push({nextX, nextY});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N;
    for(int n=0; n<N; n++) {
        vector<int> row;
        for(int m=0; m<M; m++) {
            int input;
            cin >> input;
            row.push_back(input);
            if(input == 1)
                q.push({n, m});
        }
        box.push_back(row);
    }

    bfs();

    int maximum = 0;
    for(vector<int> &row : box) {
        for(int &tomato : row) {
            if(tomato == 0) {
                cout << -1;
                return 0;
            }
            maximum = max(maximum, tomato);
        }
    }

    cout << maximum-1;
    return 0;
}
