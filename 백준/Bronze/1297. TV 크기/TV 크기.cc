#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int D, H, W;
    cin >> D >> H >> W;

    double l = D/sqrt(H*H+W*W);
    cout << int(H*l) << ' ' << int(W*l);
}
