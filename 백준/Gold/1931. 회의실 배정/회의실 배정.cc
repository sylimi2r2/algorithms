#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    vector<pair<int, int>> schedule;
    cin >> N;
    for(int i=0; i<N; i++) {
        int start, end;
        cin >> start >> end;
        schedule.push_back({end, start});
    }
    sort(schedule.begin(), schedule.end());

    int sol = 1;
    int finish = schedule[0].first;

    for(int i=1; i<N; i++) {
        if(schedule[i].second >= finish) {
            finish = schedule[i].first;
            sol++;
        }
    }

    cout << sol;
}
