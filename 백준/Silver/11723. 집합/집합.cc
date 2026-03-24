#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int S = 0;
    int M;
    cin >> M;
    while (M--) {
        string command;
        cin >> command;

        if (command == "all") {
            S = (1 << 21) - 2;
            continue;
        }

        if (command == "empty") {
            S = 0;
            continue;
        }

        int x;
        cin >> x;

        if (command == "add") {
            S |= (1 << x);
            continue;
        }

        if (command == "remove") {
            S &= ~(1 << x);
            continue;
        }

        if (command == "check") {
            cout << ((S & (1 << x)) ? 1 : 0) << '\n';
            continue;
        }

        if (command == "toggle") {
            S ^= (1 << x);
        }
    }
}