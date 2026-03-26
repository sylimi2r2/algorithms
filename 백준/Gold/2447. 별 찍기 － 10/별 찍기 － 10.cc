#include <iostream>
using namespace std;

char star[2187][2187];

void drawing(int n, int x, int y) {
  if(n == 3) {
    for(int i=0; i<3; i++)
      star[x][y+i] = '*';
    star[x+1][y] = '*';
    star[x+1][y+2] = '*';
    for(int i=0; i<3; i++)
      star[x+2][y+i] = '*';
    return;
  }
  int next = n/3;
  drawing(next, x, y);
  drawing(next, x, y+next);
  drawing(next, x, y+2*next);
  drawing(next, x+next, y);
  drawing(next, x+next, y+2*next);
  drawing(next, x+2*next, y);
  drawing(next, x+2*next, y+next);
  drawing(next, x+2*next, y+2*next);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      star[i][j] = ' ';

  drawing(N, 0, 0);

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cout << star[i][j];
    }
    cout << '\n';
  }

}
