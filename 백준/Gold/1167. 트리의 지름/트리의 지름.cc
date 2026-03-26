#include <iostream>
#include <vector>
using namespace std;

int sol = 0, solNode;
vector<pair<int, int>> tree[100001];
bool visited[100001] = {0,};

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

    int V;
    cin >> V;

    int parent, child, weight;
    for(int i=0; i<V; i++) {
        cin >> parent;
        while(true) {
            cin >> child;
            if(child != -1) {
                cin >> weight;
                tree[parent].push_back({child, weight});
                tree[child].push_back({parent, weight});
            }
            else
                break;
        }
    }

    dfs(1, 0);
    for(int i=1; i<=V; i++) {
        visited[i] = false;
    }
    sol = 0;
    dfs(solNode, 0);

    cout << sol;
}
