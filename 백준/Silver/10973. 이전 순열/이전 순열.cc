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
    for (int i=0; i<N; ++i) {
        cin >> nums[i];
    }

    int pivot = N - 2;
    while (pivot >= 0 && nums[pivot] < nums[pivot + 1]) --pivot;

    if (pivot == -1) {
        cout << -1;
        return 0;
    }

    int target = N - 1;
    while (nums[target] > nums[pivot]) --target;

    swap(nums[pivot], nums[target]);
    reverse(nums.begin() + pivot + 1, nums.end());

    for (int num: nums) {
        cout << num << ' ';
    }
}