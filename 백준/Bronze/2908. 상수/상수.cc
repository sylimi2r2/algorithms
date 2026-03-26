#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string A, B;
  cin >> A >> B;

  char tmp;
  tmp = A[0];
  A[0] = A[2];
  A[2] = tmp;
  tmp = B[0];
  B[0] = B[2];
  B[2] = tmp;

  cout << ((stoi(A) > stoi(B)) ? A : B);
}
