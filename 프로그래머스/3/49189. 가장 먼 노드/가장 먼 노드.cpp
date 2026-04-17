#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> neighbors(n + 1);
    for (vector<int>& e: edge) {
        neighbors[e[0]].push_back(e[1]);
        neighbors[e[1]].push_back(e[0]);
    }
    
    int far = 0;
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        int curD = dist[cur];
        if (curD > far) {
            far = curD;
            answer = 1;
        } else if (curD == far) {
            ++answer;
        }
        
        for (int next: neighbors[cur]) {
            if (dist[next] == -1) {
                q.push(next);
                dist[next] = dist[cur] + 1;
            }
        }
    }
    
    return answer;
}