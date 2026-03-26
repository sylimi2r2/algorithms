#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> location(26, -1);
    for (int i=0; i<s.size(); ++i) {
        int cur = s[i] - 'a';
        if (location[cur] == -1) {
            answer.push_back(-1);
            location[cur] = i;
        }
        else {
            answer.push_back(i - location[cur]);
            location[cur] = i;
        }
    }
    return answer;
}