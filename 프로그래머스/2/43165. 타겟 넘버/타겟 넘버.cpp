#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int n = numbers.size();
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while (!q.empty()) {
        auto [sum, idx] = q.front();
        q.pop();
        
        if (idx == n) {
            if (sum == target) {
                ++answer;
            }
            continue;
        }
        
        q.push({sum + numbers[idx], idx + 1});
        q.push({sum - numbers[idx], idx + 1});
    }
    
    return answer;
}