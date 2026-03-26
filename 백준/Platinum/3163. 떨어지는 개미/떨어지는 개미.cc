#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T;
int N, L, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    while(T--) {
        deque<int> ID;
        vector<pair<int, int>> distance;
        vector<pair<int, int>> falls;
        int p, a;
        cin >> N >> L >> k;

        for(int i=0; i<N; i++) {
            cin >> p >> a;
            ID.push_back(a);
            if(a > 0)
                distance.emplace_back(L-p, 1);
            else
                distance.emplace_back(p, -1);
        }
        sort(distance.begin(), distance.end());

        for(int i=0; i<N; i++) {
            if(distance[i].second==1) {
                falls.emplace_back(distance[i].first, ID.back());
                ID.pop_back();
            }
            else {
                falls.emplace_back(distance[i].first, ID.front());
                ID.pop_front();
            }
        }
        sort(falls.begin(), falls.end());

        cout << falls[k-1].second << '\n';
    }
}
