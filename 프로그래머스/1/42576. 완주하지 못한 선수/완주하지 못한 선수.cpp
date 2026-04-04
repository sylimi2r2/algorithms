#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    
    for (string c: completion) {
        auto it = m.find(c);
        
        if (it == m.end()) {
            m.insert({c, 1});
        } else {
            ++it->second;
        }
    }
    
    for (string p: participant) {
        auto it = m.find(p);
        
        if (it == m.end()) {
            return p;
        }
        
        if (it != m.end()) {
            if (--it->second < 0) {
                return p;
            }
        }
    }
}