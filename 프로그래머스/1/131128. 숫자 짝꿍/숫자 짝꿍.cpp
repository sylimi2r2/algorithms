#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> numX(10), numY(10);
    for (char x: X) {
        ++numX[x - '0'];
    }
    for (char y: Y) {
        ++numY[y - '0'];
    }
    for (int i=9; i>=0; --i) {
        if (numX[i] > 0 && numY[i] > 0) {
            for (int j=0; j<min(numX[i], numY[i]); ++j) {
                answer += '0' + i;    
            }
        }
    }
    if (answer[0] == '0')
        answer = "0";
    if (answer.length() == 0)
        answer = "-1";
    return answer;
}