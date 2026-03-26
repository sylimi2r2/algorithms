#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    map<string, int> pronounce;
    pronounce.insert({"aya", 1});
    pronounce.insert({"ye", 2});
    pronounce.insert({"woo", 3});
    pronounce.insert({"ma", 4});
    for (string b: babbling) {
        bool flag = true;
        int previous = -1;
        int idx = 0;
        while (idx < b.size()) {
            if (pronounce[b.substr(idx, 2)] != 0) {
                int cur = pronounce[b.substr(idx, 2)];
                if (cur == previous) {
                    flag = false;
                    break;
                }
                previous = cur;
                idx += 2;
                continue;
            }
            if (pronounce[b.substr(idx, 3)] != 0) {
                int cur = pronounce[b.substr(idx, 3)];
                if (cur == previous) {
                    flag = false;
                    break;
                }
                previous = cur;
                idx += 3;
                continue;
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag)
            ++answer;
    }
    return answer;
}