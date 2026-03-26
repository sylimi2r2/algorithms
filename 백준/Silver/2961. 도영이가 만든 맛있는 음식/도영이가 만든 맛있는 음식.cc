#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pair<int, int> ingredients[10];
  int N;
  cin >> N;

  for(int i=0; i<N; i++)
    cin >> ingredients[i].first >> ingredients[i].second;

  int sol = 1000000001;
  int cases = 1 << N;
  for(int i=1; i<cases; i++) {
    int S = 1;
    int B = 0;
    for(int j=0; j<N; j++) {
      if(i & (1 << j)) {
        S *= ingredients[j].first;
        B += ingredients[j].second;
      }
    }
    sol = min(sol, abs(S-B));
  }

  cout << sol;
}
