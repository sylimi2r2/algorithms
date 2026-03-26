#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, H, W, N;
    cin >> T;

    for(int i=0; i<T; i++) {
        cin >> H >> W >> N;

        int x = N/H + 1;
        int y = N%H;
        if(!y) {
            y = H;
            x--;
        }

        cout << y*100 + x << "\n";
    }
}
