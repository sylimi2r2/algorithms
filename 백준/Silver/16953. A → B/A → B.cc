#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B;
    int sol = 2000000000;
    cin >> A >> B;

    bool flag = false;
    queue<pair<long long, int>> q;
    q.push({A, 0});
    while(!q.empty()) {
        long long current = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(current > B)
            continue;
        if(current == B) {
            flag = true;
            sol = min(sol, cnt);
        }
        q.push({current*2, cnt+1});
        q.push({current*10+1, cnt+1});
    }
    if(flag)
        cout << sol+1;
    else
        cout << -1;
}
