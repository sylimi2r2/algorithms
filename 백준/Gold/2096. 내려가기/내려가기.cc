#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nums[3], Max[3]={0,}, Min[3]={0,};
    int N;
    cin >> N;

    cin >> Max[0] >> Max[1] >> Max[2];
    Min[0] = Max[0];
    Min[1] = Max[1];
    Min[2] = Max[2];

    for(int i=1; i<N; i++) {
        cin >> nums[0] >> nums[1] >> nums[2];
        int leftMax = max(Max[0], Max[1]);
        int rightMax = max(Max[1], Max[2]);
        int leftMin = min(Min[0], Min[1]);
        int rightMin = min(Min[1], Min[2]);
        Max[0] = nums[0] + leftMax;
        Max[1] = nums[1] + max(leftMax, rightMax);
        Max[2] = nums[2] + rightMax;
        Min[0] = nums[0] + leftMin;
        Min[1] = nums[1] + min(leftMin, rightMin);
        Min[2] = nums[2] + rightMin;
    }

    cout << max(Max[0], max(Max[1], Max[2])) << ' ' << min(Min[0], min(Min[1], Min[2]));

}
