#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> direction[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool visited[500][500][4] = {0,};
int n, m;
vector<string> map;

int dfs(int i, int j, int d, int cost) {
    if (visited[i][j][d]) {
        return cost;
    }
    
    visited[i][j][d] = true;
    switch (map[i][j]) {
        case 'S': {
            break;
        }
        case 'L': {
            d = (--d + 4) % 4;
            break;
        }
        case 'R': {
            d = (++d) % 4;
            break;
        }
    }
    int nextI = (i + direction[d].first + n) % n;
    int nextJ = (j + direction[d].second + m) % m;
    
    return dfs(nextI, nextJ, d, ++cost);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    n = grid.size();
    m = grid[0].size();
    for (string g: grid) {
        map.push_back(g);
    }
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            for (int d=0; d<4; ++d) {
                int cost = dfs(i, j, d, 0);
                if (cost) {
                    answer.push_back(cost);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}