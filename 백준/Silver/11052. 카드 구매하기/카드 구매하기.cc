#include <iostream>

using namespace std;

int P[1001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i=1; i<=N; ++i) {
        cin >> P[i];
        for (int j=1; j<=i/2; ++j) {
            P[i] = max(P[i], P[j] + P[i - j]);
        }
    }

    cout << P[N];
}