#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for (string p: participant) {
        if (m.find(p) != m.end()) {
            m[p]++;
        }
        else {
            m.insert({p, 1});
        }
    }
    for (string c: completion) {
        if (--m[c] == 0) {
            m.erase(c);
        }
    }
    answer = m.begin()->first;
    return answer;
}