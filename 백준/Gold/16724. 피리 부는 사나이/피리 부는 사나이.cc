#include <iostream>
using namespace std;

int N;
int M;
string map[1000];
int sec[1000][1000] = {0, };

int bfs(int x, int y, int s) {
    int &ret = sec[x][y];
    if (ret != 0) {
        return ret;
    }

    ret = s;
    switch (map[x][y]) {
        case 'U':
            ret = bfs(x - 1, y, s);
            break;
        case 'D':
            ret = bfs(x + 1, y, s);
            break;
        case 'L':
            ret = bfs(x, y - 1, s);
            break;
        case 'R':
            ret = bfs(x, y + 1, s);
            break;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> map[i];
    }

    int sol = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (sec[i][j] == 0) {
                sol++;
                if (bfs(i, j, sol) < sol) {
                    sol--;
                }
            }
        }
    }

    cout << sol;
}
