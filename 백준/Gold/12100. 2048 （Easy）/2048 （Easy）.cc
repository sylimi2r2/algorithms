#include <iostream>
#include <vector>
using namespace std;

int board[20][20];
int N;
int MAX = 0;

void Up() {
    bool visited[20][20] = {0,};

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int pos = i;
            while (pos > 0) {
                if (board[pos - 1][j] == 0) {
                    board[pos - 1][j] = board[pos][j];
                    board[pos][j] = 0;
                    pos--;
                    continue;
                } else if (board[pos - 1][j] == board[pos][j] && !visited[pos-1][j]) {
                    board[pos - 1][j] *= 2;
                    visited[pos - 1][j] = true;
                    board[pos][j] = 0;
                } else
                    break;
            }
        }
    }
}

void Down() {
    bool visited[20][20] = {0,};

    for (int i = N-2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            int pos = i;
            while (pos < N-1) {
                if (board[pos + 1][j] == 0) {
                    board[pos + 1][j] = board[pos][j];
                    board[pos][j] = 0;
                    pos++;
                    continue;
                } else if (board[pos + 1][j] == board[pos][j] && !visited[pos+1][j]) {
                    board[pos + 1][j] *= 2;
                    visited[pos + 1][j] = true;
                    board[pos][j] = 0;
                } else
                    break;
            }
        }
    }
}

void Right() {
    bool visited[20][20] = {0,};

    for (int i = N-2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            int pos = i;
            while (pos < N-1) {
                if (board[j][pos + 1] == 0) {
                    board[j][pos + 1] = board[j][pos];
                    board[j][pos] = 0;
                    pos++;
                    continue;
                } else if (board[j][pos + 1] == board[j][pos] && !visited[j][pos + 1]) {
                    board[j][pos + 1] *= 2;
                    visited[j][pos + 1] = true;
                    board[j][pos] = 0;
                } else
                    break;
            }
        }
    }
}

void Left() {
    bool visited[20][20] = {0,};

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int pos = i;
            while (pos > 0) {
                if (board[j][pos - 1] == 0) {
                    board[j][pos - 1] = board[j][pos];
                    board[j][pos] = 0;
                    pos--;
                    continue;
                } else if (board[j][pos - 1] == board[j][pos] && !visited[j][pos - 1]) {
                    board[j][pos - 1] *= 2;
                    visited[j][pos - 1] = true;
                    board[j][pos] = 0;
                } else
                    break;
            }
        }
    }
}

void prev(int a[][20], int b[][20]) {
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            a[i][j] = b[i][j];
}

void sol(int depth, int mode) {
    if(depth == 5) {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                MAX = max(MAX, board[i][j]);

        return;
    }

    int previous[20][20];
    prev(previous, board);

    switch(mode) {
        case 1:
            Up();
            break;
        case 2:
            Down();
            break;
        case 3:
            Right();
            break;
        case 4:
            Left();
            break;
    }

    for(int i=1; i<=4; i++)
        sol(depth+1, i);

    prev(board, previous);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    for(int i=1; i<=4; i++)
        sol(0, i);

    cout << MAX;
}
