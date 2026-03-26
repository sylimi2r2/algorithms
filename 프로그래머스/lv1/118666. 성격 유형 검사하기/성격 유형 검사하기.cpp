#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "RCJA";
    vector<int> scores(4);
    for (int i=0; i<survey.size(); ++i) {
        if (choices[i] == 4)
            continue;
        
        switch (survey[i][0]) {
            case 'R':
                scores[0] += choices[i] - 4;
                break;
            case 'T':
                scores[0] -= choices[i] - 4;
                break;
            case 'C':
                scores[1] += choices[i] - 4;
                break;
            case 'F':
                scores[1] -= choices[i] - 4;
                break;
            case 'J':
                scores[2] += choices[i] - 4;
                break;
            case 'M':
                scores[2] -= choices[i] - 4;
                break;
            case 'A':
                scores[3] += choices[i] - 4;
                break;
            case 'N':
                scores[3] -= choices[i] - 4;
                break;
        }
    }
    if (scores[0] > 0)
        answer[0] = 'T';
    if (scores[1] > 0)
        answer[1] = 'F';
    if (scores[2] > 0)
        answer[2] = 'M';
    if (scores[3] > 0)
        answer[3] = 'N';
    return answer;
}