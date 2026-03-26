#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    int nums[2001] = {0,};
    for (int w: weights) {
        nums[w]++;
    }
    
    for (int i=100; i<1001; ++i) {
        if (nums[i] == 0)
            continue;
        
        // 1 : 1
        answer += (long long)nums[i] * (nums[i] - 1) / 2;
        
        // 1 : 3 / 2
        if (i % 2 == 0) {
            answer += (long long)nums[i] * nums[i * 3 / 2];
        }   
        
        // 1 : 2
        answer += (long long)nums[i] * nums[i * 2];
        
        // 1 : 4/3
        if (i % 3 == 0) {
            answer += (long long)nums[i] * nums[i * 4 / 3];
        }
    }
    return answer;
}