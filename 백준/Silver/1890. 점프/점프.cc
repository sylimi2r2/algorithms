#include <iostream>
using namespace std;

int N;
int board[100][100];
long long dp[100][100] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    dp[0][0] = 1;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i==N-1 && j==N-1)
                continue;
            if(j+board[i][j] < N)
                dp[i][j+board[i][j]] += dp[i][j];
            if(i+board[i][j] < N)
                dp[i+board[i][j]][j] += dp[i][j];
        }
    }

    cout << dp[N-1][N-1];
}