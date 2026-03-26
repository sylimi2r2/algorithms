#include <iostream>
using namespace std;

int paper[2187][2187] = {0,};
int count[3] = {0,};

void check(int size, int row, int col) {
    int number = paper[row][col];
    for(int i=row; i<row+size; i++) {
        for(int j=col; j<col+size; j++) {
            if(paper[i][j] != number)
                goto divide;
        }
    }
    count[number+1]++;
    return;

    divide: {
        int resize = size/3;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                check(resize, row+i*resize, col+j*resize);
            }
        }
    };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int input;
            cin >> input;
            paper[i][j] = input;
        }
    }

    check(N, 0, 0);
    for(int i=0; i<3; i++) {
        cout << count[i] << '\n';
    }
}
