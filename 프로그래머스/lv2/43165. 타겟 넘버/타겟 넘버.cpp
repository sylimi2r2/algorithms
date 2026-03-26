#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> n;
int t;

int dfs(int cur, int idx) {
    if (idx == n.size()) {
        if (cur == t)
            return 1;
        return 0;
    }
    
    return dfs(cur + n[idx], idx + 1) + dfs(cur - n[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    n = numbers;
    t = target;
    return dfs(0, 0);
}