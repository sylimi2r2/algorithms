#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int circle = 0;
    int x = 0;
    int cWin = 0;
    int xWin = 0;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'O') {
            ++cWin;
        }
        else if (board[0][0] == 'X') {
            ++xWin;
        }    
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        if (board[2][0] == 'O') {
            ++cWin;
        }
        else if (board[2][0] == 'X') {
            ++xWin;
        }    
    }
    for (int i=0; i<3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'O') {
                ++cWin;
            }
            else if (board[i][0] == 'X') {
                ++xWin;
            }
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'O') {
                ++cWin;
            }
            else if (board[0][i] == 'X') {
                ++xWin;
            }
        }
        for (int j=0; j<3; ++j) {
            if (board[i][j] == 'O') {
                ++circle;
            }
            else if (board[i][j] == 'X') {
                ++x;
            }
        }
    }
    if (cWin && xWin == 0 && circle == x + 1) {
        return 1;
    }
    if (cWin == 0 && xWin == 1 && circle == x) {
        return 1;
    }
    if (cWin == 0 && xWin == 0 && (circle == x || circle == x + 1)) {
        return 1;
    }
    return 0;
}