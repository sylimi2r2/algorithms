#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> board;

void swap(int r1, int c1, int r2, int c2) {
    char tmp = board[r1][c1];
    board[r1][c1] = board[r2][c2];
    board[r2][c2] = tmp;
}

int checkRow(int r) {
    int ret = 1;
    int cnt = 1;
    char color = board[r][0];

    for (int c=1; c<N; ++c) {
        if (board[r][c] == color) {
            ++cnt;
            ret = max(ret, cnt);
            continue;
        }
        color = board[r][c];
        cnt = 1;
    }

    return ret;
}

int checkCol(int c) {
    int ret = 1;
    int cnt = 1;
    char color = board[0][c];

    for (int r=1; r<N; ++r) {
        if (board[r][c] == color) {
            ++cnt;
            ret = max(ret, cnt);
            continue;
        }
        color = board[r][c];
        cnt = 1;
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int ans = 1;

    cin >> N;
    for (int i=0; i<N; ++i) {
        string row;
        cin >> row;
        board.push_back(row);
    }

    for (int r=0; r<N-1; ++r) {
        for (int c=0; c<N; ++c) {
            swap(r, c, r + 1, c);
            ans = max(ans, checkRow(r));
            ans = max(ans, checkRow(r + 1));
            ans = max(ans, checkCol(c));
            swap(r, c, r + 1, c);
        }
    }
    for (int r=0; r<N; ++r) {
        for (int c=0; c<N-1; ++c) {
            swap(r, c, r, c + 1);
            ans = max(ans, checkRow(r));
            ans = max(ans, checkCol(c));
            ans = max(ans, checkCol(c + 1));
            swap(r, c, r, c + 1);
        }
    }

    cout << ans;
}