#include <iostream>
using namespace std;

int main() {
  int n, x, v;
  cin >> n >> x;
  int arr[n];
  for(int i=0; i<n; ++i) {
    cin >> v;
    arr[i] = v;
  }
  for(int i=0; i<n; ++i) {
    if(arr[i] < x) cout << arr[i] << ' ';
  }
  return 0;
}