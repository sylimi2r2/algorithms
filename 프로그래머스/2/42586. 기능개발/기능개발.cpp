#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int i = 0;
    
    while (i < progresses.size()) {    
        int left = 100 - progresses[i];
        int time = left / speeds[i] + (left % speeds[i] ? 1 : 0);
        
        int cnt = 1;
        for (++i; i<progresses.size(); ++i) {
            if (progresses[i] + time * speeds[i] >= 100)
                ++cnt;
            else
                break;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}