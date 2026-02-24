#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int smurfs[9] = {0,};
  int sum = 0;
  for(int i=0; i<9; i++) {
    cin >> smurfs[i];
    sum += smurfs[i];
  }

  sort(smurfs, smurfs+9);
  for(int i=0; i<8; i++) {
    for(int j=i+1; j<9; j++) {
      if(sum-smurfs[i]-smurfs[j] == 100) {
        for(int k=0; k<9; k++) {
          if(k != i && k !=j)
            cout << smurfs[k] << '\n';
        }
        return 0;
      }
    }
  }
}
