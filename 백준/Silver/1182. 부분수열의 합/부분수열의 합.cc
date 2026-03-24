#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, S;
    cin >> N >> S;

    vector<int> v(N);
    for (int i=0; i<N; ++i) {
        cin >> v[i];
    }

    int sol = 0;
    for (int i=1; i<(1 << N); ++i) {
        int tmp = 0;
        for (int j=0; j<N; ++j) {
            if (i & (1 << j)) {
                tmp += v[j];
            }
        }
        if (tmp == S) {
            ++sol;
        }
    }

    cout << sol;
}