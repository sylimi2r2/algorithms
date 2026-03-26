#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> scores;
  int N;
  cin >> N;
  int max = 0;

  for(int i=0; i<N; i++) {
    int score;
    cin >> score;
    if(score > max) max = score;
    scores.push_back(score);
  }

  double sum = 0;
  for(int i=0; i<N; i++) {
    sum += double(scores[i]) / max * 100;
  }
  cout << sum/N;
  return 0;
}
