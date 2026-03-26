#include <iostream>
#include <queue>
using namespace std;

#define INF 200000;

int N, problem = 0;
int map[125][125];
int cost[125][125];
pair<int, int> directions[4] = {{0, 1},{0, -1},
                             {1, 0},{-1, 0}};

void dijkstra() {
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cost[i][j] = INF;

  priority_queue<pair<int, pair<int, int>>> pq;
  pq.push({-map[0][0], {0, 0}});
  cost[0][0] = map[0][0];

  while(!pq.empty()) {
    pair<int, int> curNode = pq.top().second;
    int curCost = -pq.top().first;
    pq.pop();
    if(curCost > cost[curNode.first][curNode.second])
      continue;
    for(pair<int, int> d : directions) {
      pair<int, int> nextNode = {curNode.first+d.first, curNode.second+d.second};
      if(nextNode.first>=0 && nextNode.first<N && nextNode.second>=0 && nextNode.second<N) {
        int nextCost = curCost + map[nextNode.first][nextNode.second];
        if(nextCost < cost[nextNode.first][nextNode.second]) {
          pq.push({-nextCost, nextNode});
          cost[nextNode.first][nextNode.second] = nextCost;
        }
      }
    }
  }

  cout << "Problem " << ++problem << ": " << cost[N-1][N-1] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(true) {
    cin >> N;
    if(N == 0)
      break;

    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        cin >> map[i][j];

    dijkstra();
  }
}
