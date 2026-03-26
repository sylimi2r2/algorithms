#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, P, S;
    cin >> N >> P >> S;
    for (int i=0; i<S; ++i) {
        int m;
        bool flag = false;
        cin >> m;
        for (int j=0; j<m; ++j) {
            int card;
            cin >> card;
            if (card == P)
                flag = true;
        }
        cout << (flag ? "KEEP" : "REMOVE") << '\n';
    }
}