#include <iostream>

using namespace std;

int N, M;
int picks[7] = {0,};

void dfs(int cnt) {
    if (cnt == M) {
        for (int i=0; i<M; ++i) {
            cout << picks[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i=1; i<=N; ++i) {
        picks[cnt] = i;
        dfs(cnt + 1);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    dfs(0);
}