#include <iostream>
#include <vector>
using namespace std;

int N, u, v;
int cache[1000001][2];
vector<int> sns[1000001];
bool visited[1000001] = {0,};

void dp(int cur) {
    visited[cur] = true;
    cache[cur][0] = 0;
    cache[cur][1] = 1;
    for (int next: sns[cur]) {
        if (visited[next])
            continue;
        dp(next);
        cache[cur][0] += cache[next][1];
        cache[cur][1] += min(cache[next][0], cache[next][1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v;
        sns[u].emplace_back(v);
        sns[v].emplace_back(u);
    }
    dp(1);
    cout << min(cache[1][0], cache[1][1]);
}
