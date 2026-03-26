#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int input;
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> input;

        if(dp.empty() || dp.back() < input) {
            dp.push_back(input);
        }
        else {
            *lower_bound(dp.begin(), dp.end(), input) = input;
        }
    }

    cout << dp.size() << '\n';

}
