#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    if(s[0]>= 'a' && s[0]<='z') 
        answer += s[0] - 32;
    else
        answer += s[0];
    for(int i=1; i<s.length(); i++) {
        char c = s[i];
        if(s[i-1]==' ') {
            if(c>= 'a' && c<='z')
                c -= 32;
        }
        else if(c>='A' && c<='Z')
            c += 32;
        answer += c;
    }
    return answer;
}