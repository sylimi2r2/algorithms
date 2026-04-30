#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq(works.begin(), works.end());
    
    while (!pq.empty() && n > 0) {
        int top = pq.top();
        pq.pop();
        
        if (--top > 0)
            pq.push(top);
        --n;
    }
    
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        
        answer += top * top;
    }
    
    return answer;
}