#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &b, int i, int j) {
  while(i < j) {
    int temp;
    temp = b[i-1];
    b[i-1] = b[j-1];
    b[j-1] = temp;
    i++;
    j--;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> basket;
  int N, M;
  cin >> N >> M;

  for(int i=0; i<N; i++) {
    basket.push_back(i+1);
  }

  for(int k=0; k<M; k++) {
    int i, j;
    cin >> i >> j;
    reverse(basket, i, j);
  }

  for(int i=0; i<N; i++) {
    cout << basket[i] << " ";
  }

  return 0;
}
