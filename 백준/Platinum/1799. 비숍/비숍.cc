#include <iostream>
#include <vector>
using namespace std;

int b = 0, w = 0;
int n, input;
vector<pair<int, int>> space;
vector<pair<int, int>> black;
vector<pair<int, int>> white;
bool board[10][10] = {0,};

bool check(int r, int c) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(abs(i-r) == abs(j-c)) {
                if(board[i][j])
                    return false;
            }
        }
    }

    return true;
}

void dfsB(int index, int cnt) {
    if(index == black.size()) {
        return;
    }

    if(check(black[index].first, black[index].second)) {
        b = max(b, cnt+1);
        board[black[index].first][black[index].second] = true;
        dfsB(index + 1, cnt + 1);
        board[black[index].first][black[index].second] = false;
        dfsB(index + 1, cnt);
    }
    else {
        dfsB(index + 1, cnt);
    }
}

void dfsW(int index, int cnt) {
    if(index == white.size()) {
        return;
    }

    if(check(white[index].first, white[index].second)) {
        w = max(w, cnt+1);
        board[white[index].first][white[index].second] = true;
        dfsW(index + 1, cnt + 1);
        board[white[index].first][white[index].second] = false;
        dfsW(index + 1, cnt);
    }
    else {
        dfsW(index + 1, cnt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> input;
            if(input == 1) {
                if((i+j)%2) {
                    black.emplace_back(i, j);
                }
                else {
                    white.emplace_back(i, j);
                }
            }
        }
    }

    dfsB(0, 0);
    dfsW(0, 0);

    cout << (b+w);
}
