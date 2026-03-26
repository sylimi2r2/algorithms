#include <iostream>

using namespace std;

const int MOD = 1'000'000'000;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int prev[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int cur[10] = {0};
    for (int i=2; i<=N; ++i) {
        cur[0] = prev[1];
        cur[9] = prev[8];
        for (int j=1; j<=8; ++j) {
            cur[j] = (prev[j - 1] + prev[j + 1]) % MOD;
        }

        for (int j=0; j<=9; ++j) {
            prev[j] = cur[j];
        }
    }

    int ans = 0;
    for (int i=0; i<=9; ++i) {
        ans = (ans + prev[i]) % MOD;
    }

    cout << ans;
}