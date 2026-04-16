#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> edges(n);
    for (vector<int> c: costs) {
        edges[c[0]].push_back({c[1], c[2]});
        edges[c[1]].push_back({c[0], c[2]});
    }
    
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    pq.push({0, 0});
    
    while (!pq.empty()) {
        auto [curC, curV] = pq.top();
        pq.pop();
        
        if (visited[curV]) continue;
        
        visited[curV] = true;
        answer += curC;
        
        for (auto [nextV, nextC]: edges[curV]) {
            if (!visited[nextV]) {
                pq.push({nextC, nextV});
            }
        }
    }
    
    
    return answer;
}