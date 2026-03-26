#include <iostream>
#include <string>
#include <cmath>
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

    string K = to_string(pow(2,N));
    K = K.substr(0, K.find('.'));
    K[K.length()-1] -= 1;
    cout << K << '\n';

    if(N <= 20)
        HanoiTower(N, 1, 2, 3);

    return 0;
}
