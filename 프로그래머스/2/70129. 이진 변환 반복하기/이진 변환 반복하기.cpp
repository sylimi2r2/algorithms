#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int zeros = 0;
    int cnt = 0;
    while (s != "1") {
        ++cnt;
        int len = 0;
        for (char c: s) {
            if (c == '1') {
                ++len;
            }
        }
        zeros += s.length() - len;
        s = "";
        while (len > 0) {
            s = to_string(len % 2) + s;
            len /= 2;
        }
    }
    return {cnt, zeros};
}