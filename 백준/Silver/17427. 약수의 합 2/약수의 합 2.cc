#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    long long ans = 0;

    cin >> N;
    for (int i=1; i<=N; ++i) {
        ans += (N/i) * i;
    }

    cout << ans;
}