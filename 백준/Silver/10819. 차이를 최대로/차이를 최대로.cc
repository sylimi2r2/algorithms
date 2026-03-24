#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int ans = 0;
    do {
        int tmp = 0;
        for (int i = 0; i < N - 1; ++i) {
            tmp += abs(A[i] - A[i + 1]);
        }
        ans = max(ans, tmp);
    } while (next_permutation(A.begin(), A.end()));

    cout << ans;
}