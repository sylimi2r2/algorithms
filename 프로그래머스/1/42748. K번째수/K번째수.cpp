#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> c: commands) {
        vector<int> tmp(array.begin()+c[0]-1, array.begin()+c[1]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[c[2]-1]);
    }
    return answer;
}