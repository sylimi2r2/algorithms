#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  int v;
  for(int i=0; i<n; ++i) {
    cin >> v;
    arr[i] = v;
  }
  cin >> v;
  int cnt=0;
  for(int i=0; i<n; ++i){
    if(arr[i]==v) ++cnt;
  }
  cout << cnt;
  return 0;
}