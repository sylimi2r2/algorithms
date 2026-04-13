#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int N = prices.size();
    vector<int> answer(N);
    stack<int> s;
    
    for (int i=0; i<prices.size(); ++i) {
        int price = prices[i];
        while (!s.empty()) {
            if (price < prices[s.top()]) {
                answer[s.top()] = i - s.top();
                s.pop();
            } else break;
        }
        s.push(i);
    }
    
    while (!s.empty()) {
        answer[s.top()] = N - s.top() - 1;
        s.pop();
    }
    
    return answer;
}