#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> board;
    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        string input;
        cin >> input;
        board.push_back(input);
    }

    int solution = 64;
    string chess = "WBWBWBWB";

    for(int i=0; i<N-7; i++) {
        for(int j=0; j<M-7; j++) {
            int count = 0;
            for(int row=0; row<8; row++) {
                for(int col=0; col<8; col++) {
                    if(row%2 ^ (board[i+row][j+col]==chess[col]))
                        count++;
                }
            }
            count = min(count, 64-count);
            if(count < solution)
                solution = count;
        }
    }

    cout << solution;
}
