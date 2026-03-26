#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int N = id_list.size();
    vector<int> answer(N);
    bool visited[1000][1000] = {0,};
    int count[1000] = {0,};
    map<string, int> m;
    
    for (int i=0; i<N; ++i) {
        m.insert(make_pair(id_list[i], i));
    }
    for (int i=0; i<report.size(); ++i) {
        string a, b;
        for (int j=0; j<report[i].length(); ++j) {
            if (report[i][j] == ' ') {
                a = report[i].substr(0, j);
                b = report[i].substr(j + 1);
            }
        }
        int idA = m[a];
        int idB = m[b];
        if (!visited[idA][idB]) {
            visited[idA][idB] = true;
            ++count[idB];
        }
    }
    
    for (int i=0; i<N; ++i) {
        if (count[i] >= k) {
            for (int j=0; j<N; ++j) {
                if (visited[j][i]) {
                    ++answer[j];
                }
            }
        }
    }
    return answer;
}