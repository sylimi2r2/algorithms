#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[100001];
int parent[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    queue<int> q;
    visited[N] = true;
    parent[N] = -1;
    q.push(N);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == K) {
            break;
        }

        int next[3] = {cur - 1, cur + 1, cur * 2};
        for (int n: next) {
            if (n < 0 || n > 100000 || visited[n]) continue;

            visited[n] = true;
            parent[n] = cur;
            q.push(n);
        }
    }

    vector<int> ans;
    for (int x=K; x!=-1; x=parent[x]) {
        ans.push_back(x);
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() - 1 << '\n';
    for (int a: ans) {
        cout << a << ' ';
    }
}