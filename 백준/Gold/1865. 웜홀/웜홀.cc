#include <iostream>
#include <vector>
using namespace std;

#define INF 5000000

struct EDGE {
    int S;
    int E;
    int T;
};

int N, M, W;

bool BF(vector<EDGE> edges) {
    vector<int> dist(N+1, INF);
    dist[1] = 0;
    for(int i=0; i<N-1; i++) {
        for(EDGE e : edges) {
            int S = e.S;
            int E = e.E;
            int T = e.T;
            dist[E] = min(dist[E], dist[S]+T);
        }
    }

    for(EDGE e : edges) {
        int S = e.S;
        int E = e.E;
        int T = e.T;
        if(dist[E] > dist[S]+T)
            return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC;
    cin >> TC;
    while(TC--) {
        vector<EDGE> edges;
        cin >> N >> M >> W;

        for(int i=0; i<M; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }

        for(int i=0; i<W; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S, E, -T});
        }

        if(BF(edges))
            cout << "YES\n";
        else
            cout << "NO\n";

    }

}
