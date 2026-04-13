#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> m;
    
    for (vector<string>& cloth: clothes) {
        auto it = m.find(cloth[1]);
        
        if (it == m.end()) {
            m.insert({cloth[1], 1});
        } else {
            ++it->second;
        }
    }
    
    int combination = 1;
    for (auto it: m) {
        combination *= it.second + 1;
    }
    
    return combination - 1;
}