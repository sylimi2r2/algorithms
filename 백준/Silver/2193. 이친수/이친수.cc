#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pair<long long, long long> dp[91];
  dp[1] = {0, 1};
  int N;
  cin >> N;

  for(int i=2; i<=N; i++) {
    dp[i] = {dp[i-1].first+dp[i-1].second, dp[i-1].first};
  }

  cout << (dp[N].first+dp[N].second);
}