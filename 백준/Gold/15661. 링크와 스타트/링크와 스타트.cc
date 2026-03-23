#include <iostream>

using namespace std;

int ANS = 987654321;
int N;
int abilities[20][20];
bool starts[20];

void dfs(int cur) {
    if (cur == N) {
        int start = 0, link = 0;
        for (int i=0; i<N-1; ++i) {
            for (int j=i+1; j<N; ++j) {
                if (starts[i] && starts[j]) {
                    start += abilities[i][j] + abilities[j][i];
                }
                else if (!starts[i] && !starts[j]) {
                    link += abilities[i][j] + abilities[j][i];
                }
            }
        }

        ANS = min(ANS, abs(start - link));
        return;
    }

    starts[cur] = true;
    dfs(cur + 1);
    starts[cur] = false;
    dfs(cur + 1);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> abilities[i][j];
        }
    }

    starts[0] = true;
    dfs(1);

    cout << ANS;
}