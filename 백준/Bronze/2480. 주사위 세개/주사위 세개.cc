#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b) {
    if (a == c) cout << 10000 + 1000 * a;
    else cout << 1000 + 100 * a;
  }
  else if (a == c) {
    cout << 1000 + 100 * a;
  }
  else if (b == c) {
    cout << 1000 + 100 * b;
  }
  else cout << 100 * max(a, max(b, c));
  return 0;
}