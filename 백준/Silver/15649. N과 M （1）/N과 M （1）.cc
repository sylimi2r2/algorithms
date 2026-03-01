#include <iostream>
#include <vector>

using namespace std;

int N, M;
int picks[8];
bool picked[9];

void dfs(int cnt) {
    if (cnt == M) {
        for (int i=0; i<M; ++i) {
            cout << picks[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=1; i<=N; ++i) {
        if (!picked[i]) {
            picked[i] = true;
            picks[cnt] = i;
            dfs(cnt + 1);
            picked[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fill(picks, picks + 8, 0);
    fill(picked, picked + 9, false);

    cin >> N >> M;

    dfs(0);
}