#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    vector<int> v;
    cin >> N;
    for (int i=1; i<=N; ++i) {
        v.push_back(i);
    }

    do {
        for (int x: v) {
            cout << x << ' ';
        }
        cout << '\n';
   } while (next_permutation(v.begin(), v.end()));
}