#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double d = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
        int rM = abs(r1-r2);
        int rP = r1+r2;

        int sol;

        if(d==0 && rM==0)
            sol = -1;
        else if(d==rM || d==rP)
            sol = 1;
        else if(rM<d && d<rP)
            sol = 2;
        else
            sol = 0;

        cout << sol << '\n';
    }
}
