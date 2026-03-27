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

    vector<int> tails;
    vector<int> indexes;
    vector<int> parent(N, -1);
    for (int i=0; i<N; ++i) {
        int x = A[i];

        int pos = lower_bound(tails.begin(), tails.end(), x) - tails.begin();

        if (pos > 0) {
            parent[i] = indexes[pos - 1];
        }

        if (pos == tails.size()) {
            tails.push_back(x);
            indexes.push_back(i);
        }
        else {
            tails[pos] = x;
            indexes[pos] = i;
        }
    }

    int length = tails.size();
    vector<int> LIS(length);
    int cur = indexes[length - 1];
    for (int i=length-1; i>=0; --i) {
        LIS[i] = A[cur];
        cur = parent[cur];
    }

    cout << length << '\n';
    for (int x: LIS) {
        cout << x << ' ';
    }
}