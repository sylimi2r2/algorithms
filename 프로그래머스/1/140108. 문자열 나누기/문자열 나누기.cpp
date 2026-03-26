#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    if (len == 1) {
        return answer = 1;
    }
    char target = s[0];
    int a = 1, b = 0;
    for (int i=1; i<len; ++i) {
        if (a == 0) {
            target = s[i];
            a = 1;
        }
        else {
            if (target == s[i]) {
                ++a;
            }
            else {
                ++b;
            }
            if (a == b) {
                ++answer;
                a = 0;
                b = 0;
            }    
        }
    }
    if (a != 0) {
        ++answer;
    }
    return answer;
}