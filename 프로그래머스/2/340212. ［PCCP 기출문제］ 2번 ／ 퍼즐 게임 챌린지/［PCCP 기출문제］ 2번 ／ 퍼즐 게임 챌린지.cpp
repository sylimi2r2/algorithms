#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 100000;
    int d = diffs.size();
    int left = 1;
    int right = 100000;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        long long tmp = 0;
        
        for (int i=0; i<d; ++i) {
            if (diffs[i] <= mid) {
                tmp += times[i];
            } else {
                int rep = diffs[i] - mid;
                tmp += (times[i - 1] + times[i]) * rep + times[i];
            }
        }
        
        if (tmp <= limit) {
            right = mid - 1;
            answer = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}