#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
vector<pair<int,int>> blanks;

bool check(int x, int y) {
    int newNum = sudoku[x][y];

    for(int j=0; j<9; j++) {
        if(j!=y && sudoku[x][j]==newNum)
            return false;
    }

    for(int i=0; i<9; i++) {
        if(i!=x && sudoku[i][y]==newNum)
            return false;
    }

    int squareX = x/3*3;
    int squareY = y/3*3;
    for(int i=squareX; i<squareX+3; i++) {
        for(int j=squareY; j<squareY+3; j++) {
            if(i!=x && j!=y && sudoku[i][j]==newNum)
                return false;
        }
    }

    return true;
}

void solution(int fills) {
    if(fills==blanks.size()) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    int blankX = blanks[fills].first;
    int blankY = blanks[fills].second;
    for(int i=1; i<=9; i++) {
        sudoku[blankX][blankY] = i;
        if(check(blankX, blankY))
            solution(fills+1);
        
        sudoku[blankX][blankY] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> sudoku[i][j];
            if(sudoku[i][j]==0)
                blanks.emplace_back(i, j);
        }
    }

    solution(0);
}
