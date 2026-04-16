#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int t;
vector<bool> visited;
vector<vector<string>> tkt;

bool dfs(string cur, int used, vector<string>& answer) {
    answer.push_back(cur);
    
    if (used == t)
        return true;
    
    for (int i=0; i<t; ++i) {
        if (visited[i] || tkt[i][0] != cur) continue;
        
        visited[i] = true;
        if(dfs(tkt[i][1], used + 1, answer))
            return true;
        visited[i] = false;
    }
    answer.pop_back();
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    t = tickets.size();
    visited.assign(t, false);
    tkt = tickets;
    
    sort(tkt.begin(), tkt.end());
    
    dfs("ICN", 0, answer);
    
    return answer;
}