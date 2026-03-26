#include <iostream>
using namespace std;

int main() {
  int N; cin >> N;
  int n = N, count = 0;
  while(1) {
    n = n%10*10 + (n/10 + n%10)%10;
    count += 1;
    if(n == N) break;
  }
  cout << count;
  return 0;
}