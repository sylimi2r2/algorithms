#include <iostream>
using namespace std;

const int MOD = 10007;
int N;
int comb[53][53];
int sol = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int n = 0; n <= 52; ++n) {
        comb[n][0] = comb[n][n] = 1;
        for (int k = 1; k < n; ++k) {
            comb[n][k] = (comb[n - 1][k - 1] + comb[n - 1][k]) % MOD;
        }
    }

    for (int i = 4; i <= N; i += 4) {
        if ((i / 4) % 2) {
            sol += (comb[13][i / 4] * comb[52 - i][N - i]);
        }
        else {
            sol -= (comb[13][i / 4] * comb[52 - i][N - i]);
        }

        sol %= MOD;
        if (sol < 0)
            sol += MOD;
    }

    cout << sol;
}
