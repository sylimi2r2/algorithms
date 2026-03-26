#include <iostream>
using namespace std;

int main() {
  int n, v;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; ++i) {
    cin >> v;
    arr[i] = v;
  }
  int max = arr[0], min = arr[0];
  for(int i : arr) {
    if(i < min) min = i;
    if(i > max) max = i;
  }
  cout << min << ' ' << max;
  return 0;
}