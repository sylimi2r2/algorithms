#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int paper[16];
    int N, M;
    cin >> N >> M;

    for (int i=0; i<N; ++i) {
        string s;
        cin >> s;
        for (int j=0; j<M; ++j) {
            paper[i * M + j] = s[j] - '0';
        }
    }

    int size = N * M;
    int ans = 0;

    // 0 - row, 1 - col
    for (int mask=0; mask<(1 << size); ++mask) {
        int sum = 0;

        for (int i=0; i<N; ++i) {
            int cur = 0;
            for (int j=0; j<M; ++j) {
                int idx = i * M + j;
                if (!(mask & (1 << idx))) {
                    cur = cur * 10 + paper[idx];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        for (int j=0; j<M; ++j) {
            int cur = 0;
            for (int i=0; i<N; ++i) {
                int idx = i * M + j;
                if ((mask & (1 << idx))) {
                    cur = cur * 10 + paper[idx];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        ans = max(ans, sum);
    }

    cout << ans;
}