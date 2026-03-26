#include <iostream>
using namespace std;

int paper[128][128] = {0,};
int count[2] = {0,};

void check(int size, int row, int col) {
    int number = paper[row][col];
    for(int i=row; i<row+size; i++) {
        for(int j=col; j<col+size; j++) {
            if(paper[i][j] != number)
                goto divide;
        }
    }
    count[number]++;
    return;

    divide: {
        int resize = size/2;
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
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
    for(int i=0; i<2; i++) {
        cout << count[i] << '\n';
    }
}
