#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int nums[8];
int sol[8] = {0, };
bool visited[8] = {0,};

void dfs(int size) {
  if(size == M) {
    for(int i=0; i<M; i++) {
      cout << sol[i] << ' ';
    }
    cout << '\n';
    return;
  }

  int pv = -1;
  for(int i=0; i<N; i++) {
    if(!visited[i] && pv!=nums[i]) {
      pv = nums[i];
      visited[i] = true;
      sol[size] = nums[i];
      dfs(size+1);
      visited[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;

  for(int i=0; i<N; i++)
    cin >> nums[i];

  sort(nums, nums+N);

  dfs(0);
}
