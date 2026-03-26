#include <iostream>
using namespace std;

int dp[101][100001] = {0,};
pair<int, int> products[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, capacity;
    cin >> N >> capacity;

    for(int i=1; i<=N; i++) {
        cin >> products[i].first >> products[i].second;
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=capacity; j++) {
            int select = j - products[i].first;
            if(select >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][select]+products[i].second);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][capacity];
}
