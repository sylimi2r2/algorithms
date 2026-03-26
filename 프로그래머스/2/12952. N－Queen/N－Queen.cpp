#include <string>
#include <vector>

using namespace std;

int answer = 0;
int board[12] = {0,};
int N;

bool check(int col) {
    for (int i=0; i<col; ++i) {
        if (board[col] == board[i] || abs(board[col] - board[i]) == col - i) {
            return false;
        }
    }
    
    return true;
}

void dfs(int col) {
    if (col == N) {
        ++answer;
        return;
    }
    
    for (int i=1; i<=N; ++i) {
        board[col] = i;
        if (check(col)) {
            dfs(col + 1);
        }
    }
}

int solution(int n) {
    N = n;
    dfs(0);
    return answer;
}