#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, sol=1;
    int dp[1000] = {0,};
    vector<int> nums;
    cin >> N;
    for(int i=0; i<N; i++) {
        int input;
        cin >> input;
        nums.push_back(input);
        dp[i] = 1;
    }

    for(int i=1; i<N; i++) {
        for(int j=i-1; j>=0; j--) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        if(dp[i] > sol)
            sol = dp[i];
    }

    cout << sol;
}
