#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<pair<double, int>> time;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=1; i<=N; i++) {
        double x, y, v;
        cin >> x >> y >> v;
        time.emplace_back((sqrt(x * x + y * y) / v), i);
    }
    sort(time.begin(), time.end());

    for (int i = 0; i < N; i++) {
        cout << time[i].second << '\n';
    }
}
