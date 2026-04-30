#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    priority_queue<vector<int>, vector<vector<int>>, greater<>> left;
    for (int i=0; i<plans.size(); ++i) {
        int start = stoi(plans[i][1].substr(0, 2)) * 60 + stoi(plans[i][1].substr(3));
        int playtime = stoi(plans[i][2]);
        left.push({start, playtime, i});
    }
    
    stack<pair<int, int>> waiting;
    int t = 0;
    
    while (!left.empty()) {
        while (!waiting.empty()) {
            auto [playtime, idx] = waiting.top();
            
            if (t + playtime <= left.top()[0]) {
                t += playtime;
                answer.push_back(plans[idx][0]);
                waiting.pop();
            } else {
                int nextStart = left.top()[0];
                waiting.top().first -= nextStart - t;
                t = nextStart;
                break;
            }
        }
        
        vector<int> cur = left.top();
        left.pop();

        t = max(t, cur[0]);
        int playtime = cur[1];
        int idx = cur[2];

        if (!left.empty() && t + playtime > left.top()[0]) {
            int nextStart = left.top()[0];
            waiting.push({playtime - (nextStart - t), idx});
            t = nextStart;
            continue;
        }

        t += playtime;
        answer.push_back(plans[idx][0]);
    }
    
    while (!waiting.empty()) {
        answer.push_back(plans[waiting.top().second][0]);
        waiting.pop();
    }
    
    return answer;
}