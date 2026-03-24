#include <iostream>

using namespace std;

int N;
int picked[8];
bool visited[9];

void dfs(int cnt) {
    if (cnt == N) {
        for (int i=0; i<N; ++i) {
            cout << picked[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=1; i<=N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            picked[cnt] = i;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    dfs(0);
}
