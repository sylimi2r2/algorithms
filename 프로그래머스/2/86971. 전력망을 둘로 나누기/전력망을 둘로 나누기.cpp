#include <string>
#include <vector>

using namespace std;

vector<vector<int>> neighbors;
vector<int> subTreeSize;

int dfs(int cur, int parent) {
    int& ret = subTreeSize[cur];
    
    ret = 1;
    
    for (int& neighbor: neighbors[cur]) {
        if (neighbor != parent) {
            ret += dfs(neighbor, cur);
        }
    }
    
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    neighbors.assign(n + 1, vector<int>());
    subTreeSize.assign(n + 1, 0);
    
    for (vector<int>& wire: wires) {
        int v1 = wire[0];
        int v2 = wire[1];
        neighbors[v1].push_back(v2);
        neighbors[v2].push_back(v1);
    }
    
    dfs(1, 0);
    
    int answer = n;
    for (int i=2; i<=n; ++i) {
        answer = min(answer, abs(n - 2 * subTreeSize[i]));
    }
    
    return answer;
}