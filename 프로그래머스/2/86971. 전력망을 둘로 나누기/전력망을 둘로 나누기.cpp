#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    vector<vector<int>> graph(n + 1);
    
    for (auto &wire: wires) {
        int v1 = wire[0];
        int v2 = wire[1];
        
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    for (auto &wire: wires) {
        int cut1 = wire[0];
        int cut2 = wire[1];
        
        int cnt = 0;
        vector<bool> visited(n + 1, false);
        queue<int> q;
        visited[1] = true;
        q.push(1);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ++cnt;
            
            for (int next: graph[cur]) {
                if ((cur == cut1 && next == cut2) || (cur == cut2 && next == cut1)) continue;
                if (visited[next]) continue;
                
                visited[next] = true;
                q.push(next);
            }
        }
        
        answer = min(answer, abs(n - 2 * cnt));
    }
    
    return answer;
}