#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    if (N == 1 || N == 2) {
        cout << 1;
        return 0;
    }

    long long cur;
    long long prev1 = 1, prev2 = 1;
    for (int i=3; i<=N; ++i) {
        cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }

    cout << cur;
}