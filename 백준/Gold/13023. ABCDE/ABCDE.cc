#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> friendship[2001];
bool visited[2001] = {0,};

void dfs(int size, int cur) {
    if(size == 5) {
        cout << 1;
        exit(0);
    }
    for(int next : friendship[cur]) {
        if(visited[next])
            continue;

        visited[next] = true;
        dfs(size+1, next);
        visited[next] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    while(M--) {
        int a, b;
        cin >> a >> b;

        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }

    for(int i=0; i<N; i++) {
        visited[i] = true;
        dfs(1, i);
        visited[i] = false;
    }

    cout << 0;
}
