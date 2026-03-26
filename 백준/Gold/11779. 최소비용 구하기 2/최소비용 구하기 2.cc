#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100000000;

int start, dest;
vector<pair<int, int>> edges[1001];
int costs[1001];
int route[1001];

void dijkstra() {
  priority_queue<pair<int, int>> pq;
  pq.push({0, start});
  costs[start] = 0;

  while(!pq.empty()) {
    int currentCost = -pq.top().first;
    int currentNode = pq.top().second;
    pq.pop();
    if(currentCost > costs[currentNode])
      continue;
    for(pair<int, int> edge : edges[currentNode]) {
      int nextCost = currentCost + edge.second;
      int nextNode = edge.first;
      if(nextCost < costs[nextNode]) {
        route[nextNode] = currentNode;
        costs[nextNode] = nextCost;
        pq.push({-nextCost, nextNode});
      }
    }
  }

  vector<int> sol;
  sol.push_back(dest);
  int previous = dest;
  while(previous != start) {
    previous = route[previous];
    sol.push_back(previous);
  }

  cout << costs[dest] << '\n';
  cout << sol.size() << '\n';
  for(int i=sol.size()-1; i>=0; i--)
    cout << sol[i] << ' ';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for(int i=1; i<=n; i++) {
    costs[i] = MAX;
  }

  while(m--) {
    int s, d, c;
    cin >> s >> d >> c;
    edges[s].push_back({d, c});
  }

  cin >> start >> dest;

  dijkstra();
}
