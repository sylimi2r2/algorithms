#include <string>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size();
    int m = storage[0].size();
    int answer = n * m;
    vector<string> str;
    string init;
    for (int i=0; i<m+2; ++i) {
        init += ' ';
    }
    str.push_back(init);
    for (int i=0; i<n; ++i) {
        string tmp = " ";
        for (int j=0; j<m; ++j) {
            tmp += storage[i][j];
        }
        tmp += ' ';
        str.push_back(tmp);
    }
    str.push_back(init);
    
    for (auto req: requests) {
        char target = req[0];
        if (req.size() == 2) {
            for (int i=1; i<=n; ++i) {
                for (int j=1; j<=m; ++j) {
                    if (target == str[i][j]) {
                        str[i][j] = ' ';
                        --answer;
                    }
                }
            }
        }
        else {
            bool visited[52][52] = {0,};
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for (auto d: directions) {
                    int nextI = cur.first + d.first;
                    int nextJ = cur.second + d.second;
                    if (nextI>=0 && nextI<=n+1 && nextJ>=0 && nextJ<=m+1 && !visited[nextI][nextJ]) {
                        visited[nextI][nextJ] = true;
                        if (str[nextI][nextJ] == ' ') {
                            q.push({nextI, nextJ});
                        }
                        else if (str[nextI][nextJ] == target){
                            --answer;
                            str[nextI][nextJ] = ' ';
                        }
                    }
                }
            }
        }
    }
    return answer;
}