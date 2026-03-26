#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int x, y;
  x = (c*e-f*b)/(a*e-d*b);
  y = (a*f-c*d)/(a*e-d*b);
  cout << x << " " << y;
}
