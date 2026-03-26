#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000;

int N, M, X;
vector<pair<int, int>> edges[1001];
vector<pair<int, int>> reverse[1001];
int go[1001];
int back[1001];

void dijkstra() {
  for(int i=1; i<=N; i++)
    go[i] = INF;

  priority_queue<pair<int, int>> pq;
  pq.push({0, X});
  go[X] = 0;
  while(!pq.empty()) {
    int curNode = pq.top().second;
    int curCost = -pq.top().first;
    pq.pop();
    if(curCost > go[curNode])
      continue;
    for(pair<int, int> edge : reverse[curNode]) {
      int nextNode = edge.first;
      int nextCost = curCost + edge.second;
      if(nextCost < go[nextNode]) {
        pq.push({-nextCost, nextNode});
        go[nextNode] = nextCost;
      }
    }
  }

  for(int i=1; i<=N; i++)
    back[i] = INF;

  pq.push({0, X});
  back[X] = 0;
  while(!pq.empty()) {
    int curNode = pq.top().second;
    int curCost = -pq.top().first;
    pq.pop();
    if(curCost > back[curNode])
      continue;
    for(pair<int, int> edge : edges[curNode]) {
      int nextNode = edge.first;
      int nextCost = curCost + edge.second;
      if(nextCost < back[nextNode]) {
        pq.push({-nextCost, nextNode});
        back[nextNode] = nextCost;
      }
    }
  }

  int answer = 0;
  for(int i=1; i<=N; i++)
    answer = max(answer, go[i]+back[i]);

  cout << answer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M >> X;
  while(M--) {
    int s, d, c;
    cin >> s >> d >> c;
    edges[s].push_back({d, c});
    reverse[d].push_back({s, c});
  }

  dijkstra();
}
