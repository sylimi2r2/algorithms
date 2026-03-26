#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int X;
  cin >> X;

  int sol = 0;
  for(int i=0; i<8; i++) {
    if(X & (1 << i))
      sol++;
  }

  cout << sol;
}
