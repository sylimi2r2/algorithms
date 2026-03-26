#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int words = 0;
    for (char c: s) {
        if (c == ' ') {
            answer += c;
            words = 0;
        }
        else {
            if (words % 2) {
                answer += tolower(c);
            }
            else {
                answer += toupper(c);
            }
            ++words;
        }
    }
    return answer;
}