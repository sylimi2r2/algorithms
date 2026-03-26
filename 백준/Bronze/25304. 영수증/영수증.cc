#include <iostream>
using namespace std;

int main() {
  int x; cin >> x;
  int n; cin >> n;
  int a, b;
  for (int i=0; i<n; ++i) {
    cin >> a >> b;
    x -= a * b;
  }
  if (x) cout << "No";
  else cout << "Yes";
  return 0;
}