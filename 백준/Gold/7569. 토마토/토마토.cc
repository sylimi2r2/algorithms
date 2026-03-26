#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<vector<int>>> boxes;
queue<vector<int>> q;
int M, N, H;

void bfs() {
    vector<vector<int>> directions = {{0, 0, 1}, {0, 0, -1},
                                      {0, 1, 0}, {0, -1, 0},
                                      {1, 0, 0}, {-1, 0, 0}};
    int currentZ, currentX, currentY, nextZ, nextX, nextY;
    while(!q.empty()) {
        currentZ = q.front()[0];
        currentX = q.front()[1];
        currentY = q.front()[2];
        q.pop();
        for(auto d : directions) {
            nextZ = currentZ + d[0];
            nextX = currentX + d[1];
            nextY = currentY + d[2];
            if(nextZ<0 || nextZ>=H ||
                nextX<0 || nextX>=N ||
                nextY<0 || nextY>=M) continue;
            if(boxes[nextZ][nextX][nextY]) continue;
            boxes[nextZ][nextX][nextY] = boxes[currentZ][currentX][currentY] + 1;
            q.push({nextZ, nextX, nextY});

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N >> H;
    for(int h=0; h<H; h++) {
        vector<vector<int>> box;
        for(int n=0; n<N; n++) {
            vector<int> row;
            for(int m=0; m<M; m++) {
                int input;
                cin >> input;
                row.push_back(input);
                if(input == 1)
                    q.push({h, n, m});
            }
            box.push_back(row);
        }
        boxes.push_back(box);
    }

    bfs();

    int maximum = 0;
    for(vector<vector<int>> &box : boxes) {
        for(vector<int> &row : box) {
            for(int &tomato : row) {
                if(tomato == 0) {
                    cout << -1;
                    return 0;
                }
                maximum = max(maximum, tomato);
            }
        }
    }

    cout << maximum-1;
    return 0;
}
