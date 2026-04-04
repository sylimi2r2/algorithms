#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> subSize;

int dfs(int cur, int parent) {
    int &ret = subSize[cur];
    
    ret = 1;
    
    for (int next: graph[cur]) {
        if (next == parent) continue;
        ret += dfs(next, cur);
    }
    
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    graph.assign(n + 1, {});
    subSize.assign(n + 1, 0);
    
    for (auto& wire: wires) {
        int v1 = wire[0], v2 = wire[1];
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    dfs(1, 0);
    
    int answer = n;
    for (int node=2; node<=n; ++node) {
        answer = min(answer, abs(n - 2 * subSize[node]));
    }
    
    return answer;
}