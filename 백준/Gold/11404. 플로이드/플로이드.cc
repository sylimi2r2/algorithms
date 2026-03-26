#include <iostream>
using namespace std;

#define INF 10000000

int n, m;
int dist[101][101];

void floyd() {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dist[i][k]+dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << (dist[i][j]==INF ? 0 : dist[i][j]) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            if(i==j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(dist[a][b] > c)
            dist[a][b] = c;
    }

    floyd();
}
