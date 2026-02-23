#include <iostream>

using namespace std;

long long dp[1000001] = {0,};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, input;

    for (int i=1; i<=1000000; ++i) {
        for (int j=i; j<=1000000; j+=i) {
            dp[j] += i;
        }
    }
    for (int i=2; i<=1000000; ++i) {
        dp[i] += dp[i-1];
    }

    cin >> N;
    while (N--) {
        cin >> input;
        cout << dp[input] << '\n';
    }
}