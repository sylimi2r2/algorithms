#include <string>
#include <vector>

using namespace std;

int answer;
int n;
vector<vector<int>> COST;
vector<vector<int>> HINT;
vector<int> have;

void dfs(int stage, int sum) {
    if (sum >= answer) {
        return;
    }
    
    if (stage == n) {
        answer = min(answer, sum);
        return;
    }
    
    int use = min(have[stage], n - 1);
    sum += COST[stage][use];
    dfs(stage + 1, sum);
    
    if (stage != n - 1) {
        sum += HINT[stage][0];
        for (int i=1; i<HINT[stage].size(); ++i) {
            ++have[HINT[stage][i] - 1];
        }
        
        dfs(stage + 1, sum);

        for (int i=1; i<HINT[stage].size(); ++i) {
            --have[HINT[stage][i] - 1];
        }   
    }
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    answer = 987654321;
    n = cost.size();
    COST = cost;
    HINT = hint;
    have.assign(n, 0);
    
    dfs(0, 0);
    
    return answer;
}