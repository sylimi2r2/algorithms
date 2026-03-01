#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int ans = 0;
    int tmp = N;
    int offset = 0;
    while (tmp > 0) {
        ans += N - offset;
        tmp /= 10;
        offset = offset * 10 + 9;
    }

    cout << ans;
}