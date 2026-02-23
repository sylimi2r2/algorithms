#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;

    while (cin >> n) {
        int target = 1;
        int cnt = 1;
        while (true) {
            int remain = target % n;
            if (remain == 0) {
                cout << cnt << '\n';
                break;
            }
            else {
                target = remain * 10 + 1;
                ++cnt;
            }
        }
    }
}