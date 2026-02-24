#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    constexpr int LCM = 7980;

    int E, S, M;
    cin >> E >> S >> M;

    for (int year=1; year<=LCM; ++year) {
        if (((year - 1) % 15 + 1 == E) && ((year - 1) % 28 + 1 == S) && ((year - 1) % 19 + 1 == M)) {
            cout << year;
            break;
        }
    }
}