#include <iostream>
#include <cmath>
using namespace std;

int x, y;

int sol() {
    int distance = y-x;
    int bound = int(sqrt(distance));

    if(distance == bound*bound)
        return bound*2-1;

    if((distance-bound*bound) < ((bound+1)*(bound+1)-distance))
        return bound*2;
    else
        return bound*2+1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        cin >> x >> y;
        cout << sol() << '\n';
    }
}
