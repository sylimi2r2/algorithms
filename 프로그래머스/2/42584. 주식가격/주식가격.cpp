#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int N = prices.size();
    vector<int> answer(N);
    stack<pair<int, int>> s;
    
    for (int i=0; i<prices.size(); ++i) {
        int price = prices[i];
        while (!s.empty()) {
            if (price < s.top().first) {
                answer[s.top().second] = i - s.top().second;
                s.pop();
            } else break;
        }
        s.push({prices[i], i});
    }
    
    while (!s.empty()) {
        answer[s.top().second] = N - s.top().second - 1;
        s.pop();
    }
    
    return answer;
}