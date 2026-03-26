#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R;
int people[50][50];
bool visited[50][50];
pair<int, int> directions[4] = {{0, 1}, {0, -1},
                                {1, 0}, {-1, 0}};

void bfs() {
    int cnt = 0;
    while(true) {
        bool flag = false;

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                visited[i][j] = false;

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(!visited[i][j]) {
                    int sum = 0;
                    vector<pair<int, int>> v;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while(!q.empty()) {
                        pair<int, int> cur = q.front();
                        v.push_back(cur);
                        sum += people[cur.first][cur.second];
                        q.pop();
                        for(pair<int, int> d : directions) {
                            pair<int, int> next = {cur.first+d.first, cur.second+d.second};
                            if(next.first>=0 && next.first<N && next.second>=0 && next.second<N) {
                                if(visited[next.first][next.second] == false) {
                                    int diff = abs(people[cur.first][cur.second]-people[next.first][next.second]);
                                    if(diff>=L && diff<=R) {
                                        q.push(next);
                                        visited[next.first][next.second] = true;
                                    }
                                }
                            }
                        }
                    }

                    if(v.size() != 1) {
                        flag = true;
                        int div = sum/v.size();
                        for(pair<int, int> city : v) {
                            people[city.first][city.second] = div;
                        }
                    }
                }
            }
        }

        if(flag)
            cnt++;
        else
            break;
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L >> R;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> people[i][j];

    bfs();
}
