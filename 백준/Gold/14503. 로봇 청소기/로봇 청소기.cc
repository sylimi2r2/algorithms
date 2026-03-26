#include <iostream>
using namespace std;

int sol = 0;
int N, M;
int r, c;
int d;
int map[50][50];
pair<int, int> direction[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> map[i][j];

    while(true) {
        if(map[r][c] == 0) {
            map[r][c] = -1;
            sol++;
        }

        bool flag = false;

        for(pair<int, int> D : direction) {
            int nextR = r + D.first;
            int nextC = c + D.second;

            if(nextR>0 && nextR<N-1 && nextC>0 && nextC<M-1) {
                if(map[nextR][nextC] == 0) {
                    flag = true;
                    break;
                }
            }
        }

        if(flag) {
            for(int i=0; i<4; i++) {
                d = (d+3)%4;
                int nextR = r + direction[d].first;
                int nextC = c + direction[d].second;

                if (map[nextR][nextC] == 0) {
                    r = nextR;
                    c = nextC;
                    break;
                }
            }
        }
        else {
            int nextR = r + direction[(d+2)%4].first;
            int nextC = c + direction[(d+2)%4].second;

            if(map[nextR][nextC] != 1) {
                r = nextR;
                c = nextC;
            }
            else {
                break;
            }
        }
    }

    cout << sol;
}
