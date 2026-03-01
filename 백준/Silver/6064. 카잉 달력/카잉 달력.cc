#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        int LCM = (M * N) / gcd(M, N);
        bool flag = false;
        for (int year=x; year<=LCM; year+=M) {
            if (y == (year-1) % N + 1) {
                flag = true;
                cout << year << '\n';
                break;
            }
        }
        if (!flag)
            cout << -1 << '\n';
    }
}