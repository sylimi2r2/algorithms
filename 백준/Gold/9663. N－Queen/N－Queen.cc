#include <iostream>
using namespace std;

int N, cnt=0;
int board[14];

bool check(int size) {
    for(int i=0; i<size; i++) {
        if(board[size]==board[i] || abs(board[size]-board[i])==size-i)
            return false;
    }
    return true;
}

void dfs(int size) {
    if(size == N) {
        cnt++;
        return;
    }
    for(int i=0; i<N; i++) {
        board[size] = i;
        if(check(size))
            dfs(size+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    dfs(0);
    cout << cnt;
}
