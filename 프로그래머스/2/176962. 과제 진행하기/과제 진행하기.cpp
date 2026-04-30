#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct HW {
    string name;
    int start;
    int playtime;
};

int toMinute(string time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<HW> h;
    
    for (auto& p: plans) {
        h.push_back({
            p[0],
            toMinute(p[1]),
            stoi(p[2])
        });
    }
    
    sort(h.begin(), h.end(), [](const HW& a, const HW& b) {
        return a.start < b.start;
    });
    
    stack<pair<string, int>> delayed;
    
    for (int i=0; i<h.size() - 1; ++i) {
        string name = h[i].name;
        int curTime = h[i].start;
        int playtime = h[i].playtime;
        int nextTime = h[i + 1].start;
        
        int term = nextTime - curTime;
        
        if (playtime <= term) {
            answer.push_back(name);
            
            int rest = term - playtime;
            
            while (rest > 0 && !delayed.empty()) {
                auto [dName, dTime] = delayed.top();
                delayed.pop();
                
                if (dTime <= rest) {
                    answer.push_back(dName);
                    rest -= dTime;
                } else {
                    delayed.push({dName, dTime - rest});
                    rest = 0;
                }
            }
        } else {
            delayed.push({name, playtime - term});
        }
    }
    
    answer.push_back(h.back().name);
    
    while (!delayed.empty()) {
        answer.push_back(delayed.top().first);
        delayed.pop();
    }
    
    return answer;
}