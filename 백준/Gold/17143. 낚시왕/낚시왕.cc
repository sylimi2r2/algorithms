#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, M;
int r, c, s, d, z;
int modR, modC;
int sol = 0;
int sea[101][101] = {0,};
vector<vector<int>> shark;
bool captured[10001] = {0,};
pair<int, int> direction[5] = {{0, 0},
                               {-1, 0},
                               {1, 0},
                               {0, 1},
                               {0, -1}};

void fishing(int column) {
    for (int i = 1; i <= R; ++i) {
        if (sea[i][column] != 0) {
            captured[sea[i][column]] = true;
            sol += shark[sea[i][column]][0];
            sea[i][column] = 0;
            break;
        }
    }

    for (int i = 1; i <= M; ++i) {
        if (!captured[i]) {
            sea[shark[i][1]][shark[i][2]] = 0;
        }
    }

    for (int i = 1; i <= M; ++i) {
        if (!captured[i]) {
            int nextR = shark[i][1];
            int nextC = shark[i][2];
            int dir = shark[i][4];
            int distance = (shark[i][3] % (dir <= 2 ? modR : modC));
            while (distance--) {
                nextR += direction[dir].first;
                nextC += direction[dir].second;
                if (nextR < 1 || nextR > R || nextC < 1 || nextC > C) {
                    switch (dir) {
                        case 1:
                            dir = 2;
                            break;
                        case 2:
                            dir = 1;
                            break;
                        case 3:
                            dir = 4;
                            break;
                        case 4:
                            dir = 3;
                            break;
                    }
                    nextR += 2 * direction[dir].first;
                    nextC += 2 * direction[dir].second;
                }
            }
            if (sea[nextR][nextC] != 0) {
                captured[sea[nextR][nextC]] = true;
            }
            sea[nextR][nextC] = i;
            shark[i][1] = nextR;
            shark[i][2] = nextC;
            shark[i][4] = dir;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    shark.push_back({-1, -1, -1, -1, -1});
    captured[0] = true;

    cin >> R >> C >> M;
    modR = (R - 1) * 2;
    modC = (C - 1) * 2;
    for (int i = 1; i <= M; ++i) {
        cin >> r >> c >> s >> d >> z;
        shark.push_back({z, r, c, s, d});
    }
    sort(shark.begin(), shark.end());
    for (int i = 1; i <= M; ++i) {
        sea[shark[i][1]][shark[i][2]] = i;
    }

    for (int i = 1; i <= C; ++i) {
        fishing(i);
    }
    cout << sol;
}
