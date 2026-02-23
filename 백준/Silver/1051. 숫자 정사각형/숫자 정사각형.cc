#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;
    string input;
    int maxLen = 1;

    cin >> N >> M;
    vector<string> board;

    for (int i=0; i<N; ++i) {
        cin >> input;
        board.push_back(input);
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            for (int len=maxLen; i+len<N && j+len<M; ++len) {
                char c = board[i][j];
                if (board[i][j+len] == c &&
                    board[i+len][j] == c &&
                    board[i+len][j+len] == c) {
                    maxLen = len + 1;
                }
            }
        }
    }

    cout << maxLen * maxLen;
}