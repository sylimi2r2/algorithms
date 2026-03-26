#include <iostream>
using namespace std;

int sol = 11;
string solString = "";
int N, M;
string board[10];

void dfs(pair<int, int> r, pair<int, int> b, int cnt, string tmp) {
    if (cnt >= sol) {
        return;
    }

    int rFlag = 0, bFlag = 0;
    pair<int, int> nextR, nextB;
    int direction;

    //right - {0, 1}
    nextR = r;
    nextB = b;
    direction = 1;
    while (rFlag == 0 || bFlag == 0) {
        if (rFlag == 0) {
            nextR.second += direction;
            if (board[nextR.first][nextR.second] == '#') {
                nextR.second -= direction;
                rFlag = -1;
            }
            else if (board[nextR.first][nextR.second] == 'O') {
                rFlag = 1;
            }
        }

        if (bFlag == 0) {
            nextB.second += direction;
            if (board[nextB.first][nextB.second] == '#') {
                nextB.second -= direction;
                bFlag = -1;
            }
            else if (board[nextB.first][nextB.second] == 'O') {
                bFlag = 1;
            }
        }
    }

    if (rFlag == 1 && bFlag != 1) {
        sol = cnt;
        solString = tmp + 'R';
        return;
    }
    else if (rFlag == -1 && bFlag == -1) {
        if (nextR == nextB) {
            if (r.second > b.second) {
                nextB.second -= direction;
            }
            else {
                nextR.second -= direction;
            }
        }

        if(r != nextR || b != nextB) {
            dfs(nextR, nextB, cnt + 1, tmp+'R');
        }
    }

    //left - {0, -1}
    rFlag = 0, bFlag = 0;
    nextR = r;
    nextB = b;
    direction = -1;
    while (rFlag == 0 || bFlag == 0) {
        if (rFlag == 0) {
            nextR.second += direction;
            if (board[nextR.first][nextR.second] == '#') {
                nextR.second -= direction;
                rFlag = -1;
            }
            else if (board[nextR.first][nextR.second] == 'O') {
                rFlag = 1;
            }
        }

        if (bFlag == 0) {
            nextB.second += direction;
            if (board[nextB.first][nextB.second] == '#') {
                nextB.second -= direction;
                bFlag = -1;
            }
            else if (board[nextB.first][nextB.second] == 'O') {
                bFlag = 1;
            }
        }
    }

    if (rFlag == 1 && bFlag != 1) {
        sol = cnt;
        solString = tmp + 'L';
        return;
    }
    else if (rFlag == -1 && bFlag == -1) {
        if (nextR == nextB) {
            if (r.second < b.second) {
                nextB.second -= direction;
            }
            else {
                nextR.second -= direction;
            }
        }

        if(r != nextR || b != nextB) {
            dfs(nextR, nextB, cnt + 1, tmp+'L');
        }
    }

    //down - {1, 0}
    rFlag = 0, bFlag = 0;
    nextR = r;
    nextB = b;
    direction = 1;
    while (rFlag == 0 || bFlag == 0) {
        if (rFlag == 0) {
            nextR.first += direction;
            if (board[nextR.first][nextR.second] == '#') {
                nextR.first -= direction;
                rFlag = -1;
            }
            else if (board[nextR.first][nextR.second] == 'O') {
                rFlag = 1;
            }
        }

        if (bFlag == 0) {
            nextB.first += direction;
            if (board[nextB.first][nextB.second] == '#') {
                nextB.first -= direction;
                bFlag = -1;
            }
            else if (board[nextB.first][nextB.second] == 'O') {
                bFlag = 1;
            }
        }
    }

    if (rFlag == 1 && bFlag != 1) {
        sol = cnt;
        solString = tmp + 'D';
        return;
    }
    else if (rFlag == -1 && bFlag == -1) {
        if (nextR == nextB) {
            if (r.first > b.first) {
                nextB.first -= direction;
            }
            else {
                nextR.first -= direction;
            }
        }

        if(r != nextR || b != nextB) {
            dfs(nextR, nextB, cnt + 1, tmp+'D');
        }
    }

    //up - {-1, 0}
    rFlag = 0, bFlag = 0;
    nextR = r;
    nextB = b;
    direction = -1;
    while (rFlag == 0 || bFlag == 0) {
        if (rFlag == 0) {
            nextR.first += direction;
            if (board[nextR.first][nextR.second] == '#') {
                nextR.first -= direction;
                rFlag = -1;
            }
            else if (board[nextR.first][nextR.second] == 'O') {
                rFlag = 1;
            }
        }

        if (bFlag == 0) {
            nextB.first += direction;
            if (board[nextB.first][nextB.second] == '#') {
                nextB.first -= direction;
                bFlag = -1;
            }
            else if (board[nextB.first][nextB.second] == 'O') {
                bFlag = 1;
            }
        }
    }

    if (rFlag == 1 && bFlag != 1) {
        sol = cnt;
        solString = tmp + 'U';
        return;
    }
    else if (rFlag == -1 && bFlag == -1) {
        if (nextR == nextB) {
            if (r.first < b.first) {
                nextB.first -= direction;
            }
            else {
                nextR.first -= direction;
            }
        }

        if(r != nextR || b != nextB) {
            dfs(nextR, nextB, cnt + 1, tmp+'U');
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<int, int> red;
    pair<int, int> blue;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 1; j < M; j++) {
            if (board[i][j] == 'R') {
                red.first = i;
                red.second = j;
            }
            else if (board[i][j] == 'B') {
                blue.first = i;
                blue.second = j;
            }
        }
    }

    dfs(red, blue, 1 , "");

    if (sol != 11) {
        cout << sol << '\n' << solString;
    }
    else
        cout << -1;
}