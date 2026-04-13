#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> ready;
    for (int i=0; i<priorities.size(); ++i) {
        ready.push({priorities[i], i});
    }
    
    sort(priorities.begin(), priorities.end(), [](int a, int b) {
        return a > b;
    });
    
    int idx = 0;
    int cnt = 1;
    while (!ready.empty()) {
        if (ready.front().first == priorities[idx]) {
            if (ready.front().second == location) {
                return cnt;
            }
            
            ready.pop();
            ++idx;
            ++cnt;
        }
        else {
            ready.push(ready.front());
            ready.pop();
        }
    }
}