#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int h, o;
int d;
vector<pair<int, int>> location;
priority_queue<int, vector<int>, greater<>> q;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second)
        return a.second < b.second;

    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h >> o;
        if (h < o) {
            location.emplace_back(h, o);
        }
        else {
            location.emplace_back(o, h);
        }
    }
    cin >> d;
    sort(location.begin(), location.end(), compare);

    int sol = 0;

    for (pair<int, int> cur: location) {
        if (cur.second - cur.first <= d) {
            q.push(cur.first);
        }
        else {
            continue;
        }

        while (!q.empty()) {
            int left = q.top();
            if (cur.second > left + d) {
                q.pop();
            }
            else {
                break;
            }
        }

        sol = max(sol, (int)q.size());
    }

    cout << sol;
}
