#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int input;
    vector<int> tails;
    for (int i=0; i<N; ++i) {
        cin >> input;

        auto it = lower_bound(tails.begin(), tails.end(), -input);
        if (it == tails.end()) {
            tails.push_back(-input);
        }
        else {
            *it = -input;
        }
    }

    cout << tails.size();
}