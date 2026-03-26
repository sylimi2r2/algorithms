#include <iostream>
#include <vector>
using namespace std;

int sol = 0, solNode;
vector<pair<int, int>> tree[10001];
bool visited[10001] = {0,};

void dfs(int start, int distance) {
    visited[start] = true;
    if(distance > sol) {
        sol = distance;
        solNode = start;
    }
    for(pair<int, int> next : tree[start]) {
        if(!visited[next.first]) {
            visited[next.first] = true;
            dfs(next.first, distance+next.second);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n-1; i++) {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].push_back({child, weight});
        tree[child].push_back({parent, weight});
    }

    dfs(1, 0);
    for(int i=1; i<=n; i++) {
        visited[i] = false;
    }
    sol = 0;
    dfs(solNode, 0);

    cout << sol;
}
