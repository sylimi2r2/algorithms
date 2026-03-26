#include <iostream>
using namespace std;

int n, num;
int wants[100001];
bool visited[100001];
bool check[100001];

void dfs(int who) {
    visited[who] = true;
    int who_wants = wants[who];

    if(!visited[who_wants])
        dfs(who_wants);
    else {
        while(!check[who_wants]) {
            check[who_wants] = true;
            num++;
            who_wants = wants[who_wants];
        }
    }
    check[who] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        num = 0;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> wants[i];
            visited[i] = false;
            check[i] = false;
        }

        for(int i=1; i<=n; i++) {
            if(!visited[i])
                dfs(i);
        }

        cout << n-num << '\n';
    }
}
