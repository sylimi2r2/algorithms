#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 1;
int N;
int K;
vector<string> needs;

bool isInfected(const string& cmd, const string& need) {
    int idx = 0;
    
    for (char c: cmd) {
        if (idx < need.size() && need[idx] == c) {
            ++idx;
        }
    }
    
    return idx == need.size();
}

void dfs(string& command) {
    if (command.size() == K + 1) {
        int cnt = 0;
        
        for (int i=1; i<=N; ++i) {
            if (isInfected(command, needs[i])) {
                ++cnt;
            }
        }
        
        answer = max(answer, cnt);
        
        return;
    }
    
    for (char c='1'; c<='3'; ++c) {
        if (c != command.back()) {
            command.push_back(c);
            dfs(command);
            command.pop_back();
        }
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    N = n;
    K = k;
    
    vector<vector<pair<int, char>>> link(n + 1);
    for (vector<int>& e: edges) {
        int x = e[0];
        int y = e[1];
        char type = (char)(e[2] + '0');
        
        link[x].push_back({y, type});
        link[y].push_back({x, type});
    }
    
    needs.assign(n + 1, "");
    queue<int> q;
    q.push(infection);
    needs[infection] = "#";
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (auto [next, type]: link[cur]) {
            if (needs[next] != "") continue;
            
            q.push(next);
            if (needs[cur].back() == type)
                needs[next] = needs[cur];
            else 
                needs[next] = needs[cur] + type;
        }
    }
    
    string command = "#";
    dfs(command);
    
    return answer;
}