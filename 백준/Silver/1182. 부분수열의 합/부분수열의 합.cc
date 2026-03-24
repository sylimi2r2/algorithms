#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, S;
    cin >> N >> S;

    vector<int> v(N);
    for (int i=0; i<N; ++i) {
        cin >> v[i];
    }

    int limit = 1 << N;
    vector<int> sum(limit, 0);

    int sol = 0;

    for (int mask=1; mask<limit; ++mask) {
        int lsb = mask & -mask;
        int idx = __builtin_ctz(lsb);
        int prev = mask ^ lsb;

        sum[mask] = sum[prev] + v[idx];

        if (sum[mask] == S) {
            ++sol;
        }
    }

    cout << sol;
}