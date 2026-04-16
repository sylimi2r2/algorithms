#include <string>
#include <vector>

using namespace std;

int N;
vector<vector<int>> com;
vector<bool> visited;

void dfs(int cur) {
    for (int next=0; next<N; ++next) {
        if (com[cur][next] && !visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    N = n;
    com = computers;
    visited.assign(n, false);
    
    for (int i=0; i<n; ++i) {
        if (!visited[i]) {
            ++answer;
            dfs(i);
        }
    }
    
    return answer;
}