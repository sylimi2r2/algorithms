#include <iostream>
#include <array>
using namespace std;

int main() {
  array num = {1, 1, 2, 2, 2, 8};
  int n;
  for(int &it : num){
    cin >> n;
    it -= n;
  }
  for(int &it : num) {
    cout << it << ' ';
  }
  return 0;
}
