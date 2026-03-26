#include <iostream>
using namespace std;

int sol = 0;
int G, P, gi;
int gate[100001];

int find(int x) {
    if(x == gate[x]) return x;
    return gate[x] = find(gate[x]);
}

void union_root(int greed) {
    int greedY = find(greed-1);
    gate[greed] =  greedY;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> G >> P;

    for(int i=1; i<=G; i++)
        gate[i] = i;

    for(int i=0; i<P; i++) {
        cin >> gi;

        int greedy = find(gi);
        if(greedy == 0)
            break;
        union_root(greedy);
        sol++;
    }

    cout << sol;
}
