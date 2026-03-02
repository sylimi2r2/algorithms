#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int dp[21] = {0, };
  int N, MAX = 0;
  cin >> N;

  for(int i=1; i<=N; i++) {
    int T, P;
    cin >> T >> P;
    dp[i] = max(dp[i], MAX);
    dp[i+T] = max(dp[i+T], dp[i]+P);
    MAX = max(MAX, dp[i]);
  }
  MAX = max(MAX, dp[N+1]);

  cout << MAX;
}
