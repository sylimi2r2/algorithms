#include <iostream>
using namespace std;

int cost;
int changes[6] = {500, 100, 50, 10, 5, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> cost;
    cost = 1000-cost;

    int i = 0;
    int cnt = 0;
    while(cost) {
        cnt += cost/changes[i];
        cost = cost%changes[i];
        i++;
    }

    cout << cnt;
}
