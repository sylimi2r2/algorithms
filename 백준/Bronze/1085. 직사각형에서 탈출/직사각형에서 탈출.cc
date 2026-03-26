#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int dx = min(x, (w-x));
    int dy = min(y, (h-y));

    cout << min(dx, dy);
}
