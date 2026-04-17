#include <string>
#include <vector>

using namespace std;

int dfs(int cur, vector<vector<int>>& graph, vector<bool>& visited) {
    int cnt = 0;
    
    for (int next: graph[cur]) {
        if (visited[next]) continue;
        
        visited[next] = true;
        cnt += 1 + dfs(next, graph, visited);
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> win(n + 1), lose(n + 1);
    
    for (vector<int>& r: results) {
        win[r[0]].push_back(r[1]);
        lose[r[1]].push_back(r[0]);
    }
    
        
    for (int i=1; i<=n; ++i) {
        vector<bool> visited(n + 1, false);
        int stronger = dfs(i, lose, visited);
        
        visited.assign(n + 1, false);
        int weaker = dfs(i, win, visited);
        
        if (stronger + weaker == n - 1) {
            ++answer;
        }
    }
    
    return answer;
}
