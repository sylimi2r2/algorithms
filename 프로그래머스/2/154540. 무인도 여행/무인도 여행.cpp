#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    queue<pair<int, int>> q;
    bool visited[100][100] = {0,};
    int N = maps.size();
    int M = maps[0].size();
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (!visited[i][j] && maps[i][j] != 'X') {
                int cost = maps[i][j] - '0';
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (pair<int, int> d: directions) {
                        pair<int, int> next = {cur.first + d.first, cur.second + d.second};
                        if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < M && !visited[next.first][next.second] && maps[next.first][next.second] != 'X') {
                            cost += maps[next.first][next.second] - '0';
                            visited[next.first][next.second] = true;
                            q.push(next);
                        }
                    }
                }
                answer.push_back(cost);
            }
        }
    }
    
    if (answer.size()) {
        sort(answer.begin(), answer.end());
    }
    else {
        answer.push_back(-1);
    }
    
    return answer;
}