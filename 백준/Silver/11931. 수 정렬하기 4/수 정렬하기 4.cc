#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> nums(N);
    for (int &num: nums) {
        cin >> num;
    }

    sort(nums.begin(), nums.end(), greater<>());
    for (int num: nums) {
        cout << num << '\n';
    }
}