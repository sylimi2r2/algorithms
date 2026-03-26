#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

int field[50][50];
pair<int, int> directions[4] = {{0, 1}, {0, -1},
                                {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int M, N, K, cnt = 0;
        cin >> M >> N >> K;
        vector<pair<int, int>> cabbages;
        queue<pair<int,int>> q;
        for(int i=0; i<N; i++) {
            memset(field[i], 0, sizeof(bool)*M);
        }
        for(int i=0; i<K; i++) {
            int x, y;
            cin >> x >> y;
            cabbages.push_back({y, x});
            field[y][x] = true;
        }
        for(pair<int,int> start : cabbages) {
            if(field[start.first][start.second]==1) {
                q.push(start);
                field[start.first][start.second] = 2;
                cnt++;
                while(!q.empty()) {
                    pair<int, int> current = q.front();
                    q.pop();
                    for(pair<int, int> d : directions) {
                        pair<int, int> next = {current.first+d.first, current.second+d.second};
                        if(next.first<0 || next.first>=N ||
                        next.second<0 || next.second>=M) continue;
                        if(field[next.first][next.second]==1) {
                            q.push(next);
                            field[next.first][next.second] = 2;
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}
