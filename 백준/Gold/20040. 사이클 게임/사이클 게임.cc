#include <iostream>
using namespace std;

int n, m;
int a, b;
int parent[500000];

int find(int x) {
    if(x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}

bool check(int x, int y) {
    int xParent = find(x);
    int yParent = find(y);

    if(xParent == yParent)
        return true;

    parent[xParent] = yParent;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        parent[i] = i;

    for(int i=1; i<=m; i++) {
        cin >> a >> b;

        if(check(a, b)) {
            cout << i;
            return 0;
        }
    }


    cout << 0;
    return 0;
}
