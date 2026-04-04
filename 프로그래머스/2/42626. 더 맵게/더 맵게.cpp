#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq(scoville.begin(), scoville.end());
   
    while (!pq.empty()) {
        int first = pq.top();
        pq.pop();
        
        if (first < K) {
            if (pq.empty()) {
                return -1;
            }
            
            int second = pq.top();
            pq.pop();
            pq.push(first + second * 2);
            ++answer;
        } else {
            break;
        }
    }
    
    return answer;
}