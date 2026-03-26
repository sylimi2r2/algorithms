#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int stickers[2][100001] = {0, };
    int T, n;
    cin >> T;

    while(T--) {
        cin >> n;

        for(int i=0; i<2; i++) {
            for(int j=1; j<=n; j++) {
                cin >> stickers[i][j];
            }
        }
        
        for(int i=2; i<=n; i++) {
            stickers[0][i] = max(stickers[1][i-1], stickers[1][i-2]) + stickers[0][i];
            stickers[1][i] = max(stickers[0][i-1], stickers[0][i-2]) + stickers[1][i];
        }

        cout << max(stickers[0][n], stickers[1][n]) << '\n';
    }
}
