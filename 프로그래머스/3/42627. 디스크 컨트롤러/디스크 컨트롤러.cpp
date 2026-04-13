#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int total_turnaround = 0;
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> ready;
    int time = 0;
    int idx = 0;
    int total = 0;
    int n = jobs.size();
    
    while (idx < n || !ready.empty()) {
        while (idx < n && jobs[idx][0] <= time) {
            ready.push({jobs[idx][1], jobs[idx][0]});
            ++idx;
        }
        
        if (ready.empty()) {
            time = jobs[idx][0];
            continue;
        }
        
        auto [duration, request] = ready.top();
        ready.pop();
        
        time += duration;
        total += time - request;
    }
    
    return total / n;
}