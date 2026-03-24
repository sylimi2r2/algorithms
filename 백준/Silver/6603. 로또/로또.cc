#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int k;
    while (true) {
        cin >> k;
        if (k == 0)
            break;

        vector<int> S(k);
        for (int i=0; i<k; ++i) {
            cin >> S[i];
        }

        vector<int> unPicked(k, 1);
        for (int i=0; i<6; ++i) {
            unPicked[i] = 0;
        }

        do {
            for (int i=0; i<k; ++i) {
                if (!unPicked[i]) {
                    cout << S[i] << ' ';
                }
            }
            cout << '\n';
        } while (next_permutation(unPicked.begin(), unPicked.end()));

        cout << '\n';
    }
}