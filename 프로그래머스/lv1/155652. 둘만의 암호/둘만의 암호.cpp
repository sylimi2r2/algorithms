#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string mask = "abcdefghijklmnopqrstuvwxyz";
    for (char sk: skip) {
        mask.erase(find(mask.begin(), mask.end(), sk));
    }
    int len = mask.length();
    vector<int> idx(26);
    for (int i=0; i<len; ++i) {
        idx[mask[i] - 'a'] = i;
    }
    for (char c: s) {
        int tmp = (idx[c - 'a'] + index) % len;
        answer += mask[tmp];
    }
    return answer;
}