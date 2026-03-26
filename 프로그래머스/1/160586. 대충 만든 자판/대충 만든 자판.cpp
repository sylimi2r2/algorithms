#include <string>
#include <vector>

using namespace std;

const int INF = 9999999;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> alphabets(26, INF);
    for (string key: keymap) {
        for (int i=0; i<key.length(); ++i) {
            alphabets[key[i] - 'A'] = min(alphabets[key[i] - 'A'], i+1);
        }
    }
    for (string target: targets) {
        int tmp = 0;
        for (char t: target) {
            tmp += alphabets[t - 'A'];
        }
        if (tmp >= INF) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(tmp);
        }
    }
    return answer;
}