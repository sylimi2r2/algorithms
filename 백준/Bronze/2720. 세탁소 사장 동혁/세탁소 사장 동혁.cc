#include <iostream>
using namespace std;

int money[4] = {25, 10, 5, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int C;
        cin >> C;

        for(int m : money) {
            cout << (C / m) << ' ';
            C %= m;
        }
        cout << '\n';
    }
}