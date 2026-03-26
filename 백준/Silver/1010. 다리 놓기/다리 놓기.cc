#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // nCr = n-1Cr-1 + n-1Cr //
    int combination[30][30] = {0,};

    for(int n=1; n<30; n++) {
        combination[n][0] = 1;
        combination[n][n] = 1;
    }
    for(int n=2; n<30; n++) {
        for(int r=1; r<n; r++) {
            combination[n][r] = combination[n-1][r-1] + combination[n-1][r];
        }
    }


    int T;
    cin >> T;
    while(T--) {
        int n, r;
        cin >> r >> n;
        cout << combination[n][r] << '\n';
    }
}
