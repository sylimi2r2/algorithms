#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    // prime init
    vector<bool> prime(3001, true);
    for (int i=2; i<=3000; ++i) {
        if (prime[i]) {
            for (int j=2*i; j<=3000; j+=i) {
                prime[j] = false;
            }        
        }
    }
    
    int s = nums.size();
    for (int i=0; i<s-2; ++i) {
        int one = nums[i];
        for (int j=i+1; j<s-1; ++j) {
            int two = one + nums[j];
            for (int k=j+1; k<s; ++k) {
                if (prime[two + nums[k]]) {
                    ++answer;
                }
            }
        }
    }

    return answer;
}