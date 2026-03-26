#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nums[3];

    for(int i=0; i<3; i++)
        cin >> nums[i];

    sort(nums, nums+3);

    cout << nums[1];
}
