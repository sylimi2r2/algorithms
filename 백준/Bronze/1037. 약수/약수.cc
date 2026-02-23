#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    int minN = 1'000'001, maxN = 1;
    int input;

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> input;
        minN = min(minN, input);
        maxN = max(maxN, input);
    }

    cout << minN * maxN;
}