#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long P[101];
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    for(int i=4; i<101; i++) {
        P[i] = P[i-2] + P[i-3];
    }

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        cout << P[N] << '\n';
    }
}