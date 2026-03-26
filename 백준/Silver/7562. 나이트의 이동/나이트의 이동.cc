#include <iostream>
#include <queue>
using namespace std;

bool visited[300][300];
int l, sol;
pair<int, int> start, dest;
pair<int, int> directions[8] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};


void bfs() {
  queue<pair<pair<int, int>, int>> q;
  q.push({start, 0});

  while(!q.empty()) {
    pair<int, int> current = q.front().first;
    int moves = q.front().second;
    if(current == dest) {
      sol = moves;
      return;
    }
    q.pop();
    for(pair<int, int> d : directions) {
      pair<int, int> next = {current.first+d.first, current.second+d.second};
      if(next.first<l && next.first>=0 &&
         next.second<l && next.second>=0) {
        if(!visited[next.first][next.second]) {
          q.push({next, moves+1});
          visited[next.first][next.second] = true;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;

  while(T--) {
    cin >> l;
    cin >> start.first >> start.second;
    cin >> dest.first >> dest.second;

    for(int i=0; i<l; i++)
      for(int j=0; j<l; j++)
        visited[i][j] = false;
    sol = 0;

    bfs();

    cout << sol << '\n';
  }
}
