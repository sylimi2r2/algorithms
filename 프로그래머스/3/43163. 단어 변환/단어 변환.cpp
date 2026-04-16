#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    int n = words.size();
    int m = begin.size();
    int t = -1;
    for (int i=0; i<n; ++i) {
        if (target == words[i]) {
            t = i;
            break;
        }
    }
    if (t == -1)
        return 0;
    
    
    queue<int> q;
    vector<int> dist(n, -1);
    q.push(n - 1);
    dist[n - 1] = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur == t) {
            return dist[cur];
        }
        
        string curW = words[cur];
        
        for (int next=0; next<n-1; ++next) {
            if (next == cur) continue;
            if (dist[next] >= 0) continue;
            
            string nextW = words[next];
            int cnt = 0;
            for (int i=0; i<m; ++i) {
                if (curW[i] != nextW[i]) ++cnt;
            }
            
            if (cnt == 1) {
                q.push(next);
                dist[next] = dist[cur] + 1;
            }
        }
    }
    
    return 0;
}