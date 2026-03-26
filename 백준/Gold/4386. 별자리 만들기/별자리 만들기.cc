#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

double sol = 0;
int n;
pair<double, double> star[100];
bool visited[100] = {0,};

void prim() {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    pq.emplace(0.0, 0);

    while(!pq.empty()) {
        int curStar = pq.top().second;
        double curDist = pq.top().first;
        pq.pop();

        if(visited[curStar])
            continue;
        visited[curStar] = true;
        sol += curDist;

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                double nextDist = sqrt(pow(star[curStar].first-star[i].first, 2) + pow(star[curStar].second-star[i].second, 2));
                pq.emplace(nextDist, i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> star[i].first >> star[i].second;
    }

    prim();

    cout << fixed;
    cout.precision(2);
    cout << sol;
}
