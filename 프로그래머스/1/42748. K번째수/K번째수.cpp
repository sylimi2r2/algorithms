#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int>& cmd: commands) {
        vector<int> subArray(array.begin() + cmd[0] - 1, array.begin() + cmd[1]);
        
        sort(subArray.begin(), subArray.end());
        
        answer.push_back(subArray[cmd[2] - 1]);
    }
    
    return answer;
}