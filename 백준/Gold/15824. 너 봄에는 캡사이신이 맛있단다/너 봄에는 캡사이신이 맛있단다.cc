#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
int N;
int num[300000];
long long cache[300001];
long long p = 0, m = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> num[i];
    }
    sort(num, num + N);

    cache[0] = 1;
    cache[1] = 2;
    for (int i = 2; i < N; ++i) {
        cache[i] = (2 * cache[i-1]) % MOD;
    }

    for (int i = 0; i < N; ++i) {
        p = (p + num[i] * (cache[i] - 1)) % MOD;
        m = (m + num[i] * (cache[N - i - 1] - 1)) % MOD;
    }

    if (p - m >= 0) {
        p -= m;
    }
    else {
        p = p - m + MOD;
    }

    cout << p;
}
