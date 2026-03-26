#include <iostream>
#include <string>
using namespace std;

void HanoiTower(int num, int from, int by, int to) {
    if(num == 1)
        cout << from << ' ' << to << '\n';
    else {
        HanoiTower(num-1, from, to, by);
        cout << from << ' ' << to << '\n';
        HanoiTower(num-1, by, from, to);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int K = 1;
    for(int i=0; i<N; i++) {
        K *= 2;
    }

    cout << K-1 << '\n';

    if(N <= 20)
        HanoiTower(N, 1, 2, 3);

    return 0;
}
