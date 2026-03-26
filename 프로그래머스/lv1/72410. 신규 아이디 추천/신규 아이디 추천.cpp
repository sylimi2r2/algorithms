#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    for (int i=0; i<new_id.length(); ++i) {
        char cur = new_id[i];
        // 1 단계
        if (cur >= 'A' && cur <= 'Z') {
            new_id[i] = cur + 32;
            continue;
        }
        // 2 단계
        if ((cur >= 'a' && cur <= 'z') || (cur >= '0' && cur <= '9') || 
           cur == '-' || cur == '_' || cur == '.') {}
        else {
            new_id.erase(new_id.begin() + i--);
            continue;
        }
        // 3 단계
        if (i != 0 && cur == '.' && new_id[i - 1] == '.') {
            new_id.erase(new_id.begin() + i--);
        }
    }
    // 4 단계
    if (*new_id.begin() == '.') {
        new_id.erase(new_id.begin());
    }
    if (*(new_id.end() - 1) == '.') {
        new_id.erase(new_id.end() - 1);
    }
    // 5 단계
    if (new_id.length() == 0) {
        new_id = "a";
    }
    // 6 단계
    if (new_id.length() >= 16) {
        new_id = new_id.substr(0, 15);
        if (*(new_id.end() - 1) == '.')
            new_id.erase(new_id.end() - 1);
    }
    // 7 단계
    while (new_id.length() <= 2) {
        new_id += *(new_id.end() - 1);
    }
    return new_id;
}