#include <iostream>
#include <string>
using namespace std;

string puzzle[9];

void dfs(int x, int y) {
    if (x == 9 && y == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << puzzle[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }

    if(puzzle[x][y] == '0') {
        for (int i = 0; i < 9; i++) {
            bool isWrong = false;
            char answer = '1' + i;

            for (int j = 0; j < 9; j++) {
                if(puzzle[x][j] == answer) {
                    isWrong = true;
                    break;
                }
                if(puzzle[j][y] == answer) {
                    isWrong = true;
                    break;
                }
            }
            if (isWrong)
                continue;

            int squareX = (x / 3) * 3;
            int squareY = (y / 3) * 3;
            for (int j = 0; j < 9; j++) {
                if (puzzle[squareX + (j / 3)][squareY + (j % 3)] == answer) {
                    isWrong = true;
                    break;
                }
            }
            if (isWrong)
                continue;

            puzzle[x][y] = answer;
            dfs(x + (y + 1) / 9, (y + 1) % 9);
        }
        puzzle[x][y] = '0';
    }

    else {
        dfs(x + (y + 1) / 9, (y + 1) % 9);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 9; i++)
        cin >> puzzle[i];

    dfs(0, 0);
}
