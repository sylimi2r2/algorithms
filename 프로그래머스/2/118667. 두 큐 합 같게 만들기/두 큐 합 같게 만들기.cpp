#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int N = queue1.size();
    queue<int> q1, q2;
    long long left = 0, right = 0;
    long long goal = 0;
    
    for (int i=0; i<N; ++i) {
        left += queue1[i];
        q1.push(queue1[i]);
        right += queue2[i];
        q2.push(queue2[i]);
    }
    
    goal = left + right;
    if (goal % 2 != 0) {
        return -1;
    } 
    goal /= 2;
    
    while (answer < 2 * N + 1) {
        if (left == goal) {
            return answer;
        }
        if (left > goal) {
            left -= q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else {
            left += q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        ++answer;
    }

    return -1;
}