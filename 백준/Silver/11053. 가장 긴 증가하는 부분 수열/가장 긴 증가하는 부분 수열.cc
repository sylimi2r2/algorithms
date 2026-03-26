#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> LIS;
    for (int i=0; i<N; ++i) {
        int input;
        cin >> input;

        auto it = lower_bound(LIS.begin(), LIS.end(), input);

        if (it == LIS.end()) {
            LIS.push_back(input);
        } else {
            *it = input;
        }
    }

    cout << LIS.size();
}