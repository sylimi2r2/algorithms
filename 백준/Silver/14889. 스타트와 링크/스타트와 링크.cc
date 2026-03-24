#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    int S[20][20];
    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> S[i][j];
        }
    }

    int ans = 987654321;

    for (int mask=1; mask<(1 << N); ++mask) {
        if (__builtin_popcount(mask) != N/2)
            continue;

        int start = 0;
        int link = 0;

        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                bool isStartI = mask & (1 << i);
                bool isStartJ = mask & (1 << j);

                if (isStartI && isStartJ) {
                    start += S[i][j] + S[j][i];
                }
                else if (!isStartI && !isStartJ) {
                    link += S[i][j] + S[j][i];
                }
            }
        }

        ans = min(ans, abs(start - link));
    }

    cout << ans;
}