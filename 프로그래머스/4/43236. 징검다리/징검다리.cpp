#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0;
    int right = distance;
    
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        int prev = 0;
        int remove = 0;
        
        for (int r: rocks) {
            if (r - prev < mid) {
                ++remove;
            } else {
                prev = r;
            }
        }
        
        if (remove <= n) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
}