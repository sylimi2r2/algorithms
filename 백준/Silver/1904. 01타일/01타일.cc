#include <iostream>
using namespace std;

int dp[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  dp[1] = 1;
  dp[2] = 2;

  int N;
  cin >> N;

  for(int i=3; i<=N; i++)
    dp[i] = (dp[i-1] + dp[i-2]) % 15746;

  cout << dp[N];

}
