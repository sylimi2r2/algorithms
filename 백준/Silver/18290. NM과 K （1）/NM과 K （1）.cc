#include <iostream>

using namespace std;

int ANS = -1000001;
int N, M, K;
int board[10][10];
int directions[2][2] = {{0, -1}, {-1, 0}};
bool visited[10][10];

void dfs(int cnt, int ret, int prev) {
    if (cnt == K) {
        ANS = max(ANS, ret);
        return;
    }

    for (int next=prev+1; next<N*M; ++next) {
        int r = next / M;
        int c = next % M;
        bool flag = true;
        for (auto direction: directions) {
            int checkR = r + direction[0];
            int checkC = c + direction[1];
            if (checkR>=0 && checkR<N && checkC>=0 && checkC<M && visited[checkR][checkC]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            visited[r][c] = true;
            dfs(cnt + 1, ret + board[r][c], next);
            visited[r][c] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fill(&visited[0][0], &visited[0][0] + 100, false);

    cin >> N >> M >> K;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
        }
    }


    dfs(0, 0, -1);

    cout << ANS;
}