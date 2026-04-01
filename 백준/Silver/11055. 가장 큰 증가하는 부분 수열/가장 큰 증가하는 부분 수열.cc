#include <iostream>
#include <algorithm>

using namespace std;

int A[1001];
int dp[1001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i=1; i<=N; ++i) {
        cin >> A[i];
        for (int j=i-1; j>0; --j) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += A[i];
    }

    cout << *max_element(dp + 1, dp + N + 1);


}